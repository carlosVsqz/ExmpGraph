QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProyectoGrafo
TEMPLATE = app


SOURCES += main.cpp\
        dragwidget.cpp \
    grafo.cpp \
    circulovertice.cpp \
    infomostrar.cpp \
    list.cpp \
    nodo.cpp \
    vertice.cpp \
    arista.cpp \
    button.cpp \
    arraylist.cpp \
    pila.cpp \
    cola.cpp \
    informationPrim.cpp

HEADERS  += dragwidget.h \
    grafo.h \
    circulovertice.h \
    infomostrar.h \
    list.h \
    nodo.h \
    vertice.h \
    arista.h \
    button.h \
    arraylist.h \
    pila.h \
    cola.h \
    informationPrim.h

RC_ICONS = icono.ico
