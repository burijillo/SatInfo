#include "LogView.h"

LogView::LogView ()
{
   Logger& logger_ = Logger::GetLogger ();
   std::cout << "Log view session starts\n";
   logger_.Attach (this);
}

LogView::~LogView ()
{
   std::cout << "Log view session ends\n";
}

void LogView::setLogTextCtrl(wxWindow* parent)
{
   logTextCtrl = new wxTextCtrl(parent, wxID_ANY, "[LOG]: Log initialization\n", wxPoint(0,0), parent->FromDIP(wxSize(150, 90)), wxNO_BORDER | wxTE_MULTILINE);
   logTextCtrl->SetModified(false);
}

void LogView::Update (const std::string& messageFromLogger, LOG_TYPE logTypeFromLogger)
{
   messageFromLogger_ = messageFromLogger;
   logTypeFromLogger_ = logTypeFromLogger;
   PrintInfo ();
}

void LogView::RemoveLogViewFromLogger ()
{
   Logger& logger_ = Logger::GetLogger ();
   logger_.Dettach (this);
   std::cout << "Log view removed from logger\n";
}

void LogView::PrintInfo ()
{
   (*logTextCtrl) << getTagFromMap(logTypeFromLogger_) << " : " << messageFromLogger_ << "\n";
}

std::string LogView::getTagFromMap(LOG_TYPE logType)
{
   std::string result = "";

   for (auto item:logTypeMap){
      if (item.first == logType){
         result = item.second;
         return result;
      }
   }
   result = logTypeMap[LOG_TYPE::SYS_ERR];
   return result;   
}