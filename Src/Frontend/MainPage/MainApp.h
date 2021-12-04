#include "Backend.h"
#include "MainWindow.h"

class MainApp : public wxApp {
public:
    virtual bool OnInit();
    virtual int  OnExit();

private:
    wxFrame* mainWindow;
};
