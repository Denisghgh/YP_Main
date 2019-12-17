#ifndef LEADERS_H
#define LEADERS_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QTableWidgetItem>
#include "sqlwork.h"

enum Games {Doodle, Snake, Miner};

namespace Ui {
class leaders;
}

class leaders : public QMainWindow
{
    Q_OBJECT

public:
    explicit leaders(QWidget *parent = 0);
    ~leaders();

public slots:
    void LoadLeadersTable();
    void CheckGameResult(QString login, Games game, int score);

private slots:
    void on_pushButton_clicked();

private:
    Ui::leaders *ui;
};

#endif // LEADERS_H
