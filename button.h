#ifndef BUTTON_H
#define BUTTON_H
#include<QPushButton>

class Button: public QPushButton
{
        Q_OBJECT
    public:
    Button(QWidget *parent = nullptr);
    protected:
    public slots:
     //   void Presioonaar();
     //   void mouseMoveEvent();
     //   void clickear();
};

#endif // BUTTON_H
