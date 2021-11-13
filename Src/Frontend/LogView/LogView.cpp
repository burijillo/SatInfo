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
   logTextCtrl = new wxTextCtrl(parent, wxID_ANY, "[LOG]: Log initialization", wxPoint(0,0), parent->FromDIP(wxSize(150, 90)), wxNO_BORDER | wxTE_MULTILINE);
   logTextCtrl->SetModified(false);
}

void LogView::Update (const std::string& message_from_logger)
{
   message_from_logger_ = message_from_logger;
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
   (*logTextCtrl) << "[LOG]: " << message_from_logger_ << "\n";
}