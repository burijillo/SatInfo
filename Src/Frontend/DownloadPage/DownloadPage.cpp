#include "DownloadPage.h"

DownloadPage::DownloadPage(wxWindow *parent) {
    // TEST
    downloadDialog = new wxDialog(parent, wxID_ANY, "HEEEEY", wxDefaultPosition, wxWindow::FromDIP(wxSize(800, 500), NULL));

    wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);
    // create text ctrl with minimal size 100x60
    wxArrayString databaseArray;
    databaseArray.Add("BoxCat");
    databaseArray.Add("SatCat");
    wxComboBox *databaseSelector = new wxComboBox(downloadDialog, wxID_ANY, "Database type", wxDefaultPosition, wxSize(100, 40), databaseArray);
    topsizer->Add(databaseSelector, 1, wxEXPAND, 10);
    /*topsizer->Add(new wxTextCtrl(downloadDialog, -1, "My text.", wxDefaultPosition,
                      wxSize(100, 60), wxTE_MULTILINE),
        1,         // make vertically stretchable
        wxEXPAND | // make horizontally stretchable
            wxALL, //   and make border all around
        10);       // set border width to 10*/
    wxBoxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
    button_sizer->Add(new wxButton(downloadDialog, wxID_OK, "OK"),
        0,     // make horizontally unstretchable
        wxALL, // make border all around (implicit top alignment)
        10);   // set border width to 10
    button_sizer->Add(new wxButton(downloadDialog, wxID_CANCEL, "Cancel"),
        0,     // make horizontally unstretchable
        wxALL, // make border all around (implicit top alignment)
        10);   // set border width to 10
    topsizer->Add(button_sizer,
        0,                                            // make vertically unstretchable
        wxALIGN_CENTER);                              // no border and centre horizontally
    downloadDialog->SetSizerAndFit(topsizer);

    // Bind events
    downloadDialog->Bind(wxEVT_BUTTON, &DownloadPage::OnOKButton, this, wxID_OK);

    downloadDialog->ShowModal();
}

void DownloadPage::OnOKButton(wxCommandEvent& event) {
    std::cout << "aloha\n";
    curlManager = std::make_unique<curl_manager>();
    curlManager.get()->download_data(curl_manager::download_type::CURRENT_DATA);
    std::cout << "alochao\n";
    downloadDialog->Close();
}