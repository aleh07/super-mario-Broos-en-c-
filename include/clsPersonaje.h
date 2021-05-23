#ifndef CLSPERSONAJE_H
#define CLSPERSONAJE_H
#include <adnConsts.h>
#include <clsSprite.h>
#include <clsScreen.h>
#include <clsTimer.h>
#include <clsLadrillo.h>


class clsPersonaje : public clsSprite
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
   bool gravActivada;
    clsScreen *screen;
    clsTimer timer;
    clsLadrillo ladrillo;


};



#endif // CLSPERSONAJE_H
