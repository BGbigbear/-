/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_title;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QDateTimeEdit *dateTimeEdit_start;
    QTextEdit *textEdit;
    QLabel *label_2;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEdit_end;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(349, 326);
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(9, -1, -1, -1);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 4, 0, 1, 3);

        lineEdit_title = new QLineEdit(Dialog);
        lineEdit_title->setObjectName(QStringLiteral("lineEdit_title"));
        lineEdit_title->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        gridLayout_2->addWidget(lineEdit_title, 0, 1, 1, 2);

        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dateTimeEdit_start = new QDateTimeEdit(groupBox);
        dateTimeEdit_start->setObjectName(QStringLiteral("dateTimeEdit_start"));
        dateTimeEdit_start->setDateTime(QDateTime(QDate(2021, 5, 4), QTime(0, 0, 0)));

        gridLayout->addWidget(dateTimeEdit_start, 0, 1, 1, 1);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(textEdit, 2, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        dateTimeEdit_end = new QDateTimeEdit(groupBox);
        dateTimeEdit_end->setObjectName(QStringLiteral("dateTimeEdit_end"));
        dateTimeEdit_end->setDateTime(QDateTime(QDate(2021, 5, 4), QTime(0, 0, 0)));
        dateTimeEdit_end->setDate(QDate(2021, 5, 4));

        gridLayout->addWidget(dateTimeEdit_end, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 3, 0, 1, 3);

        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 29));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\345\210\233\345\273\272\344\272\213\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        buttonBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("Dialog", "\345\261\236\346\200\247", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\350\257\246\347\273\206\344\277\241\346\201\257\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", " \344\272\213\344\273\266\345\220\215\347\247\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
