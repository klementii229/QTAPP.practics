#pragma once
#include "qsqltablemodel.h"
#include <QTableView>
#include <QMainWindow>

namespace Ui {
class adminpanel;
}

class adminpanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminpanel(QWidget *parent = nullptr);
    ~adminpanel();
     QTableView *tableView;
private:
    Ui::adminpanel *ui;
};
