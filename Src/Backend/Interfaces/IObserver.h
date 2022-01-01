#pragma once
#include <string.h>
#include <iostream>

class IObserver
{
public:
   enum class LOG_TYPE {
      LOG,
      PARSER,
      SYS_ERR,
      CURL_MAN
   };

   virtual ~IObserver () {};
   virtual void Update (const std::string& message_from_subject, LOG_TYPE log_type) = 0;
};