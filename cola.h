#ifndef COLA_H
#define COLA_H
#include"nodo.h"
#include <iostream>

template  <class T>
class Cola
{
    Nodo<T>* inicio;
    Nodo<T>* final;
    int cantidadElmentos;
public:
    Cola(){
        this->inicio = nullptr;
        this->final = nullptr;
        this->cantidadElmentos=0;
    }

    T front()
    {
        return inicio->valor;
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
            inicio = nuevo;
            final=nuevo;
            nuevo->siguiente = nullptr;
            nuevo->anterior= nullptr;
        }
        {
            final->siguiente=nuevo;
            nuevo->anterior=final;
            final=nuevo;
        }
        cantidadElmentos++;
        return true;
    }

    T pop_front() {

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
            eliminar=inicio;
            inicio->siguiente->anterior=nullptr;
            inicio=inicio->siguiente;
        }
        cantidadElmentos--;
        return eliminar->valor;
    }

    int size() {
        return this->cantidadElmentos;
    }
};

#endif // COLA_H
