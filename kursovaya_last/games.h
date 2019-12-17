#ifndef GAMES_H
#define GAMES_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QFileDialog>
#include "sqlwork.h"
#include "leaders.h"



namespace Ui {
class games;
}

class games : public QMainWindow
{
    Q_OBJECT

public:
    explicit games(QWidget *parent = 0);
    ~games();
    QString GetNickname();
    void ChangePhoto(QPixmap photo);
    void LoadPhoto();

public slots:
    void SavePlayerNickname(QString loginPlayer);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

signals:
    void LeadersFormOpen();
    void CheckGameResult(QString login, Games game, int score);

private:
    Ui::games *ui;
    QString login;
    leaders* LeadersForm;
};

#endif // GAMES_H
