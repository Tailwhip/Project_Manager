#ifndef GUINEWPROJECT_H
#define GUINEWPROJECT_H

#include <iostream>
#include <vector>
#include <string>
#include "wx/wx.h"
#include "docsgenerator.h"
#include "gendoclist.h"
#include "dbmanager.h"
#include "pmutilities.h"


class guiNewProject : public wxFrame
{
public:
    // guiNewProject();
    guiNewProject(wxFrame*);
    ~guiNewProject();

private:
    // frame to get back
    wxFrame* backFrame = nullptr;
    // new project frame variables
    int newProjFramePosX = 0;
    int newProjFramePosY = 0;
    wxPoint newProjFramePos;
    int newProjWidth = 10;
    int newProjHeight = 10;
    // new project panel
    wxPanel *newProjPanel = nullptr;
    // back button variables
    static int const backBtnID = 20000;
    int backBtnWidth = 0;
    int backBtnHeight = 0;
    wxSize backBtnSize;
    int backBtnPosX = 0;
    int backBtnPosY = 0;
    wxPoint backBtnPosition;
    wxButton *backBtn = nullptr;
    // create button variables
    static int const  createBtnID = 20001;
    int createBtnWidth = 0;
    int createBtnHeight = 0;
    wxSize createBtnSize;
    int createBtnPosX = 0;
    int createBtnPosY = 0;
    wxPoint createBtnPosition;
    wxButton *createBtn = nullptr;
    // new project text boxes variables
    int newProjTxtWidth = 0;
    int newProjTxtHeight = 0;
    wxSize newProjTxtSize;
    int newProjTxtPosX = 0;
    int newProjTxtPosY = 0;
    wxPoint newProjTxtPosition;
    unsigned const txtCtrlCount = 3;
    int const projNameTxtIDbegin = 20002;
    std::vector<wxTextCtrl*> textControls;
    // new project labels variables
    int newProjLabelsWidth = 0;
    int newProjLabelsHeight = 0;
    wxSize newProjLabelsSize;
    int newProjLabelsPosX = 0;
    int newProjLabelsPosY = 0;
    wxPoint newProjLabelsPosition;
    //unsigned labelsCount = txtCtrlCount;
    int const projNameLabelsIDbegin = projNameTxtIDbegin + txtCtrlCount;
    std::vector<wxStaticText*> textLabels;
    std::vector<char*> labelsTxt;

    // std::string const char*
    // gui objects functions
    void OnClose(wxCloseEvent& evt);
    void OnBackBtnClicked(wxCommandEvent &evt);
    void OnCreateBtnClicked(wxCommandEvent &evt);

    wxDECLARE_EVENT_TABLE();
};

#endif // GUINEWPROJECT_H




