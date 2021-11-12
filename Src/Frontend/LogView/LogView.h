#pragma once
#include "Backend.h"

class LogView : public IObserver
{
public:
   LogView ();
   virtual ~LogView ();

   void Update (const std::string& message_from_logger) override;
   void RemoveLogViewFromLogger ();
   void PrintInfo ();

private:
   //Logger* logger_;
   std::string message_from_logger_;
};