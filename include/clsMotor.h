#ifndef CLSMOTOR_H
#define CLSMOTOR_H
#include <adnConsts.h>
#include <clsError.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <clsEvent.h>
#include <clsFondo.h>
#include <clsLadrillo.h>
#include <clsPersonaje.h>
#include <clsEnemigo.h>

class clsMotor
{
public:
    int init();
    int run();
    int keyPressed(Uint16);
    int keyFree(Uint16);
private:
    bool salir;
    clsScreen screen;
    clsMode mode;
    clsEvent event;
    clsError error;
    clsFondo Fondo;
    clsLadrillo ladrillo;
    clsPersonaje Mario;
    clsTimer timer;
    clsEnemigo Enemigo;

};


#endif // CLSMOTOR_H
