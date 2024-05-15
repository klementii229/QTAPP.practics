#include "regestration.h"
#include "ui_regestration.h"

regestration::regestration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::regestration)
{
    ui->setupUi(this);
    QIcon qic1(":/image/app_icon");
    this->setWindowIcon(qic1);
}

void regestration::closeInitialWindow(initial* initialWindow) {

    initialWindow->close();
}

regestration::~regestration()
{
    delete ui;
}

void regestration::on_pushButton_2_clicked()
{
    this->close();
}


void regestration::on_pushButton_clicked()
{
    this->login = this->ui->lineEdit->text();
    this->password = this->ui->lineEdit_2->text();
    emit RegistrUser();
}

