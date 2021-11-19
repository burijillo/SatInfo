#include "Logger.h"

Logger::Logger ()
{
   
}

Logger& Logger::GetLogger ()
{
   static Logger logger;
   return logger;
}

Logger::~Logger ()
{
   std::cout << "End log session\n";
}

void Logger::Attach (IObserver* observer)
{
   list_observers.push_back (observer);
}

void Logger::Dettach (IObserver* observer)
{
   list_observers.remove (observer);
}

void Logger::Notify ()
{
   std::list<IObserver*>::iterator iter = list_observers.begin ();
   while (iter != list_observers.end ()) {
      (*iter)->Update (message, logType);
      ++iter;
   }
}

void Logger::CreateMessage (std::string message, IObserver::LOG_TYPE logType)
{
   this->message = message;
   this->logType = logType;
   Notify ();
}