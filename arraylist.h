#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include<iostream>
#include"nodo.h"
using namespace std;
template<class T>

class ArrayListP
{
    int tamanoArray=50;
    int cantidadElementos;
    T* array;
public:
    bool change(int f, int s)
    {
        if(f<0 || f>=cantidadElementos || s<0 || s>=cantidadElementos)
            return false;
        T ts = array[f];
        array[f]=array[s];
        array[s]=ts;
        return true;
    }

    ArrayListP(){
        this->array = new T [50];
        this->cantidadElementos=0;
    }

    Nodo<T>* getFirst()
    {
        Nodo<T>* nuevo = new Nodo<T>(array[0]);
        return nuevo;
    }

    bool insertar(T valor, int posicion) {
            if(posicion > this->cantidadElementos || posicion < 0)
                return false;
            if(this->cantidadElementos == this->tamanoArray)
                this->duplicarArray();

            for(int i = this->cantidadElementos; i > posicion ; i--)
                array[i]=array[i-1];

            array[posicion] = valor;
            this->cantidadElementos++;
            return true;
        }

    T buscar(int valor) {
        if(valor<0 || valor > cantidadElementos)
            return nullptr;
        return array[valor];
    }

    Nodo<T>* obtener(int posicion) {
        Nodo<T>* n= new Nodo<T>(array[posicion]);
        return n;
    }

    int getSize()
    {
        return this->cantidadElementos;
    }

    Nodo<T>* buscar(T valor) {
        Nodo<T>* temporal = new Nodo<T>(valor);
        for(int i = 0; i < this->cantidadElementos; i++){
            if (*(temporal->valor) == *(array[i]))
            {
                return temporal;
            }
        }
        return nullptr;
    }

    bool buscarE(T valor) {
        Nodo<T>* temporal = new Nodo<T>(valor);
        for(int i = 0; i < this->cantidadElementos; i++){
            if (*(temporal->valor) == *(array[i]))
            {
                return true;
            }
        }
        return false;
    }

    int getPos(T valor) {
        Nodo<T>* temporal = new Nodo<T>(valor);
        for(int i = 0; i < this->cantidadElementos; i++){
            if (*(temporal->valor) == *(array[i]))
            {
                return i;
            }
        }
        return -1;
    }

    bool eliminarPosicion(int posicion) {
        if(posicion >= this->cantidadElementos)
            return false;

        for(int i = posicion; i < this->cantidadElementos-1; i++)
            array[i] = array[i+1];
        cantidadElementos--;

        if(this->cantidadElementos*2 >= tamanoArray)
        this->decrementarArray();

        return true;
    }


    bool eliminarValor(T valor) {
        int posicion = getPos(valor);
        if (posicion == -1)
            return -1;
        return eliminarPosicion(posicion);
    }

    void duplicarArray() {
        T *temp = new T[cantidadElementos*2];
        for(int i =0 ; i < this->cantidadElementos; i++)
            temp[i] = array[i];
        delete [] array;
        array = temp;
    }

    void decrementarArray() {
        if (this->tamanoArray/2 < this->cantidadElementos)
            return;
            int n= cantidadElementos+(cantidadElementos/2);
            T* temp = new T[n];
            for (int i = 0; i < this->cantidadElementos; ++i)
                temp[i] = array[i];

                delete [] array;
                array = temp;
    }

    bool guardar(T valor) {
        return insertar(valor, this->cantidadElementos);
    }
};

#endif
