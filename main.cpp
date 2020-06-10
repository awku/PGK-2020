#include <wx/wx.h>
#include "GUIFrame.h"

class MyApp : public wxApp {

public:

    virtual bool OnInit();
    virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    wxFrame* mainFrame = new GUIFrame(NULL);
    mainFrame->Show(true);
    SetTopWindow(mainFrame);
    return true;
}