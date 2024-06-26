#pragma once


#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "initial.h"
#include "regestration.h"
#include <QMessageBox>
#include "adminpanel.h"
#include "userpanel.h"
#include "ui_userpanel.h"
#include <QTableView>
#include "QSqlTableModel"

class MainApp : public QApplication {
    Q_OBJECT
public:
    MainApp(int argc, char *argv[]);
    ~MainApp();
    bool checkUserStatus(const QString& login, const QString& password);
private:
    initial* w;
    regestration* w2;
    QSqlDatabase db;
    adminpanel * admpanel;
    UserPanel *userpanel;
    QSqlTableModel *modal;


private slots:
    void openRegistrationWindow();
    void PushRegistrButton();
    void PushLoginButton();
    void DeleteUser();
    void AddUser();
    void DeleteLine();
    void AddLine();
};
