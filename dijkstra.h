#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include"vertice.h"
#include"arista.h"
#include"nodo.h"
#include"arraylist.h"

class dijkstra
{
public:
    dijkstra();
    ArrayListP<Vertice*>* listaVertices;
    int aristaId=0;
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

#endif // DIJKSTRA_H
