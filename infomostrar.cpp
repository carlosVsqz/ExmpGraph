#include "infomostrar.h"

infoMostrar::infoMostrar(QWidget *parent):QLabel(parent)
{
    this->nombre="";
}

void infoMostrar::mostrando(string nombre)
{
    texto = nombre.c_str();
    this->setGeometry(300,10,300,70);
    this->setText(texto);
    this->show();
}
