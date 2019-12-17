#include "sqlwork.h"

#define Path_users_db "build-kursovaya-Desktop_Qt_5_2_1_MinGW_32bit-Debug\\sqlite\\users.db"


SqlWork::SqlWork()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(Path_users_db);
}

SqlWork::~SqlWork()
{
}

void SqlWork::AddNewUser(QString username, QString login, QString password)
{
    if (database.open())
    {
        sqlquery = QSqlQuery(database);
        sqlquery.prepare("INSERT INTO users (nickname, login, password) VALUES (:username,:login,:password);");
        sqlquery.bindValue(":username", username);
        sqlquery.bindValue(":login", login);
        sqlquery.bindValue(":password", password);
        sqlquery.exec();
        database.close();
    }
}

bool SqlWork::IsExistingUser(QString login, QString password)
{
    QString DBlogin;
    QString DBpassword;

    if (database.open())
    {
        sqlquery = QSqlQuery(database);
        sqlquery.exec("SELECT * FROM users;");
        while (sqlquery.next())
        {
            DBlogin = sqlquery.value(2).toString();
            if (password != "")
            {
                DBpassword = sqlquery.value(3).toString();
                if ((login == DBlogin) && (password == DBpassword))
                {
                    return true;
                    break;
                }
            }
            else
                if (login == DBlogin)
                {
                    return true;
                    break;
                }
        }
        return false;
        database.close();
    }
    return false;
}

QString SqlWork::GetUsername(QString login)
{
    QString username;

    if (database.open())
    {
        sqlquery = QSqlQuery(database);
        sqlquery.prepare("SELECT nickname FROM users WHERE login = :login;");
        sqlquery.bindValue(":login", login);
        sqlquery.exec();
        sqlquery.first();
        username = sqlquery.value(0).toString();
        database.close();
    }
    return username;
}
