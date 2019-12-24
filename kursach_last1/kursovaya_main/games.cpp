#include "games.h"
#include "ui_games.h"
#include <QProcess>
#include <iostream>
#include <QPainter>

#define Path_ProfilePhotos "build-kursovaya-Desktop_Qt_5_2_1_MinGW_32bit-Debug//ProfilePhotos//"

games::games(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::games)
{
    LeadersForm = new leaders();
    connect(this, &games::LeadersFormOpen, LeadersForm, &leaders::LoadLeadersTable);
    connect(this, &games::CheckGameResult, LeadersForm, &leaders::CheckGameResult);
    ui->setupUi(this);
}

void games::ChangePhoto(QPixmap photo)
{
    QString FileName = Path_ProfilePhotos + login;
    QFile PhotoFile(FileName);
    PhotoFile.open(QIODevice::WriteOnly);
    QDataStream Stream(&PhotoFile);
    Stream<<photo;
    PhotoFile.close();
}

void games::LoadPhoto()
{
    QPixmap* photo = new QPixmap;
    QString FileName = Path_ProfilePhotos + login;
    QFile PhotoFile(FileName);
    PhotoFile.open(QIODevice::ReadOnly);
    QDataStream Stream(&PhotoFile);
    Stream >> *photo;
    PhotoFile.close();
    ui->photo->setPixmap(*photo);
}

void games::PrepareGameFormToShow(QString loginPlayer)
{
    login = loginPlayer;
    SetStyleAndShowUsername();
    LoadPhoto();
}

void games::SetStyleAndShowUsername()
{
    SqlWork sql;
    ui->photo->setStyleSheet("QLabel{margin-left: 0px; border-radius: 5px; background: grey; color: #4A0C46;}");
    ui->nicknameLabel->setStyleSheet("QLabel{margin-left: 10px; border-radius: 25px; background: grey; color: #4A0C46;}");
    ui->nicknameLabel->setText(sql.GetUsername(login));
}

games::~games()
{
    delete ui;
}

void games::on_pushButton_clicked()
{
    QString filename =  QFileDialog::getOpenFileName(this, tr("Выберите фотографию профиля!"), QDir::currentPath(), tr("Картинки (*.png *.jpg *.bmp)"));
    if (!filename.isNull())
    {
        QPixmap *Photo = new QPixmap;
        Photo->load(filename);
        Photo->scaled(QSize(100, 100));
        ChangePhoto(*Photo);
        LoadPhoto();
    }
}

void games::on_pushButton_2_clicked()
{
    QByteArray Score1("0");
    QProcess DoodleJ;
    DoodleJ.start("Games0\\DoodleJ\\x64\\Debug\\DoodleJ.exe");
    DoodleJ.waitForFinished(-1);
    Score1 = DoodleJ.readAllStandardOutput();
    emit CheckGameResult(login, Doodle, Score1.toInt());
}

void games::on_pushButton_3_clicked()
{
    QByteArray Score2("0");
    QProcess Snake1;
    Snake1.start("Games0\\Snake\\Snake1\\x64\\Debug\\Snake1.exe");
    Snake1.waitForFinished(-1);
    Score2 = Snake1.readAllStandardOutput();
    emit CheckGameResult(login, Snake, Score2.toInt());
}

void games::on_pushButton_4_clicked()
{
    QByteArray Score3("0");
    QProcess Miner1;
    Miner1.start("Games0\\Miner\\x64\\Debug\\Miner.exe");
    Miner1.waitForFinished(-1);
    Score3 = Miner1.readAllStandardOutput();
    emit CheckGameResult(login, Miner, Score3.toInt());
}

void games::on_pushButton_5_clicked()
{
    LeadersForm->show();
    emit LeadersFormOpen();
}

void games::on_pushButton_6_clicked()
{
    emit ShowMainForm();
    this->close();
}
