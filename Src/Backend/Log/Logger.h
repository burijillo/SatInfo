#pragma once
#include "../Interfaces/ISubject.h"
#include <list>

class Logger : public ISubject
{
public:
   //Logger (Logger& other) = delete;
   //void operator=(const Logger&) = delete;
   static Logger &GetLogger ();
   virtual ~Logger ();

   void Attach (IObserver* observer) override;
   void Dettach (IObserver* observer) override;
   void Notify () override;

   void CreateMessage (std::string message = "Empty");

private:
   //static Logger* logger;
   Logger ();

   std::list<IObserver*> list_observers;
   std::string message;
};