#include "mainPage.h"
#include "Backend.h"
#include "../LogView/LogView.h"

bool MyApp::OnInit()
{
    wxFrame *frame = new Frame (NULL, wxID_ANY, "SatInfo v0.1", wxDefaultPosition, wxWindow::FromDIP(wxSize(800, 600), NULL));
    frame->Show(true);


    // TEST
    Logger& logger = Logger::GetLogger();
    LogView* log_view = new LogView();
    logger.CreateMessage("TOMA NENE");

    
    curl_manager curlManager;
    curlManager.download_data(curl_manager::download_type::CURRENT_DATA);

    // END TEST

    delete log_view;
    
    return true;
}