/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <frmlunarcalendarwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushbutton_add;
    QCalendarWidget *calendarWidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QComboBox *comboBox;
    QTextBrowser *textBrowser;
    frmLunarCalendarWidget *widget_2;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(459, 439);
        action1 = new QAction(MainWindow);
        action1->setObjectName(QStringLiteral("action1"));
        action2 = new QAction(MainWindow);
        action2->setObjectName(QStringLiteral("action2"));
        action3 = new QAction(MainWindow);
        action3->setObjectName(QStringLiteral("action3"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushbutton_add = new QPushButton(widget);
        pushbutton_add->setObjectName(QStringLiteral("pushbutton_add"));

        verticalLayout->addWidget(pushbutton_add);

        calendarWidget = new QCalendarWidget(widget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout->addLayout(gridLayout);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        horizontalLayout->addWidget(widget);

        widget_2 = new frmLunarCalendarWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        horizontalLayout->addWidget(widget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 459, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action1);
        menu_2->addAction(action2);
        menu_3->addAction(action3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action1->setText(QApplication::translate("MainWindow", "\344\273\212\346\227\245\346\230\237\345\272\247", Q_NULLPTR));
        action2->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        action3->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        pushbutton_add->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\344\272\213\344\273\266", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\351\200\211\346\213\251\344\275\240\347\232\204\346\230\237\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\231\275\347\276\212\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\207\221\347\211\233\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\214\345\255\220\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\250\350\237\271\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\213\256\345\255\220\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\244\204\345\245\263\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\244\251\347\247\244\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\244\251\350\235\216\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\260\204\346\211\213\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\255\224\350\235\216\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\260\264\347\223\266\345\272\247", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\214\351\261\274\345\272\247", Q_NULLPTR)
        );
        menu->setTitle(QApplication::translate("MainWindow", "\344\270\252\346\200\247\345\214\226", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
