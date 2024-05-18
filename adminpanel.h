#pragma once
#include <QMainWindow>
#include "ui_adminpanel.h"
namespace Ui {
class adminpanel;
}

class adminpanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminpanel(QWidget *parent = nullptr);
    ~adminpanel();
    Ui::adminpanel *uiadpanel;
    int row;

private slots:

    void on_delete_Button_clicked();
    void on_newuserButton_clicked();
    void on_tableView_clicked(const QModelIndex &index);
signals:
    void deleteUser();
    void addUser();
private:

};
