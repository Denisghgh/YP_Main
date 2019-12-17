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
    QPushButton *pushButton;
    QLabel *photo;

    void setupUi(QMainWindow *games)
    {
        if (games->objectName().isEmpty())
            games->setObjectName(QStringLiteral("games"));
        games->resize(640, 480);
        games->setMinimumSize(QSize(640, 480));
        games->setMaximumSize(QSize(640, 480));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        games->setWindowIcon(icon);
        centralwidget = new QWidget(games);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        nicknameLabel = new QLabel(centralwidget);
        nicknameLabel->setObjectName(QStringLiteral("nicknameLabel"));
        nicknameLabel->setGeometry(QRect(4, 120, 110, 16));
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
        gamesLabel->setGeometry(QRect(220, 10, 371, 32));
        gamesLabel->setMinimumSize(QSize(256, 32));
        gamesLabel->setMaximumSize(QSize(500, 32));
        QFont font1;
        font1.setPointSize(24);
        font1.setKerning(true);
        gamesLabel->setFont(font1);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(220, 50, 411, 421));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 409, 419));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 131, 23));
        photo = new QLabel(centralwidget);
        photo->setObjectName(QStringLiteral("photo"));
        photo->setGeometry(QRect(14, 30, 100, 100));
        photo->setLineWidth(1);
        photo->setMidLineWidth(1);
        photo->setMargin(0);
        photo->setIndent(-1);
        games->setCentralWidget(centralwidget);
        gamesLabel->raise();
        scrollArea->raise();
        pushButton->raise();
        photo->raise();
        nicknameLabel->raise();

        retranslateUi(games);

        QMetaObject::connectSlotsByName(games);
    } // setupUi

    void retranslateUi(QMainWindow *games)
    {
        games->setWindowTitle(QApplication::translate("games", "\320\230\320\263\321\200\320\276\320\262\320\276\320\271 \321\206\320\265\320\275\321\202\321\200", 0));
        nicknameLabel->setText(QString());
        gamesLabel->setText(QApplication::translate("games", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\264\320\276\321\201\321\202\321\203\320\277\320\275\321\213\321\205 \320\270\320\263\321\200:", 0));
        pushButton->setText(QApplication::translate("games", "\321\201\320\274\320\265\320\275\320\270\321\202\321\214 \321\204\320\276\321\202\320\276", 0));
        photo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class games: public Ui_games {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMES_H
