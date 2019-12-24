/********************************************************************************
** Form generated from reading UI file 'leaders.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADERS_H
#define UI_LEADERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_leaders
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *gamesLabel;
    QTableWidget *tableWidget;
    QLabel *gamesLabel_2;

    void setupUi(QMainWindow *leaders)
    {
        if (leaders->objectName().isEmpty())
            leaders->setObjectName(QStringLiteral("leaders"));
        leaders->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leaders->sizePolicy().hasHeightForWidth());
        leaders->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        leaders->setWindowIcon(icon);
        centralwidget = new QWidget(leaders);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 440, 111, 23));
        gamesLabel = new QLabel(centralwidget);
        gamesLabel->setObjectName(QStringLiteral("gamesLabel"));
        gamesLabel->setGeometry(QRect(30, 30, 291, 40));
        gamesLabel->setMinimumSize(QSize(256, 32));
        gamesLabel->setMaximumSize(QSize(500, 40));
        QFont font;
        font.setPointSize(24);
        font.setKerning(true);
        gamesLabel->setFont(font);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 100, 571, 341));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setSortingEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setDefaultSectionSize(185);
        gamesLabel_2 = new QLabel(centralwidget);
        gamesLabel_2->setObjectName(QStringLiteral("gamesLabel_2"));
        gamesLabel_2->setGeometry(QRect(270, 30, 256, 40));
        gamesLabel_2->setMinimumSize(QSize(256, 32));
        gamesLabel_2->setMaximumSize(QSize(500, 40));
        gamesLabel_2->setFont(font);
        leaders->setCentralWidget(centralwidget);

        retranslateUi(leaders);

        QMetaObject::connectSlotsByName(leaders);
    } // setupUi

    void retranslateUi(QMainWindow *leaders)
    {
        leaders->setWindowTitle(QApplication::translate("leaders", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \320\273\320\270\320\264\320\265\321\200\320\276\320\262", 0));
        pushButton->setText(QApplication::translate("leaders", "\320\275\320\260\320\267\320\260\320\264", 0));
        gamesLabel->setText(QApplication::translate("leaders", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\273\321\203\321\207\321\210\320\270\321\205", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("leaders", "DoodleJump", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("leaders", "Snake", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("leaders", "Miner", 0));
        gamesLabel_2->setText(QApplication::translate("leaders", "\321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\262", 0));
    } // retranslateUi

};

namespace Ui {
    class leaders: public Ui_leaders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADERS_H
