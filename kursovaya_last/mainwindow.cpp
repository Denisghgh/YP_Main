#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QSqlError>
#include <set>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    RegisterForm = new Register();
    GamesForm = new games();

    connect(RegisterForm, &Register::mainWindowOpen, this, &MainWindow::show);
    connect(this, &MainWindow::OpenGamesForm, GamesForm, &games::SavePlayerNickname);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getLoginData(QString *login, QString *password){
    *login = *login + ui->lineEdit->text();
    *password = *password + ui->lineEdit_2->text();
}

void MainWindow::on_pushButton_2_clicked()
{
    RegisterForm->show();
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    QString login = "";
    QString password = "";
    {
        SqlWork sql;

        getLoginData(&login, &password);
        if (sql.IsExistingUser(login, password))
        {
            ui->label_4->setText("Success!");
            GamesForm->show();
            emit OpenGamesForm(login);
            this->close();
        }
        else
            ui->label_4->setText("Неверный логин или пароль!");
    }
}

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_2_windowIconTextChanged(const QString &iconText)
{

}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{

}
