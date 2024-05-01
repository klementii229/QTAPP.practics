#pragma once
#include <QDialog>
namespace Ui {
class regestration;
}

class regestration : public QDialog
{
    Q_OBJECT

public:
    explicit regestration(QWidget *parent = nullptr);
    ~regestration();

private slots:



private:
    Ui::regestration *ui;

};
