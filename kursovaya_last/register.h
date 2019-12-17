#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include "sqlwork.h"

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();
    void FormClose(QWidget *form);
    void GetRegisterData(QString *username, QString *login, QString *password);
    bool CheckRegisterDataFormat(QString username, QString login, QString password);

signals:
    void mainWindowOpen();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Register *ui;
    bool Check;
};

#endif // REGISTER_H
