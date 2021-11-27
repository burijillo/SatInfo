#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "../LogView/LogView.h"
#include "Backend.h"
#include "wx/artprov.h"
#include "wx/aui/aui.h"
#include "wx/frame.h"

class MainWindow : public wxFrame {
public:
    MainWindow(wxWindow *parent, wxWindowID id, const wxString &title, DataParser _dataParser,
        const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize,
        long style = wxDEFAULT_FRAME_STYLE | wxSUNKEN_BORDER);

private:
    wxAuiManager m_mgr;
    long         m_notebook_style;
    long         m_notebook_theme;

    DataParser dataParser;

    const static int BOXDATA_ID = 5500;

    wxSharedPtr<LogView> log_view;

    void OnBoxDataLoad(wxCommandEvent &event);

    void OnShowLog(wxCommandEvent &event);

    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnPaneClose(wxAuiManagerEvent &event);

    wxDECLARE_EVENT_TABLE();
};