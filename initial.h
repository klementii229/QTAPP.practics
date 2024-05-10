#pragma once
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
    QString login;
    QString password;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
private:
    Ui::initial *ui;
signals:
    void openRegistrationWindow();
    void LoginUser();
};
