#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include<queue>
#include<list>
#include<stack>
#include"vertice.h"
#include"arista.h"
#include"list.h"
#include"nodo.h"
using namespace std;

class Vertice;
class Arista;
class Grafo
{
public:
    Lista<Vertice*>* listaVertices;
    int aristaId=0;
    Grafo();
    bool vacio();
    bool existeConexion(Vertice*inicial,Vertice*final);
    int tamanoGrafo();
    Vertice* getvertice(string buscando);
    bool insertarArista(Vertice *inicial, Vertice *final, int peso);
    bool insertarArista(string inicial, string final, int peso);
    bool insertarVertice(string nombreVertice);
    void listarAdyacentes();
    bool buscarvertice(Vertice *primero, Vertice *segundo);
    bool eliminarArista(Vertice* origen, Vertice* destino);
    bool eliminarArista(string origen, string destino);
    bool eliminarVertice(Vertice* eliminar);
    bool eliminarVertice(string eliminar);
    bool existeVertice(string nombre);
    bool existeArista(Vertice* inicial, Vertice* final);
    int pesoTotal(Vertice* inicial, Vertice* final);
    Arista* getArista(Vertice* inicial, Vertice* final);
    Vertice* getFirst();
};

#endif
