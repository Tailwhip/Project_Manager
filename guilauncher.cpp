#include "guilauncher.h"

wxIMPLEMENT_APP(guiLauncher);

guiLauncher::guiLauncher()
{

}

guiLauncher::~guiLauncher()
{

}

bool guiLauncher::OnInit()
{
    mainFrame = new guiMain();
    mainFrame->Show();

    return true;
};
