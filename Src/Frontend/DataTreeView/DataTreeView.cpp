#include "DataTreeView.h"

void DataTreeView::setDataTreeViewCtrl(wxWindow *parent) {
    std::cout << "TREE VIEEEEEEWWWW\n";
    dataTreeViewCtrl = new wxTreeListCtrl(parent, wxID_ANY, wxDefaultPosition,
        parent->FromDIP(wxSize(190, 90)), wxNO_BORDER | wxTE_MULTILINE);

    // This data tree always have the same two columns
    dataTreeViewCtrl.get()->AppendColumn("Component");
    dataTreeViewCtrl.get()->AppendColumn("Elements");

    dataTreeViewCtrl.get()->SetColumnWidth(0, 100);
    dataTreeViewCtrl.get()->SetColumnWidth(1, 90);

    wxTreeListItem root = dataTreeViewCtrl.get()->GetRootItem();

    // Bind contextual menu event
    parent->Bind(
        wxEVT_TREELIST_ITEM_CONTEXT_MENU, &DataTreeView::OnItemContextMenu, this, wxID_ANY);
}

void DataTreeView::addBoxCatData(std::string _name, int _elements) {
    wxTreeListItem root = dataTreeViewCtrl.get()->GetRootItem();
    wxTreeListItem item = dataTreeViewCtrl.get()->AppendItem(root, _name);
    dataTreeViewCtrl.get()->SetItemText(item, 1, std::to_string(_elements));
}

void DataTreeView::OnItemContextMenu(wxTreeListEvent &event) {
    // TEST

    enum { Id_Check_Item, Id_Uncheck_Item, Id_Indet_Item, Id_Check_Recursively, Id_Update_Parent };

    wxMenu menu;
    menu.Append(Id_Check_Item, "&Check item");
    menu.Append(Id_Uncheck_Item, "&Uncheck item");
    if(dataTreeViewCtrl.get()->HasFlag(wxTL_3STATE))
        menu.Append(Id_Indet_Item, "Make item &indeterminate");
    menu.AppendSeparator();
    menu.Append(Id_Check_Recursively, "Check &recursively");
    menu.Append(Id_Update_Parent, "Update &parent");

    const wxTreeListItem item = event.GetItem();
    switch(dataTreeViewCtrl.get()->GetPopupMenuSelectionFromUser(menu)) {
        case Id_Check_Item:
            std::cout << "hey\n";
            break;

        case Id_Uncheck_Item:
            std::cout << "hey1\n";
            break;

        case Id_Indet_Item:
            std::cout << "hey2\n";
            break;

        case Id_Check_Recursively:
            std::cout << "he3\n";
            break;

        case Id_Update_Parent:
            std::cout << "hey4\n";
            break;

        default:
            wxFAIL_MSG("Unexpected menu selection");
            wxFALLTHROUGH;

        case wxID_NONE:
            return;
    }
}