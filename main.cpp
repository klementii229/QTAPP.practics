#include "initial.h"
#include "regestration.h"
#include <QApplication>

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("admin");

    // if (!db.open()) {
    //     qDebug() << "Error: " << db.lastError().text();

    // }
    // if (db.isOpen()) {
    //     qDebug() << "Подключились";
    // }




    initial* w = new initial;
    regestration* w2 = new regestration();


    // Установка заголовка и иконки для окна "initial"
    w->setWindowTitle("Регистрация || Вход");
    QIcon qic1(":/image/app_icon");
    w->setWindowIcon(qic1);



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
