#pragma once


#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include "initial.h"
#include "regestration.h"
#include <QMessageBox>



class MainApp : public QApplication {
    Q_OBJECT
public:
    MainApp(int argc, char *argv[]);
    ~MainApp();
private:
    QSqlDatabase db;
    initial* w;
    regestration* w2;
    QSqlQuery query;
private slots:
    void openRegistrationWindow();
    void PushRegistrButton();
    void PushLoginButton();//в 2 пока не сделаны

};
