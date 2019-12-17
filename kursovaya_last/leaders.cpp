#include "leaders.h"
#include "ui_leaders.h"

#define Path_Score "build-kursovaya-Desktop_Qt_5_2_1_MinGW_32bit-Debug//score.txt"

leaders::leaders(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::leaders)
{
    ui->setupUi(this);
}

leaders::~leaders()
{
    delete ui;
}



QString getLine(QString login, Games game, int score)
{
    QString Result;
    switch(game)
    {
        case Doodle:
            Result = "DoodleJump " + login + " " + QString::number(score);
        break;
        case Snake:
            Result = "Snake " + login + " " + QString::number(score);
        break;
        case Miner:
            Result = "Miner " + login + " " + QString::number(score);
        break;
    };
    return Result;
}

void getData(QString line, Games* gameRet, int* scoreRet, QString* loginRet)
{
    QString game;
    QString login;
    QString score;
    int i = 0;
    while (line[i] != ' ')
    {
        game += line[i];
        i++;
    }
    i++;
    while (line[i] != ' ')
    {
        login += line[i];
        i++;
    }
    i++;
    while ((line[i] != ' ') && (i < line.size()))
    {
        score += line[i];
        i++;
    }
    if (game == "DoodleJump")
            *gameRet = Doodle;
    if (game == "Snake")
            *gameRet = Snake;
    if (game == "Miner")
            *gameRet = Miner;
    *scoreRet = score.toInt();
    *loginRet = login;
}

bool CompareResult(QString line, QString result, bool *Find)
{
    QString ResultLogin;
    QString LineLogin;
    Games ResultGame;
    Games LineGame;
    int ResultScore;
    int LineScore;

    getData(line, &LineGame, &LineScore, &LineLogin);
    getData(result, &ResultGame, &ResultScore, &ResultLogin);

    if ((ResultGame == LineGame) && (ResultLogin == LineLogin))
    {
        if (ResultScore > LineScore)
        {
            return true;
        }
        *Find = true;
    }
    return false;
}

void leaders::CheckGameResult(QString login, Games game, int score)
{
    QFile LeadersFile(Path_Score);
    QString GameResult = getLine(login, game, score);
    QStringList lines;
    if ((LeadersFile.exists())&&(LeadersFile.open(QIODevice::ReadOnly | QIODevice::Text)) && (!LeadersFile.atEnd()))
    {
        while (!LeadersFile.atEnd())
        {
            lines << LeadersFile.readLine();
        }
        LeadersFile.close();
        int i = 0;
        int size = lines.size();
        bool Stop = false;
        foreach (QString s, lines)
        {
            if (!CompareResult(s, GameResult, &Stop))
            {
                i++;
                if (!Stop)
                {
                    if ((i == size) && (LeadersFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)))
                    {
                        lines.insert(size, GameResult);
                        QTextStream stream(&LeadersFile);
                        for (i = 0; i < lines.size(); i++)
                        {
                            if (i != lines.size()-1)
                                stream << lines.at(i).trimmed() << '\r' << '\n';
                            else
                                stream << lines.at(i).trimmed();
                        }
                        break;
                    }
                    LeadersFile.close();
                }
            }
            else
            {
                if (LeadersFile.open(QIODevice::WriteOnly | QIODevice::Truncate| QIODevice::Text))
                {
                    lines.removeAt(i);
                    lines.insert(i, GameResult);
                    QTextStream stream(&LeadersFile);
                    for (i = 0; i < lines.size(); i++)
                    {
                        if (i != lines.size()-1)
                            stream << lines.at(i).trimmed() << '\r' << '\n';
                        else
                            stream << lines.at(i).trimmed();
                    }
                    break;
                }
                LeadersFile.close();
            }
        }
    }
    else
    {
        LeadersFile.close();
        if (LeadersFile.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(&LeadersFile);
            stream << GameResult;
            LeadersFile.close();
        }
    }
    // вывод в list view
}

void leaders::LoadLeadersTable()
{
    QFile LeadersFile(Path_Score);
    QStringList lines;
    if ((LeadersFile.exists())&&(LeadersFile.open(QIODevice::ReadOnly)) && (!LeadersFile.atEnd()))
    {
        while (!LeadersFile.atEnd())
        {
            lines << LeadersFile.readLine();
        }
        LeadersFile.close();
        QString login;
        int score;
        Games game;
        LeadersFile.close();
        foreach (QString s, lines)
        {
            int i;
            getData(s, &game, &score, &login);
            SqlWork sql;
            QString username = sql.GetUsername(login);
            bool Find = false;
            for (i = 0; i < ui->tableWidget->rowCount(); i++)
            {
                QString header = ui->tableWidget->verticalHeaderItem(i)->text();
                if (header == username)
                {
                    Find = true;
                    break;
                }
            }
            if (Find)
            {
                QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(score));
                switch (game)
                {
                    case Doodle:
                        ui->tableWidget->setItem(i, 0, newItem);
                    break;
                    case Snake:
                        ui->tableWidget->setItem(i, 1, newItem);
                    break;
                    case Miner:
                        ui->tableWidget->setItem(i, 2, newItem);
                    break;
                };
            }
            else
            {
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
                QTableWidgetItem *header = new QTableWidgetItem(username);
                ui->tableWidget->setVerticalHeaderItem(ui->tableWidget->rowCount()-1, header);
                QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(score));
                switch (game)
                {
                    case Doodle:
                        ui->tableWidget->setItem(i, 0, newItem);
                    break;
                    case Snake:
                        ui->tableWidget->setItem(i, 1, newItem);
                    break;
                    case Miner:
                        ui->tableWidget->setItem(i, 2, newItem);
                    break;
                };
            }

        }
    }

    /*for(int row = 0; row != ui->tableWidget->rowCount(); ++row){
        for(int column = 0; column != ui->tableWidget->columnCount(); ++column) {
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg((row+1)*(column+1)));
            ui->tableWidget->setItem(row, column, newItem);
        }
    }*/
}

void leaders::on_pushButton_clicked()
{
    this->close();
}
