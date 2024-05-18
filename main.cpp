#include "main.h"


MainApp::MainApp(int argc, char *argv[]) : QApplication(argc, argv) {
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("admin");

    w = new initial;
    w2 = new regestration;
    admpanel = new adminpanel;
    userpanel = new UserPanel;

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }

    w->show();
    w->setWindowTitle("Регистрация || Вход");
    QIcon qic1(":/image/app_icon");
    w->setWindowIcon(qic1);

    connect(w, &initial::openRegistrationWindow, this, &MainApp::openRegistrationWindow);
    connect(w2, &regestration::RegistrUser, this, &MainApp::PushRegistrButton);
    connect(w, &initial::LoginUser, this, &MainApp::PushLoginButton);
    connect(admpanel, &adminpanel::addUser, this, &MainApp::AddUser);
    connect(admpanel, &adminpanel::deleteUser, this, &MainApp::DeleteUser);
    connect(userpanel, &UserPanel::addLine, this, &MainApp::AddLine);
    connect(userpanel, &UserPanel::deleteLine, this, &MainApp::DeleteLine);

}



void MainApp::openRegistrationWindow() {
    w2->setWindowTitle("Регистрация");
    w2->show();
    w->hide();
}


void MainApp::PushRegistrButton()
{
    QString login = w2->login;
    QString password = w2->password;

    QSqlQuery query(db);
    query.prepare("INSERT INTO users (login, password) VALUES (:login, :password)");
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        QString error = query.lastError().text();
        QMessageBox::warning(w2, "Ошибка", error, QMessageBox::Ok);


    } else {
        qDebug() << "User registered successfully";
        QMessageBox::information(w2, "Успех!", "Вы успешно зарегестрировались!", QMessageBox::Ok);
    }
}


void MainApp::PushLoginButton()
{
    QString login = w->login;
    QString password = w->password;

    bool isAdmin = checkUserStatus(login, password);

    if (isAdmin) {
        w->close();

        QSqlQuery query1(db);
        query1.exec("SELECT * FROM users;");

        modal = new QSqlTableModel(this, db);
        modal->setTable("users");
        modal->select();
        admpanel->uiadpanel->tableView->setModel(modal);
        admpanel->show();

    } else if (!isAdmin) {
        w->close();
        QSqlQuery query1(db);
        query1.exec("SELECT * FROM warehouse;");
         modal = new QSqlTableModel(this, db);
        modal->setTable("warehouse");
        modal->select();

        userpanel->ui->tableView->setModel(modal);
        userpanel->show();
    }
}

void MainApp::DeleteUser() {
    modal->removeRow(admpanel->row);
    modal->select();
}

void MainApp::AddUser()
{
    modal->insertRow(modal->rowCount());
}

void MainApp::DeleteLine() {
    modal->removeRow(userpanel->row);
    modal->select();
}

void MainApp::AddLine()
{
    modal->insertRow(modal->rowCount());
}

bool MainApp::checkUserStatus(const QString& login, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT status FROM users WHERE login = :login AND password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);

    if (query.exec()) {
        if (query.next()) {
            bool isAdmin = query.value(0).toBool();
            return isAdmin;
        }
    }

    return false;
}


MainApp::~MainApp() {
    delete w;
    delete w2;
    delete userpanel;
    delete admpanel;
    db.close();
}



int main(int argc, char *argv[]) {


    MainApp app(argc, argv);

    return app.exec();

}
