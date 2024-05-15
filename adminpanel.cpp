#include "adminpanel.h"
#include "ui_adminpanel.h"

adminpanel::adminpanel(QWidget *parent)
    : QMainWindow(parent)
    , uiadpanel(new Ui::adminpanel)
{
    uiadpanel->setupUi(this);
}
adminpanel::~adminpanel()
{
    delete uiadpanel;
}


void adminpanel::on_delete_Button_clicked()
{
    emit deleteUser();
}


void adminpanel::on_newuserButton_clicked()
{
    emit addUser();
}


void adminpanel::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

