#include "cslMotor.h"


int clsMotor::init()
{
  error.set(0);
  error.set(mode.init(DEFAULT));

  if(error.get())return error.get();

 error.set(screen.init(mode.getScrDepth(),
                      mode.getScrHeight(),
                      mode.getScrWidth()
                      ENABLED,
                      RESIZABLE));
                      if(error.get())return error.get();
                      //error.set(fondo)
//                      if(error.get())return error.get();
//                      return error.get();

}

int clsMotor::run()
