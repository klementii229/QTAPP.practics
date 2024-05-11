#include "main.h"
#include "qlabel.h"
#include "qlineedit.h"


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

    if (isAdmin) {
        admpanel = new adminpanel;
        w->close();

        // Создание модели данных и загрузка таблицы "users"
        QSqlTableModel *tableModel = new QSqlTableModel(this, db);
        tableModel->setTable("users");
        tableModel->select();

        // Создание виджета QTableView и установка модели данных
        QTableView *tableView = new QTableView;
        tableView->setModel(tableModel);

        // Создание кнопок для добавления и удаления пользователей
        QPushButton *addButton = new QPushButton("Добавить пользователя");
        QPushButton *deleteButton = new QPushButton("Удалить пользователя");

        // Обработка нажатий кнопок
        connect(addButton, &QPushButton::clicked, this, &MainApp::AddUser);
        connect(deleteButton, &QPushButton::clicked, this, &MainApp::DeleteUser);

        // Создание вертикального layout для кнопок и QTableView
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(addButton);
        layout->addWidget(deleteButton);
        layout->addWidget(tableView);

        // Установка стиля для кнопок
        addButton->setStyleSheet(
            "QPushButton {"
            "    background-color: #2980b9;"
            "    color: #fff;"
            "    border: none;"
            "    padding: 15px 32px;"
            "    text-align: center;"
            "    text-decoration: none;"
            "    display: inline-block;"
            "    font-size: 16px;"
            "    cursor: pointer;"
            "}"
            "QPushButton:hover {"
            "    background-color: #3498db;"
            "}"
            "QPushButton:pressed {"
            "    background-color: #2471a3;"
            "}");

        deleteButton->setStyleSheet(
            "QPushButton {"
            "    background-color: #e74c3c;"
            "    color: #fff;"
            "    border: none;"
            "    padding: 15px 32px;"
            "    text-align: center;"
            "    text-decoration: none;"
            "    display: inline-block;"
            "    font-size: 16px;"
            "    cursor: pointer;"
            "}"
            "QPushButton:hover {"
            "    background-color: #c0392b;"
            "}"
            "QPushButton:pressed {"
            "    background-color: #a93226;"
            "}");

        // Установка стиля для таблицы
        tableView->setStyleSheet("background-color: #f2f2f2; border: 1px solid #ddd; border-collapse: collapse;");

        // Установка заголовков столбцов
        tableModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        tableModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Login"));
        tableModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Password"));

        // Установка ширины столбцов
        tableView->setColumnWidth(0, 50);
        tableView->setColumnWidth(1, 150);
        tableView->setColumnWidth(2, 150);

        // Установка высоты строк
        tableView->setRowHeight(0, 30);
        tableView->setRowHeight(1, 30);
        tableView->setRowHeight(2, 30);

        // Установка отображения данных
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        // Установка layout в центральный виджет административной панели
        admpanel->setCentralWidget(new QWidget);
        admpanel->centralWidget()->setLayout(layout);

        admpanel->show();
    } else {
        userpanel = new UserPanel;
        w->close();
        userpanel->show();
    }
}





void MainApp::AddUser()
{
    // Создание диалогового окна для ввода данных нового пользователя
    // Создание диалогового окна для ввода данных нового пользователя
    QDialog *dialog = new QDialog(admpanel);
    dialog->setWindowTitle("Добавить пользователя");

    QVBoxLayout *layout = new QVBoxLayout;
    QLineEdit *loginEdit = new QLineEdit;
    QLineEdit *passwordEdit = new QLineEdit;
    QPushButton *okButton = new QPushButton("OK");

    layout->addWidget(new QLabel("Логин:"));
    layout->addWidget(loginEdit);
    layout->addWidget(new QLabel("Пароль:"));
    layout->addWidget(passwordEdit);
    layout->addWidget(okButton);

    dialog->setLayout(layout);

    // Обработка нажатия кнопки "OK"
    connect(okButton, &QPushButton::clicked, [=]() {
        QString login = loginEdit->text();
        QString password = passwordEdit->text();

        // Выполнение SQL-запроса для добавления нового пользователя
        QSqlQuery query(db);
        query.prepare("INSERT INTO users (login, password) VALUES (:login, :password)");
        query.bindValue(":login", login);
        query.bindValue(":password", password);

        if (query.exec()) {
            // Обновление данных в QTableView
            QSqlTableModel *tableModel = qobject_cast<QSqlTableModel*>(admpanel->tableView->model());
            if (tableModel) {
                tableModel->select();
            }
            dialog->accept();
        } else {
            QMessageBox::warning(dialog, "Ошибка", "Не удалось добавить пользователя.");
        }
    });

    dialog->exec();
}

void MainApp::DeleteUser()
{
    // Получение выбранного пользователя из QTableView
    QModelIndex index = admpanel->tableView->currentIndex();
    int userId = index.sibling(index.row(), 0).data().toInt();

    // Выполнение SQL-запроса для удаления пользователя
    QSqlQuery query(db);
    query.prepare("DELETE FROM users WHERE id = :userId");
    query.bindValue(":userId", userId);

    if (query.exec()) {
        // Обновление данных в QTableView
        QSqlTableModel *tableModel = qobject_cast<QSqlTableModel*>(admpanel->tableView->model());
        if (tableModel) {
            tableModel->select();
        }
    } else {
        QMessageBox::warning(admpanel, "Ошибка", "Не удалось удалить пользователя.");
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
