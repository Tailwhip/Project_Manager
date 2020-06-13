#include "guimain.h"

wxBEGIN_EVENT_TABLE(guiMain, wxFrame)
    EVT_BUTTON(10000, OnButtonClicked)
    EVT_CLOSE(guiMain::OnClose)
wxEND_EVENT_TABLE()

guiMain::GuiMain() : wxFrame(nullptr, wxID_ANY, "Project Manager") {
    // set frame position
    mainFramePosX = 300;
    mainFramePosY = 300;
    mainFramePos = wxPoint(mainFramePosX, mainFramePosY);
    this->SetPosition(mainFramePos);
    // set frame size
    mainFrameWidth = 512;
    mainFrameHeight = 512;
    this->SetSize(mainFrameWidth, mainFrameHeight);
    // set panel
    mainPanel = new wxPanel(this, wxID_ANY);
    // set new project button size
    newProjBtnWidth = mainFrameWidth / 4;
    newProjBtnHeight = mainFrameHeight / 12;
    newProjBtnSize = wxSize(newProjBtnWidth, newProjBtnHeight);
    // set new project button position
    newProjBtnPosX = (mainFrameWidth / 2) - (newProjBtnWidth / 2);
    newProjBtnPosY = (mainFrameHeight / 4) - (newProjBtnHeight / 2);
    newProjBtnPos = wxPoint(newProjBtnPosX, newProjBtnPosY);

    newProjBtn = new wxButton(mainPanel, 10000, "New project", newProjBtnPos, newProjBtnSize);
}

GuiMain::~GuiMain() {

}

int GuiMain::getFrameWidth() {
    return mainFrameWidth;
}

int GuiMain::getFrameHeight() {
    return mainFrameHeight;
}

void GuiMain::OnButtonClicked(wxCommandEvent &evt) {
    newProjFrame = new guiNewProject(this);
    newProjFrame->Show();
    this->Show(false);
    //m_list1->AppendString(m_txt1->GetValue());
    evt.Skip();
}

void GuiMain::OnClose(wxCloseEvent& evt) {
    if (!(newProjFrame = nullptr))
        newProjFrame->Close(true);
    this->Close(true);
}
