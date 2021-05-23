#include "clsEnemigo.h"

int clsEnemigo::init(clsScreen *s)
{
    Derecha=false;
    Izquierda=false;
    arriba=false;
    this->screen=s;
    error.set(0);
    setItems(2);

    setI(0);
    error.set(load("Imagenes/Tortugaverdederecha.png"));
    if(error.get()) return error.get();

    setI(1);
    error.set(load("Imagenes/Tortugaverdeizquierda.png"));
    if(error.get()) return error.get();


    setI(0);
    setX(200);
    setY(200);

    return error.get();
}

void clsEnemigo::setDerecha(bool D)
{
    this->Derecha=D;
}

void clsEnemigo::setIzquierda(bool I)
{
    this->Izquierda=I;

}



void clsEnemigo::avanzar(clsScreen * S)
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

void clsEnemigo::gravedad(clsScreen * scr)
{
      if(getY() ==485)
        {
            arriba=false;
        }
        setY(getY()+5);


    }


void clsEnemigo::saltar(clsScreen *S)
{
    if(arriba)
    {

            setY(getY()-10);




    }


}
