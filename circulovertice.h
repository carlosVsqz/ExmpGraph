#ifndef CIRCULOVERTICE_H
#define CIRCULOVERTICE_H
#include <QLabel>
#include<iostream>
#include <QFrame>
#include<QLabel>
#include <cstring>
#include<QPixmap>
#include<QPoint>
#include"grafo.h"
QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

using namespace std;

class circuloVertice
{
    QString ruta;
public:
    circulovertice();
    string name;
    int x,y;
    Vertice* representavertice;
    circuloVertice();
    bool createVertice(string name, int x, int y);

    bool operator ==(circuloVertice m) {
            return this->name == m.name;
    }
};

#endif // CIRCULOVERTICE_H
