#ifndef INFOMOSTRAR_H
#define INFOMOSTRAR_H
#include<iostream>
#include<QString>
#include <QFrame>
#include<QLabel>
#include <cstring>
QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

using namespace std;

class infoMostrar: public QLabel
{
public:
    infoMostrar(QWidget *parent = 0);
    QString texto;
    void mostrando(string nombre);
    string nombre;
};

#endif // INFOMOSTRAR_H
