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
    QFile PhotoFile(FileName); //Создаем объект файла.
    PhotoFile.open(QIODevice::WriteOnly); //Открываем только для записи.
    QDataStream Stream(&PhotoFile); //Создаем поток, записывающий в наш файл.
    Stream<<photo; //Записываем в поток наш скриншот.
    PhotoFile.close(); //После записи закрываем файл.
}

void games::LoadPhoto()
{
    QPixmap* photo = new QPixmap;
    QString FileName = Path_ProfilePhotos + login;
    QFile PhotoFile(FileName);//Создаем объект файла.
    PhotoFile.open(QIODevice::ReadOnly); //Открываем только для чтения.
    QDataStream Stream(&PhotoFile); //Создаем поток, читающий файл.
    Stream >> *photo; //Читаем из потока
    PhotoFile.close(); //После записи закрываем файл.
    ui->photo->setPixmap(*photo);
}

void games::SavePlayerNickname(QString loginPlayer)
{
    SqlWork sql;

    login = loginPlayer;
    ui->photo->setStyleSheet("QLabel{margin-left: 0px; border-radius: 5px; background: grey; color: #4A0C46;}");
    ui->nicknameLabel->setStyleSheet("QLabel{margin-left: 10px; border-radius: 25px; background: grey; color: #4A0C46;}");
    ui->nicknameLabel->setText(sql.GetUsername(login));
    LoadPhoto();
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
        QSize PhotoSize(100, 100);
        QPixmap *Photo = new QPixmap;
        Photo->load(filename);
        Photo->scaled(PhotoSize, Qt::KeepAspectRatio);

        ChangePhoto(*Photo);
        LoadPhoto();
    }
}

void games::on_pushButton_2_clicked() // тут вместо void ставишь QByteArray. И первый элемент массива(он и единственный) - это счет у игры. И далее работаешь с ним))
{
    int score;
    QByteArray Score1("0");
    QProcess DoodleJ;
    DoodleJ.start("Games0\\DoodleJ\\x64\\Debug\\DoodleJ.exe");
    DoodleJ.waitForFinished(-1);
    Score1 = DoodleJ.readAllStandardOutput();
    //Here is Doodle jump's Score!
    qDebug() << Score1;
    score = Score1.toInt();
    emit CheckGameResult(login, Doodle, score);
}

void games::on_pushButton_3_clicked()// тут вместо void ставишь QByteArray. И первый элемент массива(он и единственный) - это счет у игры. И далее работаешь с ним))
{
    int score;
    QByteArray Score2("0");
    QProcess Snake1;
    Snake1.start("Games0\\Snake\\Snake1\\x64\\Debug\\Snake1.exe");
    Snake1.waitForFinished(-1);
    Score2 = Snake1.readAllStandardOutput();
    //Here is Snake's Score!
    qDebug() << Score2;
    score = Score2.toInt();
    emit CheckGameResult(login, Snake, score);
}

void games::on_pushButton_4_clicked() // тут вместо void ставишь QByteArray. И первый элемент массива(он и единственный) - это счет у игры. И далее работаешь с ним))
{
    int score;
    QByteArray Score3("0");
    QProcess Miner1;
    Miner1.start("Games0\\Miner\\x64\\Debug\\Miner.exe");
    Miner1.waitForFinished(-1);
    Score3 = Miner1.readAllStandardOutput();
    //Here is Miner's Score!
    qDebug() << Score3;
    score = Score3.toInt();
    emit CheckGameResult(login, Miner,score);
}



void games::on_pushButton_5_clicked()
{
    LeadersForm->show();
    emit LeadersFormOpen();
}
