#include "main.h"

MainApp::MainApp(int argc, char *argv[]) : QApplication(argc, argv) {
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("admin");

    w = new initial;
    w2 = new regestration;


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

    admpanel = new adminpanel;

    if (isAdmin) {

        w->close();
        QSqlQuery query (db);
        query.prepare("SELECT * FROM users");
        tablem = new QSqlTableModel(this, db);
        tablem->setTable("Список пользователей:");
        tablem->select();



        admpanel->show();
    } else {
        userpanel = new UserPanel;
        w->close();
        userpanel->show();
    }
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
    db.close();
}





int main(int argc, char *argv[]) {


    MainApp app(argc, argv);

    return app.exec();

}
