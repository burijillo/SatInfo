#include "MainApp.h"

bool MainApp::OnInit()
{
    wxFrame* mainWindow = new MainWindow(nullptr, wxID_ANY, "SatInfo v0.1", wxDefaultPosition, wxWindow::FromDIP(wxSize(1000, 800), NULL));
    mainWindow->Show(true);

    DataParser dataParser;

    // TEST
    curl_manager curlManager;
    curlManager.download_data(curl_manager::download_type::CURRENT_DATA);

    // END TEST
    
    return true;
}