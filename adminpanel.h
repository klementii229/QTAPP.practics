#pragma once

#include <QMainWindow>

namespace Ui {
class adminpanel;
}

class adminpanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminpanel(QWidget *parent = nullptr);
    ~adminpanel();

private:
    Ui::adminpanel *ui;
};
