#include "DataTreeView.h"

void DataTreeView::setDataTreeViewCtrl(wxWindow *parent) {
    std::cout << "TREE VIEEEEEEWWWW\n";
    dataTreeViewCtrl = new wxTreeListCtrl(parent, wxID_ANY, wxDefaultPosition,
        parent->FromDIP(wxSize(190, 90)), wxNO_BORDER | wxTE_MULTILINE);

    // This data tree always have the same two columns
    dataTreeViewCtrl.get()->AppendColumn("Component");
    dataTreeViewCtrl.get()->AppendColumn("Elements");

    wxTreeListItem root   = dataTreeViewCtrl.get()->GetRootItem();
    wxTreeListItem item   = dataTreeViewCtrl.get()->AppendItem(root, "roootin");
    wxTreeListItem item_0 = dataTreeViewCtrl.get()->AppendItem(root, "testinn");
}

void DataTreeView::addBoxCatData(std::string _name) {
    wxTreeListItem root = dataTreeViewCtrl.get()->GetRootItem();
    wxTreeListItem item = dataTreeViewCtrl.get()->AppendItem(root, _name);
    dataTreeViewCtrl.get()->SetItemText(item, 1, "290");
}