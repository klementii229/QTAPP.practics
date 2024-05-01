
#include <QApplication>
#include "initial.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initial w;

    w.setWindowTitle("Регистрация || Вход");
    QIcon qic1 (":/image/app_icon");//где иконку храним
    w.setWindowIcon(qic1);//установка иконки

    w.show();

   return a.exec();

}
