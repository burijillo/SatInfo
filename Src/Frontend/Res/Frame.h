#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "wx/frame.h"
#include "wx/aui/aui.h"
#include "wx/artprov.h"
#include "Backend.h"

class Frame : public wxFrame
{
public:
    enum
    {
        ID_Hello = 1
    };
    Frame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE | wxSUNKEN_BORDER);
private:
    wxAuiManager m_mgr;
    long m_notebook_style;
    long m_notebook_theme;

    wxTextCtrl* CreateTextCtrl(const wxString& text = wxEmptyString);

    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};