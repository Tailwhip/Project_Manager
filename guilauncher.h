#include <iostream>
#include "wx/wx.h"
#include "guimain.h"

#ifndef GUILAUNCHER_H
#define GUILAUNCHER_H

class guiLauncher : public wxApp
{
public:
    guiLauncher();
    ~guiLauncher();
private:
    guiMain* mainFrame = nullptr;

public:
    virtual bool OnInit();
};

#endif // GUILAUNCHER_H




