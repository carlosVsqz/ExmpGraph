#ifndef VERTICE_H
#define VERTICE_H
#include"arista.h"
#include"list.h"
#include"circulovertice.h"
#include<iostream>
using namespace std;

class Arista;
class circuloVertice;
class Vertice
{
public:
    Vertice();
    string nombre;
    Lista<Arista*>* aristas;
    circuloVertice* dibujado;
    bool operator ==(Vertice m) {
            return this->nombre == m.nombre;
        }
};


#endif // VERTICE_H
