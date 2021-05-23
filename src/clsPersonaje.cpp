#include "clsPersonaje.h"

int clsPersonaje::init(clsScreen *s)
{
    Derecha=false;
    Izquierda=false;
    gravActivada=true;
    arriba=false;
    this->screen=s;
    error.set(0);
    setItems(10);

    setI(0);
    error.set(load("Imagenes/Mario1.PNG"));
    if(error.get()) return error.get();

    setI(1);
    error.set(load("Imagenes/Mario2.PNG"));
    if(error.get()) return error.get();

    setI(2);
    error.set(load("Imagenes/Mario3.PNG"));
    if(error.get()) return error.get();

    setI(3);
    error.set(load("Imagenes/Mario4.PNG"));
    if(error.get()) return error.get();

    setI(4);
    error.set(load("Imagenes/MarioIzq1.PNG"));
    if(error.get()) return error.get();

    setI(5);
    error.set(load("Imagenes/MarioIzq2.PNG"));
    if(error.get()) return error.get();

    setI(6);
    error.set(load("Imagenes/MarioIzq3.PNG"));
    if(error.get()) return error.get();

    setI(7);
    error.set(load("Imagenes/MarioIzq4.PNG"));
    if(error.get()) return error.get();

    setI(8);
    error.set(load("Imagenes/MarioIzq5.PNG"));
    if(error.get()) return error.get();

    setI(9);
    error.set(load("Imagenes/Mario5.PNG"));
    if(error.get()) return error.get();

    setI(10);
    error.set(load("Imagenes/Mario6.PNG"));
    if(error.get()) return error.get();


    setI(0);
    setX(200);
    setY(300);

    return error.get();
}

void clsPersonaje::setDerecha(bool D)
{
    this->Derecha=D;
}

void clsPersonaje::setIzquierda(bool I)
{
    this->Izquierda=I;

}
void clsPersonaje::setgravActivada(bool A )
{
    this->gravActivada=A;
}


void clsPersonaje::avanzar(clsScreen * S)
{

    if(Derecha)
    {

        setX(getX()+10); //sumo la velocidad a la ubicacion actual
        if(getX()>S->getWidth()) //verifico si se supero el largo de la pantalla
        {
            setX(0-getWidth());  //coloco el avion en el comienzo de la pantalla
        }
        if(getI()==4)
        {
            setI(0);
        }

        setI(getI()+1);
        if(getI()==3)
        {
            setI(0);
        }

    }

    if(Izquierda)
    {
        setX(getX()-10); //sumo la velocidad a la ubicacion actual
        if(getX()<-50) //verifico si se supero el largo de la pantalla
        {
            setX(0+850);  //coloco el avion en el comienzo de la pantalla
        }
        setI(getI()+1);
        if(getI()==7)
        {
            setI(4);

        }

    }

    paste(S->getPtr());  //Pego el avion

}

void clsPersonaje::gravedad(clsScreen * scr)
{

    if(gravActivada==true)
    {
      if(getY() ==485)
        {
            gravActivada=false;
        }
        setY(getY()+5);


    }
}

void clsPersonaje::saltar(clsScreen *S)
{
    if(arriba)
    {

            setY(getY()-10);




    }


}
