#pragma once
#include "Backend.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/window.h>
#include "wx/dialog.h"

class DownloadPage {
public:
    DownloadPage (wxWindow *parent);

private:
    wxDialog *downloadDialog;

    std::unique_ptr<curl_manager> curlManager;

    void OnOKButton(wxCommandEvent& event);

};