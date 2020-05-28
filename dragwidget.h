#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H
#include <math.h>
#include<QFrame>
#include <QMainWindow>
#include<time.h>
#include <QFrame>
#include<QLabel>
#include<QString>
#include <QtWidgets>
#include <cString>
#include<QPainter>
#include<QPoint>
#include <QTextEdit>
#include<QMouseEvent>
#include<QMessageBox>
#include"grafo.h"
#include "button.h"
#include"arraylist.h"
#include"dijkstra.h"
#include "circulovertice.h"
#include"infomostrar.h"
#include"circulovertice.h"
#include"pila.h"
#include"cola.h"
#include"informationPrim.h"
QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

using namespace std;
class DragWidget : public QFrame
{

public slots:
void handleSubmit();
void handleSubmitDelet();
void handleSubmitDeletVertie();
signals:

public:
    QString grafoActual;
    QMessageBox mensaje;
    Lista<circuloVertice*>* listaCirculosGrafo;
    Grafo* grafoPrincipal;
    Grafo* imprimir;
    Grafo* grafoFloyd;
    Grafo* grafoWarshall;
    Grafo* grafoDijkstra;
    Grafo* prim;
    Grafo* kruskal;
    ArrayListP<Vertice*>* arrayD;
    bool relleno=true;
    void setText();
    DragWidget(QWidget *parent = 0);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    infoMostrar* mostrarInfo;
    QPainter* r;
    QPainterPath path;
    QTextEdit* nombreInicio;
    QTextEdit* nombreFin;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    int x1=0,x2=300,y1=3,y2=300;
    void grafoToWarshall();
    void grafoToPrincipal();
    void copyGraphto(Grafo* nuevo);
    void grafoToFloyd();
    void grafoToDjikstra();
    void recorridoAnchura();
    void recorridoProfundidad();
    void grafoPrim();
    void grafoKruskal();
};

#endif // DRAGWIDGET_H
