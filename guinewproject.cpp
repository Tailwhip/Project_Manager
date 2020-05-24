#include "guinewproject.h"

wxBEGIN_EVENT_TABLE(guiNewProject, wxFrame)
    EVT_BUTTON(backBtnID, OnBackBtnClicked)
    EVT_BUTTON(createBtnID, OnCreateBtnClicked)
    EVT_BUTTON(choosePathBtnID, OnChoosePath)
    EVT_CLOSE(guiNewProject::OnClose)
wxEND_EVENT_TABLE()

guiNewProject::guiNewProject(wxFrame* backFrame) : wxFrame(nullptr, wxID_ANY, "New Project") {
    this->backFrame = backFrame;
    // set 'new project' panel

    newProjFramePosX = 300;
    newProjFramePosY = 300;
    newProjFramePos = wxPoint(newProjFramePosX, newProjFramePosY);
    this->SetPosition(newProjFramePos);

    newProjWidth = 512;
    newProjHeight = 512;
    this->SetSize(newProjWidth, newProjHeight);

    newProjPanel = new wxPanel(this, wxID_ANY);
    // set button 'Back'
    backBtnWidth = newProjWidth / 4;
    backBtnHeight = newProjHeight / 12;
    backBtnSize = wxSize(backBtnWidth, backBtnHeight);
    backBtnPosX = 0.1 * newProjWidth;
    backBtnPosY = 0.8 * newProjHeight;
    backBtnPosition = wxPoint(backBtnPosX, backBtnPosY);
    backBtn = new wxButton(newProjPanel, backBtnID, "Back", backBtnPosition, backBtnSize);
    // set button 'Create'
    createBtnWidth = backBtnWidth;
    createBtnHeight = backBtnHeight;
    createBtnSize = wxSize(createBtnWidth, createBtnHeight);
    createBtnPosX = 0.62 * newProjWidth;
    createBtnPosY = 0.8 * newProjHeight;
    createBtnPosition = wxPoint(createBtnPosX, createBtnPosY);
    createBtn = new wxButton(newProjPanel, createBtnID, "Create", createBtnPosition, createBtnSize);
    // set textboxes
    newProjTxtWidth = backBtnWidth;
    newProjTxtHeight = 20;
    newProjTxtSize = wxSize(newProjTxtWidth, newProjTxtHeight);
    newProjTxtPosX = 0.25 * newProjWidth;
    //newProjTxtPosY = 0.2 * newProjHeight;
    newProjTxtPosition = wxPoint(newProjTxtPosX, newProjTxtPosY);
    // set labels for texboxes
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
                                              labelsTxt.at(i),  newProjLabelsPosition,
                                              newProjLabelsSize));
    }

    // set button 'Choose path'
    choosePathBtnWidth = backBtnWidth * 0.8;
    choosePathBtnHeight = newProjTxtHeight;
    choosePathBtnSize = wxSize(choosePathBtnWidth, choosePathBtnHeight);
    choosePathBtnPosX = newProjTxtPosX + newProjTxtWidth + 20;
    choosePathBtnPosY = newProjTxtPosY;
    choosePathBtnPosition = wxPoint(choosePathBtnPosX, choosePathBtnPosY);
    choosePathBtn = new wxButton(newProjPanel,
                                 choosePathBtnID,
                                 "Choose path",
                                 choosePathBtnPosition,
                                 choosePathBtnSize);
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
    ///TODO: Check if all textboxes are filled before creating the new project
    DbManager::getInstance().createDb();

    std::map<std::string, std::string> newProjData;
    newProjData[DbManager::getInstance().getProjIdHead()] = "NULL";
    newProjData[DbManager::getInstance().getProjNameHead()] =
        (textControls.at(0)->GetValue()).mb_str();
    newProjData[DbManager::getInstance().getProjNumberHead()] =
        (textControls.at(1)->GetValue()).mb_str();
    newProjData[DbManager::getInstance().getProjPathHead()] =
        (textControls.at(2)->GetValue()).mb_str();

    DbManager::getInstance().addProj(newProjData);

    // Get current system time
	boost::posix_time::ptime timeLocal = boost::posix_time::second_clock::local_time();

    std::map<std::string, std::string> docData;
    docData[DbManager::getInstance().getDocNumHead()] =
        newProjData[DbManager::getInstance().getProjNumberHead()] + "-00"; ///TODO: Add the document's files structure level
    docData[DbManager::getInstance().getApprDocNumHead()] = "<Approving Document Number>"; ///TODO: Add the approving doc number
    docData[DbManager::getInstance().getDocApprDateHead()] =
        to_iso_extended_string(timeLocal.date());
    docData[DbManager::getInstance().getDocExtHead()] = ".xlsm";
    docData[DbManager::getInstance().getDocIdHead()] = "NULL";
    docData[DbManager::getInstance().getDocMadeDateHead()] =
        to_iso_extended_string(timeLocal.date());
    docData[DbManager::getInstance().getDocNameHead()] = "Lista_dokumentow";
    docData[DbManager::getInstance().getDocPathHead()] =
        newProjData[DbManager::getInstance().getProjPathHead()] + "/"
        + newProjData[DbManager::getInstance().getProjNumberHead()] + "-"
        + docData[DbManager::getInstance().getDocNameHead()]
        + docData[DbManager::getInstance().getDocExtHead()];
    docData[DbManager::getInstance().getDocReviewDateHead()] =
        to_iso_extended_string(timeLocal.date());
    docData[DbManager::getInstance().getDocRevHead()] = "000";
    docData[DbManager::getInstance().getProjNumberHead()] =
        newProjData[DbManager::getInstance().getProjNumberHead()];

    //DbManager::getInstance().addDoc(docData);
    DbManager::getInstance().openDb();

    DocsGenerator docGenerator;

    GenDocList docList(docData);
    docGenerator.setDocumenter(&docList);
    docGenerator.generateDoc();
    /*
    std::auto_ptr<Document> document = docGenerator.getDocument();
    document->createDocument();
    */
}

void guiNewProject::OnChoosePath(wxCommandEvent &evt) {

    wxDirDialog* dirDialog = new wxDirDialog(this);

    if (dirDialog->ShowModal() == wxID_OK) {
        wxString selectedFile = dirDialog->GetPath();
        textControls.at(2)->SetValue(selectedFile);
    }

    dirDialog->Destroy();
}

void guiNewProject::OnClose(wxCloseEvent& evt) {
    this->Close(true);
    this->backFrame->Close(true);
}
