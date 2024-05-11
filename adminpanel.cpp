#include "adminpanel.h"
#include "ui_adminpanel.h"

adminpanel::adminpanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adminpanel)
{
    ui->setupUi(this);
    this->setWindowTitle("Панель администратора");//иконку я уже поставил
     tableView = new QTableView;

}

adminpanel::~adminpanel()
{
    delete ui;
}
