#ifndef GUIMAIN_H
#define GUIMAIN_H

#include <iostream>
#include "wx/wx.h"
#include "guinewproject.h"


class guiMain : public wxFrame
{
public:
    guiMain();
    ~guiMain();

    int getFrameWidth();
    int getFrameHeight();

private:
    // main frame position
    int mainFramePosX;
    int mainFramePosY;
    wxPoint mainFramePos;
    // main frame size
    int mainFrameWidth;
    int mainFrameHeight;
    // main panel
    wxPanel *mainPanel = nullptr;
    // new project button variables
    int newProjBtnPosX = 0;
    int newProjBtnPosY = 0;
    wxPoint newProjBtnPos;
    int newProjBtnWidth = 0;
    int newProjBtnHeight = 0;
    wxSize newProjBtnSize;
    wxButton *newProjBtn = nullptr;

    guiNewProject* newProjFrame = nullptr;



    void OnClose(wxCloseEvent& evt);
    void OnButtonClicked(wxCommandEvent &evt);

    wxDECLARE_EVENT_TABLE();
};

#endif // GUIMAIN_H




