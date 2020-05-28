#ifndef PILA_H
#define PILA_H
#include "nodo.h"
#include <iostream>
using namespace std;

template  <class T>
class Pila
{
    Nodo<T>* inicio;
    Nodo<T>* final;
    int cantidadElmentos;
public:
    Pila(){
        this->inicio = nullptr;
        this->final = nullptr;
        this->cantidadElmentos=0;
    }

    T top()
    {
        return final->valor;
    }

    bool empty()
    {
        if(this->cantidadElmentos==0)
            return true;
        return false;
    }

    bool push_back(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (cantidadElmentos == 0)
        {
            final=nuevo;
            nuevo->siguiente = nullptr;
            nuevo->anterior= nullptr;
            inicio = nuevo;
        }
        {
            final->siguiente=nuevo;
            nuevo->anterior=final;
            final=nuevo;
        }
        cantidadElmentos++;
        return true;
    }

    T pop_back() {

        Nodo<T>* eliminar;

        if(cantidadElmentos==0)
            return nullptr;

        if(cantidadElmentos==1)
        {
            eliminar=inicio;
            final= nullptr;
            inicio=nullptr;
        }else
        {
            eliminar=final;
            final->anterior->siguiente=nullptr;
            final=final->anterior;
        }
        cantidadElmentos--;
        return eliminar->valor;
    }

    int size() {
        return this->cantidadElmentos;
    }
};

#endif // PILA_H
