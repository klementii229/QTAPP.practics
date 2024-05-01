#pragma once
#include "regestration.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class initial;
}
QT_END_NAMESPACE

class initial : public QDialog
{
    Q_OBJECT

public:
    initial(QWidget *parent = nullptr);
    ~initial();

private slots:

    void on_pushButton_2_clicked();

private:
    Ui::initial *ui;
    regestration *window2;

};
