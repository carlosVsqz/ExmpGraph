#include "dragwidget.h"
#include <iostream>
#include <stdlib.h>

DragWidget::DragWidget(QWidget *parent)
    : QFrame(parent)
{    
    this->grafoActual="Normal";
    this->listaCirculosGrafo = new Lista<circuloVertice*>();
    this->grafoPrincipal = new Grafo();
    this->imprimir = grafoPrincipal;
    setMinimumSize(1280,720);
    setFrameStyle(QFrame::Raised | QFrame::WinPanel);
    setAcceptDrops(true);
    mostrarInfo = new infoMostrar(this);
    this->nombreInicio = new QTextEdit(this);
    this->nombreFin = new QTextEdit(this);
    nombreInicio->setGeometry(100,5,400,24);
    nombreInicio->setPlaceholderText("Vertices");
    nombreFin->setGeometry(100,35,400,24);
    nombreFin->setPlaceholderText("adyacencias");
}

void DragWidget::handleSubmit()
{
    if(this->imprimir!=this->grafoPrincipal)
    {
        mensaje.setText("Tiene que estar en el grafo principal para habilitar esta funcion");
        mensaje.show();
        return;
    }else{
        this->grafoDijkstra = new Grafo();
        string nombrep = (this->nombreInicio->toPlainText()).toStdString();

        if(this->grafoPrincipal->listaVertices->getSize()==0)
        {
            mensaje.setText("Necesita tener por lo menos un vertice para poder ejecutar Dijkstra");
            mensaje.show();
            return;
        }else if(nombrep=="")
        {
            mensaje.setText("Ingrese un vertice inicial para ejecutar Dijkstra");
            mensaje.show();
            return;
        }

        if(!this->grafoPrincipal->existeVertice(nombrep))
        {
            mensaje.setText("Ingrese un nombre de vertice existente para poder ejecutar Dijkstra");
            mensaje.show();
            return;
        }

        arrayD= new ArrayListP<Vertice*>();
        if(this->grafoPrincipal->listaVertices->getSize()==0)
            return;
        bool visitado[this->grafoPrincipal->listaVertices->getSize()];
        int peso[this->grafoPrincipal->listaVertices->getSize()];
        Nodo<Vertice*>* temporal = this->grafoPrincipal->listaVertices->getFirst();
        Vertice*nuevo;

        while(temporal!=nullptr)
        {
            nuevo= new Vertice();
            nuevo->dibujado=temporal->valor->dibujado;
            nuevo->nombre=temporal->valor->nombre;
            arrayD->guardar(nuevo);
            temporal=temporal->siguiente;
        }

        int max = 2147483647;
        for(int i=0;i<this->grafoPrincipal->listaVertices->getSize();i++)
        {
            visitado[i]=false;
            peso[i]=max;
        }

        Vertice* caminoInicio = new Vertice();
        caminoInicio = this->grafoPrincipal->getvertice(nombrep);
        int pos=arrayD->getPos(caminoInicio);
        visitado[pos]=true;
        Nodo<Arista*>* actualizando;
        Vertice*uGrafoPrincipalU;
        Vertice* uU = new Vertice();
        Vertice* buscar2 = new Vertice();
        int posFinal;
        actualizando=caminoInicio->aristas->getFirst();

        while(actualizando!=nullptr)
        {
            uU->nombre=actualizando->valor->verticeFinal->nombre;
            posFinal=this->arrayD->getPos(uU);
            peso[posFinal]=actualizando->valor->peso;
            actualizando=actualizando->siguiente;
        }

        int menor=pos,posicionfinal,pesoNuevo,peso1,peso2;
        Nodo<Arista*>* aristaRelajadora;

        for(int i=0;i<this->grafoPrincipal->listaVertices->getSize();i++)
        {
            for(int j=0;j<this->grafoPrincipal->listaVertices->getSize();j++)
            {
                peso1=peso[j];
                for(int k=0;k<this->grafoPrincipal->listaVertices->getSize();k++)
                {
                    peso2=peso[k];
                    if(peso1<peso2 && !visitado[j])
                    {
                        menor=j;
                    }
                }
            }

            uU=arrayD->buscar(menor);
            visitado[menor]=true;

            uGrafoPrincipalU=this->grafoPrincipal->getvertice(uU->nombre);
            aristaRelajadora=uGrafoPrincipalU->aristas->getFirst();

            while(aristaRelajadora!=nullptr)
            {
                buscar2->nombre=aristaRelajadora->valor->verticeFinal->nombre;
                posicionfinal=arrayD->getPos(buscar2);
                pesoNuevo=peso[menor]+aristaRelajadora->valor->peso;
                if(peso[posicionfinal]>pesoNuevo)
                {
                    peso[posicionfinal]=pesoNuevo;
                }
                aristaRelajadora= aristaRelajadora->siguiente;
            }
        }

        Vertice* paraCopiar,*finalCopiar,*devuelto;

        for(int i=0; i<this->grafoPrincipal->listaVertices->getSize();i++)
        {
            paraCopiar=arrayD->buscar(i);
            this->grafoDijkstra->insertarVertice(paraCopiar->nombre);
            devuelto=this->grafoDijkstra->getvertice(paraCopiar->nombre);
            devuelto->dibujado=paraCopiar->dibujado;
        }

        paraCopiar=this->grafoDijkstra->getvertice(nombrep);
        for(int i=0; i<this->grafoPrincipal->listaVertices->getSize();i++)
        {
            if(peso[i]!=max)
            {
                finalCopiar=arrayD->buscar(i);
                this->grafoDijkstra->insertarArista(paraCopiar->nombre,finalCopiar->nombre,peso[i]);
            }
        }

        this->grafoActual="Dijkstra";
        this->imprimir=grafoDijkstra;
        update();
    }
}

void DragWidget::handleSubmitDelet()
{
    this->grafoActual="Normal";
    this->imprimir=this->grafoPrincipal;
    this->update();
}

void DragWidget::setText()
{
    this->nombreInicio->setText("");
    this->nombreFin->setText("");
}

void DragWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    string s = (this->nombreInicio->toPlainText()).toStdString();
    string ady = (this->nombreFin->toPlainText()).toStdString();
    //string s = "a,b,c,d,e,f,g,h,i,j,k,l,m,o,p,q,r,s,t,u,v,w,x,y,z,";
    //string ady = "ab,cd,bg,cb,";
    int init, end, x, y = 0;
    while( end = s.find(",", init), end >= 0 )
    {
      string result = s.substr(init, end - init);

      int iX = 100;
      int iY = 100;
      this->grafoPrincipal->insertarVertice(result);
      Vertice* nuevo = this->grafoPrincipal->getvertice(result);
      if(nuevo==nullptr || result=="") return;
      circuloVertice* c= new circuloVertice();

      c->createVertice(result,(iX+x),(iY+y));
      c->representavertice=nuevo;
      nuevo->dibujado=c;
      this->listaCirculosGrafo->guardar(c);
      this->update();
      y = y+200;
      if(y == 800){x = x+200; y = 0;}
      init = end + 1;
    }

    std::string delimiter = ",";
    size_t pos = 0;
    string token;
    while ((pos = ady.find(delimiter)) != std::string::npos) {
        token = ady.substr(0, pos);
        string a = token.substr(0,1);
        string b = token.substr(1,1);
        Vertice* primero = this->grafoPrincipal->getvertice(a);
        Vertice* segundo = this->grafoPrincipal->getvertice(b);
        grafoPrincipal->insertarArista(primero,segundo,1);
        this->update();
        ady.erase(0, pos + delimiter.length());
    }
    this->setText();
    nombreInicio->setPlaceholderText("Inicio");
    nombreFin->setPlaceholderText("Fin");
}

void DragWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint pos=event->pos();
    if(pos.x()>945 && pos.x()<1005 && pos.y()>35 && pos.y()<55)
    {
        this->handleSubmit();
    }else if(pos.x()>1035 && pos.x()<1095 && pos.y()>35 && pos.y()<55)
    {
        this->handleSubmitDelet();
    }else if(pos.x()>220 && pos.x()<280 && pos.y()>3 && pos.y()<23)
    {
    }else if(pos.x()>10 && pos.x()<60 && pos.y()>35 && pos.y()<55)
    {
        this->grafoToPrincipal();
    }else if(pos.x()>90 && pos.x()<150 && pos.y()>35 && pos.y()<55)
    {
    }
}

void DragWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawRect(945,35,60,20);
    painter.drawText(955,50,"Comenzar");
    painter.drawRect(1035,35,60,20);
    painter.drawText(1045,50,"Eliminar");

    int x1,x2,y1,y2,textX,textY;
    painter.setPen(Qt::red);    
    Nodo<Vertice*>* temporal = this->imprimir->listaVertices->getFirst();
    Nodo<Arista*>* aristaTemporal;
    double ang1;
    while(temporal!=nullptr)
    {
        aristaTemporal = temporal->valor->aristas->getFirst();
        while(aristaTemporal!=nullptr)
        {
            painter.setPen(Qt::black);
            x1=temporal->valor->dibujado->x+25;
            y1=temporal->valor->dibujado->y+25;
            x2= aristaTemporal->valor->verticeFinal->dibujado->x+25;
            y2= aristaTemporal->valor->verticeFinal->dibujado->y+25;
            textX=(x1+x2)/2;
            textY=(y1+y2)/2;
            if(x1!=x2 || y1!=y2)
            {
                ang1=qAtan2((y2-y1),(x2-x1));
                QPoint ellipse1,ellipse2;
                ellipse1.setX((x2-25*qCos(ang1)));
                ellipse1.setY((y2-25*qSin(ang1)));
                ellipse2.setX((x1+25*qCos(ang1)));
                ellipse2.setY((y1+25*qSin(ang1)));
                painter.drawLine(x1,y1,x2,y2);
                painter.setPen(Qt::red);
                painter.setBrush(Qt::red);
                painter.drawEllipse(ellipse1,5,5);
                QString name= QString::fromStdString(to_string(aristaTemporal->valor->peso));
                painter.setPen(Qt::black);
                painter.drawText(textX+2,textY-2,name);
            }
            aristaTemporal = aristaTemporal->siguiente;
        }
        temporal = temporal->siguiente;
    }

    temporal=this->imprimir->listaVertices->getFirst();
    while(temporal!=nullptr)
    {
        painter.setPen(Qt::blue);
        painter.setBrush(Qt::gray);
        painter.drawEllipse(temporal->valor->dibujado->x,temporal->valor->dibujado->y,50,50);
        painter.setPen(Qt::black);
        QString name= QString::fromStdString(temporal->valor->dibujado->name);
        painter.drawText(temporal->valor->dibujado->x-12.5,temporal->valor->dibujado->y-12.5,name);

        temporal=temporal->siguiente;
    }
}

void DragWidget::grafoToPrincipal()
{
    this->grafoActual="Normal";
    this->imprimir=this->grafoPrincipal;
    this->update();
}

void DragWidget::grafoToDjikstra()
{

}

void DragWidget::copyGraphto(Grafo* nuevo)
{
     Nodo<Vertice*>* temporal = this->grafoPrincipal->listaVertices->getFirst();
     Nodo<Arista*>* temporalA;
     Vertice* circ;
     while(temporal!=nullptr)
     {
         nuevo->insertarVertice(temporal->valor->nombre);
         circ=nuevo->getvertice(temporal->valor->nombre);
         circ->dibujado=temporal->valor->dibujado;
         temporal=temporal->siguiente;
     }

     temporal = this->grafoPrincipal->listaVertices->getFirst();

     while(temporal!=nullptr)
     {
         temporalA =temporal->valor->aristas->getFirst();
         while(temporalA!=nullptr)
         {
             nuevo->insertarArista(temporalA->valor->verticeInicial->nombre,temporalA->valor->verticeFinal->nombre,temporalA->valor->peso);
             temporalA = temporalA->siguiente;
         }
         temporal=temporal->siguiente;
     }
     imprimir=nuevo;
}
