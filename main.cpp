#include "initial.h"
#include "regestration.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    initial* w = new initial;

    // Установка заголовка и иконки для окна "initial"
    w->setWindowTitle("Регистрация || Вход");
    QIcon qic1(":/image/app_icon");
    w->setWindowIcon(qic1);

    // Создание объекта "regestration" и сохранение ссылки на него
    regestration* w2 = new regestration(w);

    // Соединение сигнала и слота для открытия окна "regestration" и закрытия окна "initial"
    QObject::connect(w, &initial::openRegistrationWindow, [w, w2]() {
        w2->setWindowTitle("Регистрация");
        w2->show();
        w->hide();
    });

    // Соединение сигнала закрытия окна "regestration" с завершением приложения
    QObject::connect(w2, &regestration::rejected, &a, &QApplication::quit);

    w->show();
    return a.exec();
}
