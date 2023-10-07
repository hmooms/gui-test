// helloworld.cpp
#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {}
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame("Hello, wxWidgets!");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);

