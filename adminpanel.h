#pragma once
#include <QMainWindow>
#include "ui_adminpanel.h"
namespace Ui {
class adminpanel;
}

class adminpanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminpanel(QWidget *parent = nullptr);
    ~adminpanel();
    Ui::adminpanel *uiadpanel;

private:

};
