#pragma once
#include <QDialog>
#include "initial.h"
namespace Ui {
class regestration;
}

class regestration : public QDialog
{
    Q_OBJECT

public:
    explicit regestration(QWidget *parent = nullptr);
    ~regestration();

public slots:

 void closeInitialWindow(initial* initialWindow);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::regestration *ui;
};
