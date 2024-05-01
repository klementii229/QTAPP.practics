#include "initial.h"
#include "./ui_initial.h"

initial::initial(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::initial)
{
    ui->setupUi(this);
}


initial::~initial()
{
    delete ui;
}


void initial::on_pushButton_2_clicked()
{
 emit openRegistrationWindow();
}

