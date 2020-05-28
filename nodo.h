#ifndef NODO_H
#define NODO_H

template <class T>

class Nodo {
public:
    Nodo(T valor)
    {
        this->valor = valor;
        this->anterior  = nullptr;
        this->siguiente = nullptr;
    }
    T valor;
    Nodo* siguiente;
    Nodo* anterior;
};
#endif // NODO_H
