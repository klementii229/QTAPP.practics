#include "adminpanel.h"
#include "ui_adminpanel.h"

adminpanel::adminpanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adminpanel)
{
    ui->setupUi(this);
}
adminpanel::~adminpanel()
{
    delete ui;
}
