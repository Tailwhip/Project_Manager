#ifndef GUIMAIN_H
#define GUIMAIN_H

#include <iostream>
#include "wx/wx.h"
#include "guinewproject.h"

/// Class for creating the main menu frame.
class GuiMain : public wxFrame
{
public:
    /// Constructor.
    GuiMain();
    /// Destructor.
    ~GuiMain();
    /// Gets main menu frame width.
    ///
    /// @see mainFrameWidth
    int getFrameWidth();
    /// Gets main menu frame height.
    ///
    /// @see mainFrameHeight
    int getFrameHeight();

private:
    // main frame position
    /// Main menu frame position in the x coordinate.
    int mainFramePosX;
    /// Main menu frame position in the y coordinate.
    int mainFramePosY;
    /// Main menu frame position object.
    wxPoint mainFramePos;
    // main frame size
    /// Main menu frame width.
    int mainFrameWidth;
    /// Main menu frame height.
    int mainFrameHeight;
    // main panel
    /// Main menu Panel object.
    wxPanel *mainPanel = nullptr;
    // new project button variables
    /// New project button position in the x coordinate.
    int newProjBtnPosX = 0;
    /// New project button position in the y coordinate.
    int newProjBtnPosY = 0;
    /// New project button position object.
    wxPoint newProjBtnPos;
    /// New project button width.
    int newProjBtnWidth = 0;
    /// New project button height.
    int newProjBtnHeight = 0;
    /// New project button size object.
    wxSize newProjBtnSize;
    /// New project Button object.
    wxButton *newProjBtn = nullptr;
    /// New project Frame object.
    guiNewProject* newProjFrame = nullptr;
    /// Things that are happening during main menu frame close.
    ///
    /// It closes also the New project frame if it's opened.
    void OnClose(wxCloseEvent& evt);
    /// Things that are happening after clicking buttons.
    ///
    /// On New project button clicked the New project Frame appears
    /// and Main menu frame disappears.
    void OnButtonClicked(wxCommandEvent &evt);
    /// Macro consisting of static event handlers for the Main menu frame.
    wxDECLARE_EVENT_TABLE();
};

#endif // GUIMAIN_H




