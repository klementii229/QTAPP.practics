#include "userpanel.h"
#include "ui_userpanel.h"

UserPanel::UserPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UserPanel)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Чтоб удалить пользователя, нажмите на пустое место и кнопку удалить", 22000);
}

UserPanel::~UserPanel()
{
    delete ui;
}

void UserPanel::on_addButtom_clicked()
{
    emit addLine();

    ui->statusbar->showMessage("Объект был добавлен!", 6000);
}


void UserPanel::on_deleteButton_clicked()
{
    emit deleteLine();
    ui->statusbar->showMessage("Объект был удален!", 6000);
}


void UserPanel::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

