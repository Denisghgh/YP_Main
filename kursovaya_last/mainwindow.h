#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QDebug>
#include "register.h"
#include "games.h"
#include "sqlwork.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void getLoginData(QString *login, QString *password); 
    bool IsExistingUser(QString login, QString password);

signals:
    void OpenGamesForm(QString login);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_lineEdit_2_windowIconTextChanged(const QString &iconText);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Register *RegisterForm;
    games *GamesForm;
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE","Connection");;
    QSqlQuery sqlquery;
};

#endif // MAINWINDOW_H
