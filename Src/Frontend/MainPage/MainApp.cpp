#include "MainApp.h"
#include <chrono>
#include <thread>

bool MainApp::OnInit() {
    DataParser dataParser;
    mainWindow = new MainWindow(nullptr, wxID_ANY, "SatInfo v0.1", dataParser, wxDefaultPosition,
        wxWindow::FromDIP(wxSize(1000, 800), NULL));
    mainWindow->Show(true);

    // TEST
    // dataParser.parseBoxCat();
    // curl_manager curlManager;
    // curlManager.download_data(curl_manager::download_type::CURRENT_DATA);

    // END TEST

    return true;
}

int MainApp::OnExit() {
    std::cout << "END APP\n";
    return 0;
}