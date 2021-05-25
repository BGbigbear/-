#include "warndialog.h"
#include "ui_warndialog.h"

WarnDialog::WarnDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarnDialog)
{
    ui->setupUi(this);
    this->move((desktop.availableGeometry().width()-this->width()),this->depth());//初始化位置到右下角
}

WarnDialog::WarnDialog(QString name, QWidget *parent):
    QDialog(parent),
    ui(new Ui::WarnDialog)
{
    ui->setupUi(this);
    this->move((desktop.availableGeometry().width()-this->width()),this->depth());//初始化位置到右下角
    ui->label->setText(name+"事件已截至！");
}
WarnDialog::~WarnDialog()
{
    delete ui;
}
