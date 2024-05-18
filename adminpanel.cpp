#include "adminpanel.h"
#include "ui_adminpanel.h"

adminpanel::adminpanel(QWidget *parent)
    : QMainWindow(parent)
    , uiadpanel(new Ui::adminpanel)
{
    uiadpanel->setupUi(this);
      uiadpanel->statusbar->showMessage("Чтоб удалить пользователя, нажмите на пустое место и кнопку удалить", 22000);
}
adminpanel::~adminpanel()
{
    delete uiadpanel;
}


void adminpanel::on_delete_Button_clicked()
{
    emit deleteUser();
     uiadpanel->statusbar->showMessage("Пользователь удален!", 6000);
}


void adminpanel::on_newuserButton_clicked()
{
    emit addUser();
    uiadpanel->statusbar->showMessage("Пользователь добавлен!", 6000);
}


void adminpanel::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

