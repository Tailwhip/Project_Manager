#include "guilauncher.h"

wxIMPLEMENT_APP(GuiLauncher);

GuiLauncher::GuiLauncher()
{

}

GuiLauncher::~GuiLauncher()
{

}

bool GuiLauncher::OnInit()
{
    mainFrame = new GuiMain();
    mainFrame->Show();

    return true;
};
