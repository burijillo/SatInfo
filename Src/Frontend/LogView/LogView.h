#pragma once
#include "Backend.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/window.h>

class LogView : public IObserver
{
public:
   LogView ();
   virtual ~LogView ();

   void Update (const std::string& message_from_logger) override;
   void RemoveLogViewFromLogger ();
   void PrintInfo ();

   wxSharedPtr<wxTextCtrl> getLogTextCtrl() { return logTextCtrl; }
   void setLogTextCtrl(wxWindow* parent);

private:
   std::string message_from_logger_;

   wxSharedPtr<wxTextCtrl> logTextCtrl;
};