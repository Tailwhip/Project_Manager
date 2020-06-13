#include <iostream>
#include "wx/wx.h"
#include "guimain.h"

#ifndef GUILAUNCHER_H
#define GUILAUNCHER_H
/// Class using only to launch the main menu frame of the application.
class GuiLauncher : public wxApp
{
public:
    /// Constructor.
    GuiLauncher();
    /// Destructor.
    ~GuiLauncher();
private:
    /// Main frame object.
    GuiMain* mainFrame = nullptr;

public:
    /// Function initialising the main frame of the application.
    virtual bool OnInit();
};

#endif // GUILAUNCHER_H




