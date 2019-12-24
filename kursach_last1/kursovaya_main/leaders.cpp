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

bool CompareFileAndGameResult(QString line, QString result, bool *Find)
{
    QString ResultLogin;
    QString LineLogin;
    Games ResultGame;
    Games LineGame;
    int ResultScore;
    int ResultStringListcore;

    getData(line, &LineGame, &ResultStringListcore, &LineLogin);
    getData(result, &ResultGame, &ResultScore, &ResultLogin);
    if ((ResultGame == LineGame) && (ResultLogin == LineLogin))
    {
        if (ResultScore > ResultStringListcore)
        {
            return true;
        }
        *Find = true;
    }
    return false;
}

bool isOpenToReadCompleteFile(QFile *LeadersFile)
{
    if ((*LeadersFile).exists())
        if ((*LeadersFile).open(QIODevice::ReadOnly | QIODevice::Text))
        {
            if (!(*LeadersFile).atEnd())
            {
                return true;
            }
            else
                (*LeadersFile).close();
        }
    return false;
}

bool isOpenToRewriteFile(QFile *LeadersFile)
{
    return ((*LeadersFile).open(QIODevice::WriteOnly | QIODevice::Truncate| QIODevice::Text));
}

bool isOpenToAppendFile(QFile *LeadersFile)
{
    return ((*LeadersFile).open(QIODevice::Append | QIODevice::Text));
}

void ReadDataToResultStringList(QFile *LeadersFile, QStringList *FileResults)
{
    while (!(*LeadersFile).atEnd())
    {
        *FileResults << (*LeadersFile).readLine();
    }
    (*LeadersFile).close();
}

void WriteResultStringListInFile(QFile *LeadersFile, QStringList *NewFileResults)
{
    QTextStream stream(LeadersFile);
    for (int i = 0; i < (*NewFileResults).size(); i++)
    {
        if (i != (*NewFileResults).size()-1)
            stream << (*NewFileResults).at(i).trimmed() << '\r' << '\n';
        else
            stream << (*NewFileResults).at(i).trimmed();
    }
}

void WriteSingleResultInFile(QFile *LeadersFile, QString GameResult)
{
    QTextStream stream(LeadersFile);
    stream << GameResult;
}

void leaders::CheckGameResult(QString login, Games game, int score)
{
    QFile LeadersFile(Path_Score);
    QString GameResult = getLine(login, game, score);
    QStringList ResultStringList;
    int i = 0;
    int SizeOfResultStringList;
    bool isFind = false;

    if (isOpenToReadCompleteFile(&LeadersFile))
    {
        ReadDataToResultStringList(&LeadersFile, &ResultStringList);
        SizeOfResultStringList = ResultStringList.size();
        foreach (QString FileResult, ResultStringList)
        {
            if (!CompareFileAndGameResult(FileResult, GameResult, &isFind))
            {
                i++;
                if ((!isFind) && (i == SizeOfResultStringList) && isOpenToRewriteFile(&LeadersFile))
                {
                    ResultStringList.insert(SizeOfResultStringList, GameResult);
                    WriteResultStringListInFile(&LeadersFile, &ResultStringList);
                    LeadersFile.close();
                    break;
                }
            }
            else
                if (isOpenToRewriteFile(&LeadersFile))
                {
                    ResultStringList.removeAt(i);
                    ResultStringList.insert(i, GameResult);
                    WriteResultStringListInFile(&LeadersFile, &ResultStringList);
                    LeadersFile.close();
                    break;
                }
        }
    }
    else
        if (isOpenToAppendFile(&LeadersFile))
        {
            WriteSingleResultInFile(&LeadersFile, GameResult);
            LeadersFile.close();
        }
}

void leaders::WriteScoreToTableWidget(int score, int i, Games GameType)
{
    QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(score));
    switch (GameType)
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

int leaders::ReturnIndexOfMatchUsernameAndTableHeader(QString username, bool *isFind)
{
    int i = 0;
    while (i < ui->tableWidget->rowCount())
    {
        QString TableHeader = ui->tableWidget->verticalHeaderItem(i)->text();
        if (TableHeader == username)
        {
            *isFind = true;
            break;
        }
        i++;
    }
    return i;
}

void leaders::AddRowAndSetNewUsernameAsHeader(QString username)
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    QTableWidgetItem *TableHeader = new QTableWidgetItem(username);
    ui->tableWidget->setVerticalHeaderItem(ui->tableWidget->rowCount()-1, TableHeader);
}

void leaders::LoadLeadersTable()
{
    QFile LeadersFile(Path_Score);
    QStringList ResultStringList;
    QString login;
    QString username;
    int score;
    Games GameType;
    SqlWork sql;
    bool isFind;

    if (isOpenToReadCompleteFile(&LeadersFile))
    {
        ReadDataToResultStringList(&LeadersFile, &ResultStringList);
        foreach (QString s, ResultStringList)
        {
            getData(s, &GameType, &score, &login);
            username = sql.GetUsername(login);
            isFind = false;
            int i = ReturnIndexOfMatchUsernameAndTableHeader(username, &isFind);
            if (isFind)
                WriteScoreToTableWidget(score, i, GameType);
            else
            {
                AddRowAndSetNewUsernameAsHeader(username);
                WriteScoreToTableWidget(score, i, GameType);
            }
        }
    }
}

void leaders::on_pushButton_clicked()
{
    this->close();
}
