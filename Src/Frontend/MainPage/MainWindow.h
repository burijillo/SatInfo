#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "wx/frame.h"
#include "wx/aui/aui.h"
#include "wx/artprov.h"
#include "Backend.h"
#include "../LogView/LogView.h"

class MainWindow : public wxFrame
{
public:
    MainWindow(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE | wxSUNKEN_BORDER);
private:
    wxAuiManager m_mgr;
    long m_notebook_style;
    long m_notebook_theme;

    wxSharedPtr<LogView> log_view;

    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnPaneClose(wxAuiManagerEvent& event);

    wxDECLARE_EVENT_TABLE();
};