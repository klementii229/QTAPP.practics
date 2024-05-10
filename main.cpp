#include "main.h"

MainApp::MainApp(int argc, char *argv[]) : QApplication(argc, argv) {
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("admin");

    w = new initial;
    w2 = new regestration;



    w->show();
    w->setWindowTitle("Регистрация || Вход");
    QIcon qic1(":/image/app_icon");
    w->setWindowIcon(qic1);

    connect(w, &initial::openRegistrationWindow, this, &MainApp::openRegistrationWindow);
}



void MainApp::openRegistrationWindow() {
    w2->setWindowTitle("Регистрация");
    w2->show();
    w->hide();
}





MainApp::~MainApp() {
    delete w;
    delete w2;
}





int main(int argc, char *argv[]) {

    MainApp app(argc, argv);

    return app.exec();

}
