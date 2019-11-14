#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <windows.h>
#include <QDir>
#include "ShellAPI.h"
#include <QProcess>
#include <windows.h>
#include <objbase.h>

void Circles()
{
QProcess Circle;
Circle.start("labexample\\Debug\\labexample.exe");
Circle.waitForFinished(-1);
}

void Snake_Game()
{
QProcess Snake_Game;
Snake_Game.start("Games\\Snake\\Snake1\\x64\\Debug\\Snake1.exe");
Snake_Game.waitForFinished(-1);
}

void DoodleJ()
{
//system("start C:\\Users\\Denisgh\\Documents\\GitHub\\Yp_Main\\Games\\DoodleJ\\x64\\Debug\\DoodleJ.exe");
QProcess DoodleJ;
DoodleJ.start("Games\\DoodleJ\\x64\\Debug\\DoodleJ.exe");
DoodleJ.waitForFinished(-1);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b1_clicked()
{
    Circles();
    ui->textEdit->setText("Worked!");
}


void MainWindow::on_pushButton_clicked()
{
    Snake_Game();
}

void MainWindow::on_pushButton_2_clicked()
{
    DoodleJ();
}
