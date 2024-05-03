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
    // Закрываем только окно "initial", оставляя окно "regestration" открытым
    initialWindow->hide();

}

regestration::~regestration()
{
    delete ui;
}

void regestration::on_pushButton_2_clicked()
{
    this->close();
}

