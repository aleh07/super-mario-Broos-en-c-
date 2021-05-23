#include "clsMotor.h"

int clsMotor::init()
{
    error.set(mode.init(800,600,16));
    mode.crashPrevent();
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    error.set(screen.init(mode.getScrWidth(),
                          mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          RESIZABLE));
    error.set(Fondo.init("Imagenes/Fondo_juego.PNG"));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    error.set(ladrillo.init("Imagenes/Ladrillo.PNG"));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    error.set(Mario.init(&screen));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
     error.set(Enemigo.init(&screen));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }

    screen.setTitle("Mario Bros - ARCADE");
    salir=false;
    return error.get();
}
int clsMotor::run()
{
    screen.clean(BLACK);
    Fondo.paste(screen.getPtr());
    ladrillo.paste(screen.getPtr());
    screen.refresh();
    while(!salir)
    {
        screen.clean(BLACK);
        Fondo.paste(screen.getPtr());
        ladrillo.paste(screen.getPtr());
        Mario.avanzar(&screen);
        Enemigo.avanzar(&screen);
       //Mario.setgravActivada(true);
        Mario.gravedad(&screen);
        Mario.saltar(&screen);
       // Enemigo.gravedad(&screen);
       if(Mario.getContact(&Enemigo))
       {
           Mario.setgravActivada(false);
       }
;        screen.refresh();
        if(event.wasEvent())
        {
            switch(event.getEventType())
            {
            case KEY_PRESSED:
            {

                error.set( keyPressed(event.getKey()));
                if(error.get())
                {
                    error.show(true);
                    return error.get();
                }

            }
            break;
 case KEY_FREE:
            {

                error.set(keyFree(event.getKey()));
                if(error.get())
                {
                    error.show(true);
                    return error.get();
                }

            }
            break;

            }

        }
    }
    return error.get();
}
int clsMotor::keyPressed(Uint16 key)
{
    switch(key)
    {
     case KEY_RIGHT:
    {
        Mario.setDerecha(true);
         Mario.avanzar(&screen);

    }break;

     case KEY_LEFT:
    {
        Mario.setIzquierda(true);
         Mario.avanzar(&screen);

    }break;

     case KEY_UP:
    {
        Mario.arriba=true;

    }break;

    case KEY_ESCAPE:
    {
        salir=true;
    }
    break;
    }
    return error.get();
}

int clsMotor::keyFree(Uint16 key)
{
    switch(key)
    {
     case KEY_RIGHT:
    {
        Mario.setDerecha(false);
         Mario.setI(0);


    }break;
     case KEY_LEFT:
    {
        Mario.setIzquierda(false);
         Mario.setI(4);


    }break;

   case KEY_UP:
{
    Mario.arriba=false;
    Mario.setgravActivada(true);


    }break;

    case KEY_ESCAPE:
    {
        salir=true;
    }
    break;
    }
    return error.get();
}

