#pragma once
#include "Backend.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/treelist.h>
#include <wx/window.h>

#define wxHAS_EVENT_BIND

class DataTreeView {
public:
    void setDataTreeViewCtrl(wxWindow *parent);
    wxSharedPtr<wxTreeListCtrl> getDataTreeViewCtrl() { return dataTreeViewCtrl; }

    // Add boxCat data
    void addBoxCatData(std::string _name, int _elements);

private:
    wxSharedPtr<wxTreeListCtrl> dataTreeViewCtrl;

    void OnItemContextMenu(wxTreeListEvent &event);
};