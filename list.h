#ifndef LIST_H
#define LIST_H
#include "nodo.h"
#include <iostream>
using namespace std;

template  <class T>

class Lista {

    Nodo<T>* inicio;
    Nodo<T>* final;
    int cantidadElmentos;

public:
    Lista() {
        this->inicio = nullptr;
        this->final = nullptr;
        this->cantidadElmentos=0;
    }

    Nodo<T>* getFirst()
    {
        return inicio;
    }

    bool guardar(T valor) {
        return insertar(valor,cantidadElmentos);
    }

    Nodo<T>* buscar(T comparar) {
        Nodo<T>* temporal = inicio;
        for(int i = 0; i < cantidadElmentos; i++)
        {
            if (*(temporal->valor) == *comparar)
                return temporal;
            temporal = temporal->siguiente;
        }
        return nullptr;
    }

    bool buscarE(T buscar)
    {
        Nodo<T>* temporal = inicio;
        for(int i = 0; i < cantidadElmentos; i++)
        {
            if (*(temporal->valor) == *buscar)
                return true;
            temporal = temporal->siguiente;
        }
        return false;
    }

    int getPos(T comparar)
    {
        int contara=0;
        Nodo<T>* temporal = this->inicio;
        while(temporal!=nullptr)
        {
            if(*(temporal->valor)==*comparar)
                return contara;
            contara++;
            temporal=temporal->siguiente;
        }
        return -1;
    }

    bool eliminar(T valor) {
        Nodo<T>* eliminar;

        if(cantidadElmentos==0)
            return false;

        if(cantidadElmentos==1 && valor==inicio->valor)
        {
            eliminar=inicio;
            final= nullptr;
            inicio=nullptr;
        }else if(inicio->valor==valor)
        {
            eliminar=inicio;
            inicio=inicio->siguiente;
        }else
        {
            Nodo<T>* temporal=inicio;
            for(int i = 0; i<cantidadElmentos-1; i++)
                if (temporal->siguiente->valor==valor && cantidadElmentos-1!=i)
                {
                    eliminar = temporal->siguiente;
                    temporal->siguiente=temporal->siguiente->siguiente;
                }
                else if (temporal->siguiente->valor==valor && cantidadElmentos-1==i)
                {
                    eliminar = temporal->siguiente;
                    temporal->siguiente=final;
                    final=temporal;
                }else
                {
                    temporal=temporal->siguiente;
                }
        }
        cantidadElmentos--;
        return true;
    }


    Nodo<T>* obtenerPosicionInicial(int inicial) {
        Nodo<T>* ttemporal = inicio;
        for(int i = 0; i < inicial; i++)
        {
            ttemporal=ttemporal->siguiente;
        }
        return ttemporal;
    }

    bool insertar(T valor, int posicion) {
        if(posicion < 0 || posicion > cantidadElmentos)
            return false;

        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (cantidadElmentos == 0)
        {
            final=nuevo;
            nuevo->siguiente = nullptr;
            nuevo->anterior= nullptr;
            inicio = nuevo;
        }else if (1 == cantidadElmentos)
        {
            inicio->siguiente = nuevo;
            nuevo->anterior=inicio;
            nuevo->siguiente= nullptr;
            final = nuevo;
        }else if(posicion==0)
        {
            nuevo->siguiente=inicio;
            inicio->anterior=nuevo;
            nuevo->anterior= nullptr;
            inicio=nuevo;
        }else
        {
            Nodo<T>* temporal= inicio;
            for (int i = 0; i < posicion-1; ++i)
                temporal = temporal->siguiente;
            nuevo->siguiente = temporal->siguiente;
            nuevo->anterior=temporal;
            temporal->siguiente = nuevo;
        }
        cantidadElmentos++;
        return true;
    }

    int eliminar(int posicion) {
        if (posicion < 0 || posicion >= cantidadElmentos)
            return -1;

        Nodo<T>* eliminar;

        if(cantidadElmentos==0)
            return -1;

        if (posicion == 0)
        {
            eliminar = inicio;
            inicio = inicio->siguiente;
        }else if (1 == cantidadElmentos)
        {
            eliminar = inicio->siguiente;
            final = nullptr;
        }else if(posicion==cantidadElmentos-1)
        {
            Nodo<T>* temporal = inicio;
            for(int i = 0; i < cantidadElmentos-3; i++)
                temporal=temporal->siguiente;
            eliminar=temporal->siguiente;
            temporal->siguiente=final;
            final=temporal;
        }
        else
        {
            Nodo<T>* temporal = inicio;
            for (int i = 0; i < posicion-1; ++i) {
                temporal = temporal->siguiente;
                eliminar = temporal->siguiente;
                temporal->siguiente = temporal->siguiente->siguiente;
            }
        }
        cantidadElmentos--;
        return eliminar->valor;
    }

    int getSize() {
        return this->cantidadElmentos;
    }

    T buscar(int valor) {
        if(valor<0 || valor > cantidadElmentos)
            return nullptr;
        Nodo<T>* temporal = inicio;
        for (int i = 0; i < valor ; ++i)
        {
            temporal=temporal->siguiente;
        }
        return temporal->valor;
    }
};

#endif // LIST_H
