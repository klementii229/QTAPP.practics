#pragma once


#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "initial.h"
#include "regestration.h"


class MainApp : public QApplication {
    Q_OBJECT
public:
    MainApp(int argc, char *argv[]);
    ~MainApp();
private:
    QSqlDatabase db;
    initial* w;
    regestration* w2;
private slots:
    void openRegistrationWindow();
};
