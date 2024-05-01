#include "regestration.h"
#include "ui_regestration.h"

regestration::regestration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::regestration)
{
    ui->setupUi(this);


}

void regestration::closeInitialWindow(initial* initialWindow) {
    // Закрываем только окно "initial", оставляя окно "regestration" открытым
    initialWindow->hide();
}

regestration::~regestration()
{
    delete ui;

}
