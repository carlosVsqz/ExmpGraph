#ifndef ARISTA_H
#define ARISTA_H
#include<iostream>
#include"vertice.h"

using namespace std;

class Vertice;
class Arista
{
public:
    Arista();
    Vertice* verticeInicial;
    Vertice* verticeFinal;
    int peso;
    string id;
    bool operator ==(Arista m) {
            return this->id == m.id;
        }
};

#endif
