#include "guinewproject.h"

wxBEGIN_EVENT_TABLE(guiNewProject, wxFrame)
    EVT_BUTTON(backBtnID, OnBackBtnClicked)
    EVT_BUTTON(createBtnID, OnCreateBtnClicked)
    EVT_CLOSE(guiNewProject::OnClose)
wxEND_EVENT_TABLE()

guiNewProject::guiNewProject(wxFrame* backFrame) : wxFrame(nullptr, wxID_ANY, "New Project") {
    this->backFrame = backFrame;
    // set position
    newProjFramePosX = 300;
    newProjFramePosY = 300;
    newProjFramePos = wxPoint(newProjFramePosX, newProjFramePosY);
    this->SetPosition(newProjFramePos);
    // set size
    newProjWidth = 512;
    newProjHeight = 512;
    this->SetSize(newProjWidth, newProjHeight);
    // set new project panel
    newProjPanel = new wxPanel(this, wxID_ANY);
    // set back button
    backBtnWidth = newProjWidth / 4;
    backBtnHeight = newProjHeight / 12;
    backBtnSize = wxSize(backBtnWidth, backBtnHeight);
    backBtnPosX = 0.1 * newProjWidth;
    backBtnPosY = 0.8 * newProjHeight;
    backBtnPosition = wxPoint(backBtnPosX, backBtnPosY);
    backBtn = new wxButton(newProjPanel, backBtnID, "Back", backBtnPosition, backBtnSize);
    // set create button
    createBtnWidth = backBtnWidth;
    createBtnHeight = backBtnHeight;
    createBtnSize = wxSize(createBtnWidth, createBtnHeight);
    createBtnPosX = 0.62 * newProjWidth;
    createBtnPosY = 0.8 * newProjHeight;
    createBtnPosition = wxPoint(createBtnPosX, createBtnPosY);
    createBtn = new wxButton(newProjPanel, createBtnID, "Create", createBtnPosition, createBtnSize);
    // set project name textboxes and labels for texboxes
    newProjTxtWidth = backBtnWidth;
    newProjTxtHeight = 20;
    newProjTxtSize = wxSize(newProjTxtWidth, newProjTxtHeight);
    newProjTxtPosX = 0.25 * newProjWidth;
    //newProjTxtPosY = 0.2 * newProjHeight;
    newProjTxtPosition = wxPoint(newProjTxtPosX, newProjTxtPosY);
    // labels
    newProjLabelsPosX = 0.05 * newProjWidth;
    newProjLabelsWidth = 100;
    newProjLabelsHeight = newProjTxtHeight;
    newProjLabelsSize = wxSize(newProjLabelsWidth, newProjLabelsHeight);
    labelsTxt = std::vector<char*>{"Project name", "Project Number", "Project Path"};

    for (unsigned i = 0; i < txtCtrlCount; i++) {
        newProjTxtPosY = (0.1 * newProjHeight) + i * (0.1 * newProjHeight);
        newProjTxtPosition = wxPoint(newProjTxtPosX, newProjTxtPosY);
        textControls.push_back(new wxTextCtrl(newProjPanel, projNameTxtIDbegin + i, "",
                                              newProjTxtPosition, newProjTxtSize));
        newProjLabelsPosition = wxPoint(newProjLabelsPosX , newProjTxtPosY);
        textLabels.push_back(new wxStaticText(newProjPanel, projNameLabelsIDbegin + i,
                                              labelsTxt.at(i),  newProjLabelsPosition, newProjLabelsSize));
    }
}

/* // MessageBox pattern
    wxString message;
    message.Printf(wxT("Liczba:  "));
    wxMessageBox(message);
*/

guiNewProject::~guiNewProject() {

}

void guiNewProject::OnBackBtnClicked(wxCommandEvent &evt) {
    this->backFrame->Show(true);
    this->Show(false);
    //m_list1->AppendString(m_txt1->GetValue());
    evt.Skip();
}

void guiNewProject::OnCreateBtnClicked(wxCommandEvent &evt) {

    DbManager::getInstance().createDb();

    std::map<std::string, std::string> newProjData;
    newProjData[DbManager::getInstance().getProjIdHead()] = "NULL";
    newProjData[DbManager::getInstance().getProjNameHead()] = (textControls.at(0)->GetValue()).mb_str();
    newProjData[DbManager::getInstance().getProjNumberHead()] = (textControls.at(1)->GetValue()).mb_str();
    newProjData[DbManager::getInstance().getProjPathHead()] = (textControls.at(2)->GetValue()).mb_str();

    DbManager::getInstance().addProj(newProjData);

    std::map<std::string, std::string> docData;
    docData[DbManager::getInstance().getApprDocNumHead()] = "";
    docData[DbManager::getInstance().getDocApprDateHead()] = "";
    docData[DbManager::getInstance().getDocExtHead()] = ".xlsm";
    docData[DbManager::getInstance().getDocIdHead()] = "NULL";
    docData[DbManager::getInstance().getDocMadeDateHead()] = "";
    docData[DbManager::getInstance().getDocNameHead()] = "Lista dokumentów";
    docData[DbManager::getInstance().getDocPathHead()] = newProjData[DbManager::getInstance().getProjPathHead()];
    docData[DbManager::getInstance().getDocReviewDateHead()] = "";
    docData[DbManager::getInstance().getDocRevHead()] = "000";
    docData[DbManager::getInstance().getProjNumberHead()] =  newProjData[DbManager::getInstance().getProjNumberHead()];

    DbManager::getInstance().addDoc(docData);
    DbManager::getInstance().openDb();

    DocsGenerator docGenerator;

    GenDocList docList(docData);
    docGenerator.generateDoc();
/*
    std::auto_ptr<Document> document = docGenerator.getDocument();
    document->createDocument();
*/
}

void guiNewProject::OnClose(wxCloseEvent& evt) {
    this->Close(true);
    this->backFrame->Close(true);
}
