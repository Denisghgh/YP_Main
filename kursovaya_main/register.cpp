#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::GetRegisterData(QString *username, QString *login, QString *password)
{
    *username = ui->lineEdit->text();
    *login = ui->lineEdit_2->text();
    *password = ui->lineEdit_3->text();
}

void Register::FormClose(QWidget *form)
{
    form->close();
    emit mainWindowOpen();
}

void Register::on_pushButton_3_clicked()
{
    FormClose(this);
}

bool Register::CheckRegisterDataFormat(QString username, QString login, QString password)
{
    if (!(username == "") && !(login == "") && !(password == ""))
    {
        if (username.length() < 5)
        {
            ui->label_5->setText("Длина имени пользователя должна быть больше 5 символов!");
            return false;
        }
        if (login.length() < 5)
        {
            ui->label_5->setText("Длина логина должна быть больше 5 символов!");
            return false;
        }
        if (password.length() < 5)
        {
            ui->label_5->setText("Длина пароля должна быть больше 5 символов!");
            return false;
        }
        return true;
    }
    else
    {
        ui->label_5->setText("Заполните все поля!");
        return false;
    }
}

void Register::on_pushButton_2_clicked()
{
    QString username;
    QString login;
    QString password;
    {
        SqlWork sql;
        GetRegisterData(&username, &login, &password);
        if ((CheckRegisterDataFormat(username, login, password)) && !(sql.IsExistingUser(login, "")))
        {
            ui->label_5->setText("Вы успешно зарегестрировались!");
            sql.AddNewUser(username, login, password);
        }
        else
            ui->label_5->setText("Пользователь с таким логином уже зарегестрирован!");
    }
}

