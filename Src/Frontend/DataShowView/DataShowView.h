#pragma once
#include "Backend.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/window.h>

class DataShowView {
public:
    void setDataShowViewCtrl(wxWindow *parent, DataParser *_dataParser);
    wxSharedPtr<wxPanel> getDataShowViewCtrl() { return dataShowViewCtrl; }

private:
    wxSharedPtr<wxPanel> dataShowViewCtrl;
};