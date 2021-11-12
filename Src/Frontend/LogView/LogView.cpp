#include "LogView.h"

LogView::LogView ()
{
   Logger& logger_ = Logger::GetLogger ();
   //logger_ = Logger::GetLogger ();
   std::cout << "Log view session starts\n";
   logger_.Attach (this);
}

LogView::~LogView ()
{
   std::cout << "Log view session ends\n";
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
   std::cout << "[LOG]: " << this->message_from_logger_ << "\n";
}