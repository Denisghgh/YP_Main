/********************************************************************************
** Form generated from reading UI file 'games.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMES_H
#define UI_GAMES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_games
{
public:
    QWidget *centralwidget;
    QLabel *nicknameLabel;
    QLabel *gamesLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *photo;
    QPushButton *pushButton_5;

    void setupUi(QMainWindow *games)
    {
        if (games->objectName().isEmpty())
            games->setObjectName(QStringLiteral("games"));
        games->resize(640, 480);
        games->setMinimumSize(QSize(640, 480));
        games->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        games->setWindowIcon(icon);
        centralwidget = new QWidget(games);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        nicknameLabel = new QLabel(centralwidget);
        nicknameLabel->setObjectName(QStringLiteral("nicknameLabel"));
        nicknameLabel->setGeometry(QRect(10, 120, 110, 16));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nicknameLabel->sizePolicy().hasHeightForWidth());
        nicknameLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        nicknameLabel->setFont(font);
        nicknameLabel->setAlignment(Qt::AlignCenter);
        gamesLabel = new QLabel(centralwidget);
        gamesLabel->setObjectName(QStringLiteral("gamesLabel"));
        gamesLabel->setGeometry(QRect(210, 0, 441, 40));
        gamesLabel->setMinimumSize(QSize(256, 32));
        gamesLabel->setMaximumSize(QSize(500, 40));
        QFont font1;
        font1.setPointSize(24);
        font1.setKerning(true);
        gamesLabel->setFont(font1);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(270, 50, 341, 411));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 339, 409));
        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 321, 41));
        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 110, 321, 41));
        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 60, 321, 41));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 131, 23));
        photo = new QLabel(centralwidget);
        photo->setObjectName(QStringLiteral("photo"));
        photo->setGeometry(QRect(20, 30, 100, 100));
        photo->setLineWidth(1);
        photo->setMidLineWidth(1);
        photo->setMargin(0);
        photo->setIndent(-1);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(0, 150, 131, 23));
        games->setCentralWidget(centralwidget);
        gamesLabel->raise();
        scrollArea->raise();
        pushButton->raise();
        photo->raise();
        nicknameLabel->raise();
        pushButton_5->raise();

        retranslateUi(games);

        QMetaObject::connectSlotsByName(games);
    } // setupUi

    void retranslateUi(QMainWindow *games)
    {
        games->setWindowTitle(QApplication::translate("games", "\320\230\320\263\321\200\320\276\320\262\320\276\320\271 \321\206\320\265\320\275\321\202\321\200", 0));
        nicknameLabel->setText(QString());
        gamesLabel->setText(QApplication::translate("games", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\264\320\276\321\201\321\202\321\203\320\277\320\275\321\213\321\205 \320\270\320\263\321\200:", 0));
        pushButton_2->setText(QApplication::translate("games", "DoodleJump", 0));
        pushButton_4->setText(QApplication::translate("games", "Saper/ Miner", 0));
        pushButton_3->setText(QApplication::translate("games", "Snake", 0));
        pushButton->setText(QApplication::translate("games", "\321\201\320\274\320\265\320\275\320\270\321\202\321\214 \321\204\320\276\321\202\320\276", 0));
        photo->setText(QString());
        pushButton_5->setText(QApplication::translate("games", "\321\202\320\260\320\261\320\273\320\270\321\206\320\260 \320\273\320\270\320\264\320\265\321\200\320\276\320\262", 0));
    } // retranslateUi

};

namespace Ui {
    class games: public Ui_games {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMES_H
