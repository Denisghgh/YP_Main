#ifndef SQLWORK_H
#define SQLWORK_H

#include <QString>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QDebug>

class SqlWork
{
public:
    SqlWork();
    ~SqlWork();
    void AddNewUser(QString username, QString login, QString password);
    bool IsExistingUser(QString login, QString password);
    QString GetUsername(QString login);
private:
    QSqlDatabase database;
    QSqlQuery sqlquery;
};

#endif // SQLWORK_H
