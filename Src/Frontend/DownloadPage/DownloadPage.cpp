#include "DownloadPage.h"

DownloadPage::DownloadPage(wxWindow *parent) {
    // TEST
    downloadDialog = new wxDialog(parent, wxID_ANY, "HEEEEY", wxDefaultPosition, wxWindow::FromDIP(wxSize(800, 500), NULL));

    wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);
    // create text ctrl with minimal size 100x60
    databaseArray.Add("BoxCat");
    databaseArray.Add("SatCat");
    databaseSelector = new wxComboBox(downloadDialog, wxID_ABOUT, "Database type", wxDefaultPosition, wxSize(100, 40), databaseArray);
    parameterSelector = new wxComboBox(downloadDialog,wxID_PREVIEW, "Database parameters", wxDefaultPosition, wxSize(100, 40), parameterArray);
    topsizer->Add(databaseSelector, 1, wxEXPAND, 10);
    topsizer->Add(parameterSelector, 1, wxEXPAND, 10);
    OKButton = new wxButton(downloadDialog, wxID_OK, "OK");
    wxBoxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
    button_sizer->Add(OKButton,
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

    OKButton->Disable();

    // Bind events
    downloadDialog->Bind(wxEVT_BUTTON, &DownloadPage::OnOKButton, this, wxID_OK);
    downloadDialog->Bind(wxEVT_COMBOBOX, &DownloadPage::OnSelectionChange, this, wxID_ABOUT);

    downloadDialog->ShowModal();
}

void DownloadPage::OnOKButton(wxCommandEvent& event) {
    std::cout << "aloha\n";
    curlManager = std::make_unique<curl_manager>();
    curlManager.get()->download_data(category);
    std::cout << "alochao\n";
    downloadDialog->Close();
}

void DownloadPage::OnSelectionChange(wxCommandEvent& event) {
    // Check on string selected
    std::string selection = event.GetString().ToStdString();
    if (CheckSelection(selection)) {
        OKButton->Enable();
        parameterArray.clear();

        if (selection == databaseArray[0]) {
            category = curl_manager::download_type::BOX_CAT;
            
            for (int i = 0; i < boxCatPropSize; i++) {
                parameterArray.Add(boxCatProp[i]);
            }
            FillParameterArray();
        } else if (selection == databaseArray[1]) {
            category = curl_manager::download_type::SAT_CAT;
            FillParameterArray();
        }
    } else {
        OKButton->Disable();
    }
}

bool DownloadPage::CheckSelection(std::string selection) {
    bool result = false;

    for (auto item : databaseArray) {
        if (item == selection){
            return true;
        }
    }

    return result;
}

void DownloadPage::FillParameterArray() {
    parameterSelector->Set(parameterArray);
    parameterSelector->Update();
}