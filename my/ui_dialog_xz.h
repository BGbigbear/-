/********************************************************************************
** Form generated from reading UI file 'dialog_xz.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_XZ_H
#define UI_DIALOG_XZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_xz
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_jinniu;
    QPushButton *pushButton_juxie;
    QPushButton *pushButton_sheshou;
    QPushButton *pushButton_shuangzi;
    QPushButton *pushButton_tiancheng;
    QPushButton *pushButton_chunv;
    QPushButton *pushButton_baiyang;
    QPushButton *pushButton_sanguang;
    QPushButton *pushButton_tianxie;
    QPushButton *pushButton_moxie;
    QPushButton *pushButton_shuiping;
    QPushButton *pushButton_shuangyu;

    void setupUi(QDialog *Dialog_xz)
    {
        if (Dialog_xz->objectName().isEmpty())
            Dialog_xz->setObjectName(QStringLiteral("Dialog_xz"));
        Dialog_xz->resize(254, 120);
        gridLayoutWidget = new QWidget(Dialog_xz);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 254, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_jinniu = new QPushButton(gridLayoutWidget);
        pushButton_jinniu->setObjectName(QStringLiteral("pushButton_jinniu"));

        gridLayout->addWidget(pushButton_jinniu, 0, 2, 1, 1);

        pushButton_juxie = new QPushButton(gridLayoutWidget);
        pushButton_juxie->setObjectName(QStringLiteral("pushButton_juxie"));

        gridLayout->addWidget(pushButton_juxie, 1, 1, 1, 1);

        pushButton_sheshou = new QPushButton(gridLayoutWidget);
        pushButton_sheshou->setObjectName(QStringLiteral("pushButton_sheshou"));

        gridLayout->addWidget(pushButton_sheshou, 2, 3, 1, 1);

        pushButton_shuangzi = new QPushButton(gridLayoutWidget);
        pushButton_shuangzi->setObjectName(QStringLiteral("pushButton_shuangzi"));

        gridLayout->addWidget(pushButton_shuangzi, 0, 3, 1, 1);

        pushButton_tiancheng = new QPushButton(gridLayoutWidget);
        pushButton_tiancheng->setObjectName(QStringLiteral("pushButton_tiancheng"));

        gridLayout->addWidget(pushButton_tiancheng, 2, 1, 1, 1);

        pushButton_chunv = new QPushButton(gridLayoutWidget);
        pushButton_chunv->setObjectName(QStringLiteral("pushButton_chunv"));

        gridLayout->addWidget(pushButton_chunv, 1, 3, 1, 1);

        pushButton_baiyang = new QPushButton(gridLayoutWidget);
        pushButton_baiyang->setObjectName(QStringLiteral("pushButton_baiyang"));

        gridLayout->addWidget(pushButton_baiyang, 0, 1, 1, 1);

        pushButton_sanguang = new QPushButton(gridLayoutWidget);
        pushButton_sanguang->setObjectName(QStringLiteral("pushButton_sanguang"));

        gridLayout->addWidget(pushButton_sanguang, 1, 2, 1, 1);

        pushButton_tianxie = new QPushButton(gridLayoutWidget);
        pushButton_tianxie->setObjectName(QStringLiteral("pushButton_tianxie"));

        gridLayout->addWidget(pushButton_tianxie, 2, 2, 1, 1);

        pushButton_moxie = new QPushButton(gridLayoutWidget);
        pushButton_moxie->setObjectName(QStringLiteral("pushButton_moxie"));

        gridLayout->addWidget(pushButton_moxie, 3, 1, 1, 1);

        pushButton_shuiping = new QPushButton(gridLayoutWidget);
        pushButton_shuiping->setObjectName(QStringLiteral("pushButton_shuiping"));

        gridLayout->addWidget(pushButton_shuiping, 3, 2, 1, 1);

        pushButton_shuangyu = new QPushButton(gridLayoutWidget);
        pushButton_shuangyu->setObjectName(QStringLiteral("pushButton_shuangyu"));

        gridLayout->addWidget(pushButton_shuangyu, 3, 3, 1, 1);


        retranslateUi(Dialog_xz);

        QMetaObject::connectSlotsByName(Dialog_xz);
    } // setupUi

    void retranslateUi(QDialog *Dialog_xz)
    {
        Dialog_xz->setWindowTitle(QApplication::translate("Dialog_xz", "Dialog", Q_NULLPTR));
        pushButton_jinniu->setText(QApplication::translate("Dialog_xz", "\351\207\221\347\211\233\345\272\247", Q_NULLPTR));
        pushButton_juxie->setText(QApplication::translate("Dialog_xz", "\345\267\250\350\237\271\345\272\247", Q_NULLPTR));
        pushButton_sheshou->setText(QApplication::translate("Dialog_xz", "\345\260\204\346\211\213\345\272\247", Q_NULLPTR));
        pushButton_shuangzi->setText(QApplication::translate("Dialog_xz", "\345\217\214\345\255\220\345\272\247", Q_NULLPTR));
        pushButton_tiancheng->setText(QApplication::translate("Dialog_xz", "\345\244\251\347\247\244\345\272\247", Q_NULLPTR));
        pushButton_chunv->setText(QApplication::translate("Dialog_xz", "\345\244\204\345\245\263\345\272\247", Q_NULLPTR));
        pushButton_baiyang->setText(QApplication::translate("Dialog_xz", "\347\231\275\347\276\212\345\272\247", Q_NULLPTR));
        pushButton_sanguang->setText(QApplication::translate("Dialog_xz", "\347\213\256\345\255\220\345\272\247", Q_NULLPTR));
        pushButton_tianxie->setText(QApplication::translate("Dialog_xz", "\345\244\251\350\235\216\345\272\247", Q_NULLPTR));
        pushButton_moxie->setText(QApplication::translate("Dialog_xz", "\351\255\224\350\235\216\345\272\247", Q_NULLPTR));
        pushButton_shuiping->setText(QApplication::translate("Dialog_xz", "\346\260\264\347\223\266\345\272\247", Q_NULLPTR));
        pushButton_shuangyu->setText(QApplication::translate("Dialog_xz", "\345\217\214\351\261\274\345\272\247", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_xz: public Ui_Dialog_xz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_XZ_H
