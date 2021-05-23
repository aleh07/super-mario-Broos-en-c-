#ifndef CLSENEMIGO_H
#define CLSENEMIGO_H

#include <clsPersonaje.h>
#include <adnConsts.h>
#include <clsSprite.h>
#include <clsScreen.h>
#include <clsTimer.h>
#include <clsLadrillo.h>




class clsEnemigo : public clsPersonaje
{
    public:
       int init(clsScreen *);
       void animar();
       void avanzar(clsScreen *);
       void setDerecha(bool);
       void setIzquierda(bool);
       bool arriba;
       void setgravActivada(bool);
        void gravedad(clsScreen *);
        void saltar(clsScreen *);

    protected:
    void inherit(){};
    bool Derecha;
    bool Izquierda;
    clsScreen *screen;
    clsTimer timer;
    clsLadrillo ladrillo;
};

#endif // CLSENEMIGO_H
