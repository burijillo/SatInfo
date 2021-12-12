#include "DataShowView.h"

void DataShowView::setDataShowViewCtrl(wxWindow *parent, DataParser *_dataParser) {
    dataShowViewCtrl = new wxPanel(
        parent, wxID_ANY, wxDefaultPosition, parent->FromDIP(wxSize(220, 90)), wxNO_BORDER);

    wxStaticBox *box2      = new wxStaticBox(dataShowViewCtrl.get(), wxID_ANY,
        "&Test data.........................................................:");
    wxSizer *sizerMiddleUp = new wxStaticBoxSizer(box2, wxVERTICAL);
    wxSizer *sizerMiddle   = new wxBoxSizer(wxVERTICAL);
    sizerMiddle->Add(sizerMiddleUp, 0, wxGROW);
    // sizerMiddle->Add(sizerMiddleDown, 1, wxGROW | wxTOP, 5);

    wxStaticBox *box3    = new wxStaticBox(dataShowViewCtrl.get(), wxID_ANY, "&Text:");
    wxSizer *m_sizerText = new wxStaticBoxSizer(box3, wxHORIZONTAL);
    m_sizerText->SetMinSize(150, 0);

    wxSizer *sizerTop = new wxBoxSizer(wxHORIZONTAL);
    sizerTop->Add(sizerMiddle, 0, wxGROW | wxALL, 10);
    sizerTop->Add(m_sizerText, 1, wxGROW | (wxALL & ~wxRIGHT), 10);
    dataShowViewCtrl.get()->SetSizer(sizerTop);
}