#pragma once
#include <QTableView>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
namespace Ui {
class adminpanel;
}

class adminpanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminpanel(QWidget *parent = nullptr);
    ~adminpanel();
private:
    Ui::adminpanel *ui;
};
