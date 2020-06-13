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
#include <boost/date_time.hpp>

/* // MessageBox pattern
    wxString message;
    message.Printf(wxT("Liczba:  "));
    wxMessageBox(message);
*/

/// Class for creating a new project frame.
class GuiNewProject : public wxFrame
{
public:
    // GuiNewProject();
    /// Constructor.
    ///
    /// @param backFrame Frame object for the *Back* button.
    GuiNewProject(wxFrame* backFrame);
    /// Destructor.
    ~GuiNewProject();

private:
    /// Frame to get back from the New Project Frame.
    wxFrame* backFrame = nullptr;
    // new project frame variables
    /// New project frame position in the x coordinate.
    int newProjFramePosX = 0;
    /// New project frame position in the y coordinate.
    int newProjFramePosY = 0;
    /// New project frame position object.
    wxPoint newProjFramePos;
    /// New project frame width.
    int newProjWidth = 10;
    /// New project frame height.
    int newProjHeight = 10;
    /// New project panel object.
    wxPanel *newProjPanel = nullptr;
    // button 'Back' variables
    /// Id number of the Back button.
    static int const backBtnID = 10000;
    /// Back button width.
    int backBtnWidth = 0;
    /// Back button height.
    int backBtnHeight = 0;
    /// Back button size object.
    wxSize backBtnSize;
    /// Back button position in the x coordinate.
    int backBtnPosX = 0;
    /// Back button position in the y coordinate.
    int backBtnPosY = 0;
    /// Back button position object.
    wxPoint backBtnPosition;
    /// Back button object.
    wxButton *backBtn = nullptr;
    // button 'Create' variables
    /// Id number of the Create button.
    static int const createBtnID = 10001;
    /// Create button width.
    int createBtnWidth = 0;
    /// Create button height.
    int createBtnHeight = 0;
    /// Create button size object.
    wxSize createBtnSize;
    /// Create button position in the x coordinate.
    int createBtnPosX = 0;
    /// Create button position in the y coordinate.
    int createBtnPosY = 0;
    /// Create button position object.
    wxPoint createBtnPosition;
    /// Create button object.
    wxButton *createBtn = nullptr;
    // button 'Choose path' variables
    /// Id number of the Choose path button.
    static int const choosePathBtnID = 10002;
    /// Choose path button width.
    int choosePathBtnWidth = 0;
    /// Choose path button height.
    int choosePathBtnHeight = 0;
    /// Choose path button size object.
    wxSize choosePathBtnSize;
    /// Choose path button position in the x coordinate.
    int choosePathBtnPosX = 0;
    /// Choose path button position in the y coordinate.
    int choosePathBtnPosY = 0;
    /// Choose path button position object.
    wxPoint choosePathBtnPosition;
    /// Choose path button object.
    wxButton *choosePathBtn = nullptr;
    // new project text boxes variables
    /// New project textbox width.
    int newProjTxtWidth = 0;
    /// New project textbox height.
    int newProjTxtHeight = 0;
    /// New project textbox size object.
    wxSize newProjTxtSize;
    /// New project textbox position in the x coordinate.
    int newProjTxtPosX = 0;
    /// New project textbox position in the y coordinate.
    int newProjTxtPosY = 0;
    /// New project textbox position object.
    wxPoint newProjTxtPosition;
    /// The number of textboxes in the New project frame.
    unsigned const txtCtrlCount = 3;
    /// Id number of the first textbox in the New project frame.
    int const projNameTxtIDbegin = 20000;
    /// Vector of textbox objects in the New project frame.
    std::vector<wxTextCtrl*> textControls;
    // new project labels variables
    /// New project labels width.
    int newProjLabelsWidth = 0;
    /// New project labels height.
    int newProjLabelsHeight = 0;
    /// New project labels size object.
    wxSize newProjLabelsSize;
    /// New project labels position in the x coordinate.
    int newProjLabelsPosX = 0;
    /// New project labels position in the y coordinate.
    int newProjLabelsPosY = 0;
    /// New project labels position object.
    wxPoint newProjLabelsPosition;
    //unsigned labelsCount = txtCtrlCount;
    /// Id number of the first New project label.
    int const projNameLabelsIDbegin = projNameTxtIDbegin + txtCtrlCount;
    /// Vector of label objects in the New project frame.
    std::vector<wxStaticText*> textLabels;
    /// Vector of label texts in the New project frame.
    std::vector<char*> labelsTxt;
    // std::string const char*
    // gui objects functions
    /// Things that are happening after clicking Back button.
    ///
    /// Shows the frame given as a backFrame parameter.
    /// @see backFrame
    void OnBackBtnClicked(wxCommandEvent &evt);
    /// Things that are happening after clicking Create button.
    ///
    /// Creates a new project using given by the user data.
    void OnCreateBtnClicked(wxCommandEvent &evt);
    /// Things that are happening after clicking Choose path button.
    ///
    /// Shows the path choosing dialog.
    void OnChoosePath(wxCommandEvent &evt);
    /// Things that are happening during main menu frame close.
    ///
    /// It closes also the frame given as a backFrame parameter.
    /// @see backFrame
    void OnClose(wxCloseEvent &evt);
    /// Macro consisting of static event handlers for the New project frame.
    wxDECLARE_EVENT_TABLE();
};

#endif // GUINEWPROJECT_H




