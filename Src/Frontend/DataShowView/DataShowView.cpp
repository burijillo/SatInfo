#include "DataShowView.h"

void DataShowView::setDataShowViewCtrl(wxWindow *parent, DataParser *_dataParser) {
    dataShowViewCtrl = new wxPanel(
        parent, wxID_ANY, wxDefaultPosition, parent->FromDIP(wxSize(220, 90)), wxNO_BORDER);

    // TEST

    wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);
    // create text ctrl with minimal size 100x60
    topsizer->Add(new wxTextCtrl(dataShowViewCtrl.get(), -1, "My text.", wxDefaultPosition,
                      wxSize(100, 60), wxTE_MULTILINE),
        1,         // make vertically stretchable
        wxEXPAND | // make horizontally stretchable
            wxALL, //   and make border all around
        10);       // set border width to 10
    wxBoxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
    button_sizer->Add(new wxButton(dataShowViewCtrl.get(), wxID_OK, "OK"),
        0,     // make horizontally unstretchable
        wxALL, // make border all around (implicit top alignment)
        10);   // set border width to 10
    button_sizer->Add(new wxButton(dataShowViewCtrl.get(), wxID_CANCEL, "Cancel"),
        0,     // make horizontally unstretchable
        wxALL, // make border all around (implicit top alignment)
        10);   // set border width to 10
    topsizer->Add(button_sizer,
        0,                                            // make vertically unstretchable
        wxALIGN_CENTER);                              // no border and centre horizontally
    dataShowViewCtrl.get()->SetSizerAndFit(topsizer); // use the sizer for layout and size window
                                                      // accordingly and prevent it from being
                                                      // resized to smaller size
}