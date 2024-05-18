#pragma once

#include <QMainWindow>

namespace Ui {
class UserPanel;
}

class UserPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserPanel(QWidget *parent = nullptr);
    ~UserPanel();
    int row;
        Ui::UserPanel *ui;

private slots:
    void on_addButtom_clicked();

    void on_deleteButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:

signals:
    void addLine();
    void deleteLine();
};
