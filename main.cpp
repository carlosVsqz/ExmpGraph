#include "dragwidget.h"
#include <QApplication>
#include <QHBoxLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DragWidget w;
    w.setGeometry(0,30,1600,720);
    w.show();

    return a.exec();

    //QApplication a(argc, argv);

    QWidget mainWidget;
    QHBoxLayout *horizontalLayout = new QHBoxLayout(&mainWidget);
    horizontalLayout->addWidget(new DragWidget);
    mainWidget.setWindowTitle("Juego de Grafos");
    mainWidget.show();
    return a.exec();

}
