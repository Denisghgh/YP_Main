#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QSqlError>
#include <set>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RegisterForm = new Register();
    GamesForm = new games();
    connect(RegisterForm, &Register::mainWindowOpen, this, &MainWindow::show);
    connect(this, &MainWindow::OpenGamesForm, GamesForm, &games::PrepareGameFormToShow);
    connect(GamesForm, &games::ShowMainForm, this, &MainWindow::CreateMainWindow);
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
    QString login;
    QString password;
    bool isOpen = false;
    {
        SqlWork sql;
        getLoginData(&login, &password);
        if (sql.IsExistingUser(login, password))
            isOpen = true;
        else
            ui->label_4->setText("Неверный логин или пароль!");
    }
    if (isOpen)
    {
        GamesForm->show();
        emit OpenGamesForm(login);
        this->close();
    }
}

void MainWindow::CreateMainWindow()
{
    this->show();
    this->ui->lineEdit_2->clear();
    this->ui->lineEdit->clear();
    this->ui->label_4->clear();
}
