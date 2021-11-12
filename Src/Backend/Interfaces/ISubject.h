#pragma once
#include "IObserver.h"

class ISubject
{
public:
   virtual ~ISubject () {};
   virtual void Attach (IObserver* observer) = 0;
   virtual void Dettach (IObserver* observer) = 0;
   virtual void Notify () = 0;
};