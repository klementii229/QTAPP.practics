#pragma once
#include <QTableView>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "qsqlquerymodel.h"
namespace Ui {
class adminpanel;
}

class adminpanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminpanel(QWidget *parent = nullptr);
    ~adminpanel();
    QSqlQuery query;
    QSqlDatabase db2;
private:
    Ui::adminpanel *ui;
};
