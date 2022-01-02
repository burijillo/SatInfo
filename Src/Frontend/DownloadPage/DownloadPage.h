#pragma once
#include "Backend.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/window.h>
#include "wx/dialog.h"
//#include <span>

class DownloadPage {
public:
    DownloadPage (wxWindow *parent);

private:
    wxDialog *downloadDialog;
    wxComboBox *databaseSelector;
    wxComboBox *parameterSelector;
    wxButton *OKButton;
    wxArrayString databaseArray;
    wxArrayString parameterArray;
    curl_manager::download_type category;

    std::unique_ptr<curl_manager> curlManager;

    void OnOKButton(wxCommandEvent& event);
    void OnSelectionChange(wxCommandEvent& event);

    bool CheckSelection(std::string selection);
    void FillParameterArray();
};