#pragma once
#include "Backend.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/treelist.h>
#include <wx/window.h>

enum TreeViewExpandedComparatorCol { Col_Name = 0, Col_Elements };

class ExpandedComparator : public wxTreeListItemComparator {
public:
    virtual int Compare(wxTreeListCtrl *treeList, unsigned int column, wxTreeListItem item_1,
        wxTreeListItem item_2) wxOVERRIDE {
        wxString item_1_text = treeList->GetItemText(item_1, column);
        wxString item_2_text = treeList->GetItemText(item_2, column);

        switch(column) {
            case Col_Name:
                return item_1_text.CmpNoCase(item_2_text);

            case Col_Elements: {
                unsigned long value_1;
                unsigned long value_2;
                item_1_text.ToULong(&value_1);
                item_2_text.ToULong(&value_2);
                return (value_1 - value_2);
            }
        }

        return 0;
    }
};

class DataTreeView {
public:
    void setDataTreeViewCtrl(wxWindow *parent, DataParser *_dataParser);
    wxSharedPtr<wxTreeListCtrl> getDataTreeViewCtrl() { return dataTreeViewCtrl; }

    // Add boxCat data
    void addBoxCatData(std::string _name, int _elements);

private:
    wxSharedPtr<wxTreeListCtrl> dataTreeViewCtrl;
    DataParser *dataParser;

    ExpandedComparator expandedComparator;

    void OnItemContextMenu(wxTreeListEvent &event);
    void OnSelectionChanged(wxTreeListEvent &event);

    std::string dataSelectedName;
};