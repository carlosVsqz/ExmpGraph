#include "grafo.h"


Grafo::Grafo()
{
    this->listaVertices = new Lista<Vertice*>();
}

Vertice* Grafo::getvertice(string buscando)
{
    Vertice* temporal = new Vertice();
    temporal->nombre=buscando;
    Nodo<Vertice*>* tem = this->listaVertices->buscar(temporal);
    if(tem==nullptr)
        return nullptr;
    return tem->valor;
}

int Grafo::tamanoGrafo()
{
    return this->listaVertices->getSize();
}

bool Grafo::insertarVertice(string nombreVertice)
{
    if(existeVertice(nombreVertice))
        return false;

    Vertice* nuevoNodo = new Vertice();
    nuevoNodo->nombre=nombreVertice;
    return this->listaVertices->guardar(nuevoNodo);
}

bool Grafo::vacio()
{
    if(this->listaVertices->getSize()==0)
        return true;
    return false;
}

bool Grafo::existeConexion(Vertice *inicial, Vertice *final)
{
    if(inicial->aristas->getSize()==0)
        return false;

    Nodo<Arista*>* temporal = inicial->aristas->getFirst();
    while(temporal!=nullptr)
    {
         if(temporal->valor->verticeFinal->nombre==final->nombre)
             return true;
         temporal=temporal->siguiente;
    }
    return false;
}

void Grafo::listarAdyacentes()
{
    Nodo<Vertice*>* vertice=this->listaVertices->getFirst();
    Nodo<Arista*>* arista;
    while(vertice!=nullptr)
    {
        arista=vertice->valor->aristas->getFirst();
        cout<<vertice->valor->nombre<<": "<<endl;
        while(arista!=nullptr)
        {
            cout<<"->"<<arista->valor->verticeFinal->nombre;
            arista=arista->siguiente;
        }
        vertice=vertice->siguiente;
    }
    cout<<endl;
}

bool Grafo::buscarvertice(Vertice* primero, Vertice* segundo)
{
    if(primero==nullptr || segundo==nullptr)
        return false;
    if(getvertice(primero->nombre)!= nullptr && getvertice(segundo->nombre) != nullptr)
        return true;
    return false;
}

bool Grafo::eliminarArista(Vertice *origen, Vertice *destino)
{
    if(!buscarvertice(origen,destino))
        return false;
    Nodo<Arista*>* temporal = origen->aristas->getFirst();
    while(temporal!=nullptr)
    {
        if(temporal->valor->verticeFinal->nombre==destino->nombre)
            return origen->aristas->eliminar(temporal->valor);
        temporal = temporal->siguiente;
    }
    return false;
}

bool Grafo::eliminarArista(string origen, string destino)
{
    Vertice* primero = this->getvertice(origen);
    Vertice* segundo = this->getvertice(destino);
    return this->eliminarArista(primero,segundo);

}

bool Grafo::eliminarVertice(Vertice *eliminar)
{
    if(eliminar==nullptr)
        return false;

    if(getvertice(eliminar->nombre) == nullptr)
    {
        cout<<"No se encontro el vertice ingresado"<<endl;
        return false;
    }

    Nodo<Vertice*>* verticeT = this->listaVertices->getFirst();
    Nodo<Arista*>* aristaT;

    while(verticeT!=nullptr)
    {
        aristaT=verticeT->valor->aristas->getFirst();
        while(aristaT!=nullptr)
        {
            if(aristaT->valor->verticeFinal->nombre==eliminar->nombre)
                verticeT->valor->aristas->eliminar(aristaT->valor);
            aristaT=aristaT->siguiente;
        }
        verticeT=verticeT->siguiente;
    }
    return this->listaVertices->eliminar(eliminar);
}

bool Grafo::eliminarVertice(string eliminar)
{
    Vertice* delet = this->getvertice(eliminar);
    return this->eliminarVertice(delet);
}


bool Grafo::existeVertice(string nombre)
{
    Vertice* temporal = new Vertice();
    temporal->nombre=nombre;
    return this->listaVertices->buscarE(temporal);
}

bool Grafo::existeArista(Vertice *inicial, Vertice *final)
{
    if(!buscarvertice(inicial,final))
        return false;
    Nodo<Arista*>* temporal = inicial->aristas->getFirst();
    while(temporal!=nullptr)
    {
        if(temporal->valor->verticeFinal->nombre==final->nombre)
            return true;
        temporal=temporal->siguiente;
    }
    return false;
}

int Grafo::pesoTotal(Vertice *inicial, Vertice *final)
{
    if(!buscarvertice(inicial,final))
        return -1;
    Arista* temporal= getArista(inicial,final);
    if(temporal!=nullptr)
        return temporal->peso;
    return -1;
}

Arista *Grafo::getArista(Vertice *inicial, Vertice *final)
{
    if(!buscarvertice(inicial,final))
        return nullptr;
    Nodo<Arista*>* temporal = inicial->aristas->getFirst();
    while(temporal!=nullptr)
    {
        if(temporal->valor->verticeFinal->nombre==final->nombre)
            return temporal->valor;
        temporal=temporal->siguiente;
    }
    return nullptr;
}

Vertice *Grafo::getFirst()
{
    Nodo<Vertice*>* temporal = this->listaVertices->getFirst();
    if(temporal!=nullptr)
        return temporal->valor;
    return nullptr;
}

bool Grafo::insertarArista(Vertice *inicial, Vertice *final, int peso)
{
    if(buscarvertice(inicial,final))
    {
        Nodo<Arista*>* temporal;
        temporal=inicial->aristas->getFirst();
        while(temporal!=nullptr)
        {            
            if(temporal->valor->verticeFinal->nombre==final->nombre)
                return false;
            temporal=temporal->siguiente;
        }
        Arista* nuevaArista = new Arista();
        nuevaArista->peso=peso;
        nuevaArista->verticeInicial=inicial;
        nuevaArista->verticeFinal=final;
        nuevaArista->id=to_string(this->aristaId);
        this->aristaId++;
        return inicial->aristas->guardar(nuevaArista);
    }
    return false;
}

bool Grafo::insertarArista(string nIn, string nFin, int peso)
{
    Vertice* inicial = getvertice(nIn);
    Vertice* final = getvertice(nFin);
    if(buscarvertice(inicial,final))
    {
        Nodo<Arista*>* temporal;
        temporal=inicial->aristas->getFirst();
        while(temporal!=nullptr)
        {
            if(temporal->valor->verticeFinal->nombre==final->nombre)
                return false;
            temporal=temporal->siguiente;
        }
        Arista* nuevaArista = new Arista();
        nuevaArista->peso=peso;
        nuevaArista->verticeInicial=inicial;
        nuevaArista->verticeFinal=final;
        nuevaArista->id=to_string(this->aristaId);
        this->aristaId++;
        return inicial->aristas->guardar(nuevaArista);
    }
    return false;

}
