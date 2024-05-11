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
#include "adminpanel.h"
#include "userpanel.h"


class MainApp : public QApplication {
    Q_OBJECT
public:
    MainApp(int argc, char *argv[]);
    ~MainApp();
    bool checkUserStatus(const QString& login, const QString& password);
private:
    QSqlDatabase db;
    initial* w;
    regestration* w2;
    QSqlQuery query;
    adminpanel * admpanel;
    UserPanel *userpanel;
    QSqlTableModel * tablem;
private slots:
    void openRegistrationWindow();
    void PushRegistrButton();
    void PushLoginButton();

};
