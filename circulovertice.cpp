#include "circulovertice.h"

circuloVertice::circulovertice()
{
    this->representavertice=nullptr;
    this->name="";
    this->x=0;
    this->y=0;
}

circuloVertice::circuloVertice()
{
    this->name="";
    this->ruta=("C:/Users/DELL 5040 I7/Documents/ProyectoGrafo/images/vertice.png");
}

bool circuloVertice::createVertice(string name,int x, int y)
{
    this->name=name;
    this->x=x;
    this->y=y;
    return true;
}
