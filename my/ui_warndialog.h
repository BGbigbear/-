/********************************************************************************
** Form generated from reading UI file 'warndialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNDIALOG_H
#define UI_WARNDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WarnDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *WarnDialog)
    {
        if (WarnDialog->objectName().isEmpty())
            WarnDialog->setObjectName(QStringLiteral("WarnDialog"));
        WarnDialog->resize(300, 200);
        verticalLayout = new QVBoxLayout(WarnDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(WarnDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 28pt \"\351\273\221\344\275\223\";\n"
"color: rgb(170, 0, 0);"));

        verticalLayout->addWidget(label);


        retranslateUi(WarnDialog);

        QMetaObject::connectSlotsByName(WarnDialog);
    } // setupUi

    void retranslateUi(QDialog *WarnDialog)
    {
        WarnDialog->setWindowTitle(QApplication::translate("WarnDialog", "\344\272\213\344\273\266\345\210\260\346\234\237\346\217\220\351\206\222", Q_NULLPTR));
        label->setText(QApplication::translate("WarnDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WarnDialog: public Ui_WarnDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNDIALOG_H
