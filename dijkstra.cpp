#include "dijkstra.h"

dijkstra::dijkstra()
{
    this->listaVertices = new ArrayListP<Vertice*>();
}

bool dijkstra::vacio()
{
    if(this->listaVertices->getSize()==0)
        return true;
    return false;
}

bool dijkstra::existeConexion(Vertice *inicial, Vertice *final)
{
    if(inicial->aristas->getSize()==0)
        return false;

    Nodo<Arista*>* temporal = inicial->aristas->getFirst();
    for(int i=0;i<inicial->aristas->getSize();i++)
    {
         temporal=inicial->aristas->obtenerPosicionInicial(i);
         if(temporal!=nullptr && temporal->valor->verticeFinal==final)
             return true;
    }
    return false;
}

int dijkstra::tamanoGrafo()
{
    return this->listaVertices->getSize();
}

Vertice *dijkstra::getvertice(string buscando)
{
    Vertice* temporal = new Vertice();
    temporal->nombre=buscando;
    Nodo<Vertice*>* tem = this->listaVertices->buscar(temporal);
    if(tem==nullptr)
        return nullptr;
    return tem->valor;
}

bool dijkstra::insertarArista(Vertice *inicial, Vertice *final, int peso)
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

bool dijkstra::insertarArista(string nIn, string nFin, int peso)
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

bool dijkstra::insertarVertice(string nombreVertice)
{
    if(existeVertice(nombreVertice))
        return false;
    Vertice* nuevoNodo = new Vertice();
    nuevoNodo->nombre=nombreVertice;
    return this->listaVertices->guardar(nuevoNodo);
}

void dijkstra::listarAdyacentes()
{
    Vertice* vertice;
    Nodo<Arista*>* arista;
    for(int i = 0; i< this->listaVertices->getSize();i++)
    {
        vertice = this->listaVertices->buscar(i);
        arista=vertice->aristas->getFirst();
        cout<<vertice->nombre<<": "<<endl;
        while(arista!=nullptr)
        {
            cout<<"->"<<arista->valor->verticeFinal->nombre;
            arista=arista->siguiente;
        }
    }
    cout<<endl;
}

bool dijkstra::buscarvertice(Vertice *primero, Vertice *segundo)
{
    if(primero==nullptr || segundo==nullptr)
        return false;
    if(getvertice(primero->nombre)!= nullptr && getvertice(segundo->nombre) != nullptr)
        return true;
    return false;
}

bool dijkstra::eliminarArista(Vertice *origen, Vertice *destino)
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

bool dijkstra::eliminarArista(string origen, string destino)
{
    Vertice* primero = this->getvertice(origen);
    Vertice* segundo = this->getvertice(destino);
    return this->eliminarArista(primero,segundo);
}

bool dijkstra::eliminarVertice(Vertice *eliminar)
{
    if(eliminar==nullptr)
        return false;

    if(getvertice(eliminar->nombre) == nullptr)
    {
        cout<<"No se encontro el vertice ingresado"<<endl;
        return false;
    }

    Vertice* verticeT;
    Nodo<Arista*>* aristaT;

    for(int i=0;i<listaVertices->getSize();i++)
    {
        verticeT=this->listaVertices->buscar(i);
        aristaT=verticeT->aristas->getFirst();
        while(aristaT!=nullptr)
        {
            if(aristaT->valor->verticeFinal->nombre==eliminar->nombre)
                verticeT->aristas->eliminar(aristaT->valor);
            aristaT=aristaT->siguiente;
        }
    }
    return this->listaVertices->eliminarValor(eliminar);
}

bool dijkstra::eliminarVertice(string eliminar)
{
    Vertice* delet = this->getvertice(eliminar);
    return this->eliminarVertice(delet);
}

bool dijkstra::existeVertice(string nombre)
{
    Vertice* temporal = new Vertice();
    temporal->nombre=nombre;
    return this->listaVertices->buscarE(temporal);
}

bool dijkstra::existeArista(Vertice *inicial, Vertice *final)
{
    if(!buscarvertice(inicial,final))
        return nullptr;
    Nodo<Arista*>* temporal = inicial->aristas->getFirst();
    while(temporal!=nullptr)
    {
        if(temporal->valor->verticeFinal->nombre==final->nombre)
            return temporal;
        temporal=temporal->siguiente;
    }
    return nullptr;
}

int dijkstra::pesoTotal(Vertice *inicial, Vertice *final)
{
    if(!buscarvertice(inicial,final))
        return -1;
    Arista* temporal= getArista(inicial,final);
    if(temporal!=nullptr)
        return temporal->peso;
    return -1;
}

Arista *dijkstra::getArista(Vertice *inicial, Vertice *final)
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

Vertice *dijkstra::getFirst()
{
    Nodo<Vertice*>* temporal = this->listaVertices->getFirst();
    if(temporal!=nullptr)
        return temporal->valor;
    return nullptr;
}


