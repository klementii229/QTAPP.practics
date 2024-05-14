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
