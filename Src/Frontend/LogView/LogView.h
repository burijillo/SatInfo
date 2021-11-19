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

   void Update (const std::string& messageFromLogger, LOG_TYPE logType) override;
   void RemoveLogViewFromLogger ();
   void PrintInfo ();

   wxSharedPtr<wxTextCtrl> getLogTextCtrl() { return logTextCtrl; }
   void setLogTextCtrl(wxWindow* parent);

private:
   std::map<LOG_TYPE, std::string> logTypeMap {
      {LOG_TYPE::LOG, "[LOG]"},
      {LOG_TYPE::PARSER, "[PARSER]"},
      {LOG_TYPE::SYS_ERR, "[SYSTEM ERROR]"}
   };
   std::string getTagFromMap(LOG_TYPE logType);
   std::string msgConstructor(std::string msg, LOG_TYPE log_type);

   std::string messageFromLogger_;
   LOG_TYPE logTypeFromLogger_;

   wxSharedPtr<wxTextCtrl> logTextCtrl;
};