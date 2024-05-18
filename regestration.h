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
    QString login;
    QString password;
public slots:

 void closeInitialWindow(initial* initialWindow);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
private:
    Ui::regestration *ui;
signals:
    void RegistrUser();
};
