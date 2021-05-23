#include "clsFondo.h"

int clsFondo::init(const char* path)
{
    setItems(1);
    setI(0);

    error.set(load(path));
    if(error.get())return error.get();
    setName(path);
    setX(0);
    setY(0);
    setI(0);

return error.get();
}
