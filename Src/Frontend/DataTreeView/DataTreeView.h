#pragma once
#include "Backend.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/treelist.h>
#include <wx/window.h>

class DataTreeView {
public:
    void                        setDataTreeViewCtrl(wxWindow *parent);
    wxSharedPtr<wxTreeListCtrl> getDataTreeViewCtrl() { return dataTreeViewCtrl; }

    // Add boxCat data
    void addBoxCatData(std::string _name);

private:
    wxSharedPtr<wxTreeListCtrl> dataTreeViewCtrl;
};