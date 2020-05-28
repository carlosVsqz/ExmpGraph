#include "vertice.h"


Vertice::Vertice()
{
    this->aristas = new Lista<Arista*>();
    this->nombre="";
    this->dibujado=nullptr;
}

