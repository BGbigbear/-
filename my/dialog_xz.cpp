#include "dialog_xz.h"
#include "ui_dialog_xz.h"

Dialog_xz::Dialog_xz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_xz)
{
    ui->setupUi(this);
}

Dialog_xz::~Dialog_xz()
{
    delete ui;
}


void Dialog_xz::on_pushButton_baiyang_clicked()
{
    emit baiyang();
}

void Dialog_xz::on_pushButton_jinniu_clicked()
{
    emit jingniu();
}

void Dialog_xz::on_pushButton_shuangzi_clicked()
{
    emit shuangzi();
}

void Dialog_xz::on_pushButton_juxie_clicked()
{
emit juxie();
}

void Dialog_xz::on_pushButton_sanguang_clicked()
{
emit sanguang();
}

void Dialog_xz::on_pushButton_chunv_clicked()
{
emit chunv();
}

void Dialog_xz::on_pushButton_tiancheng_clicked()
{
emit tiancheng();
}

void Dialog_xz::on_pushButton_tianxie_clicked()
{
emit tianxie();
}

void Dialog_xz::on_pushButton_sheshou_clicked()
{
emit sheshou();
}

void Dialog_xz::on_pushButton_moxie_clicked()
{
emit moxie();
}

void Dialog_xz::on_pushButton_shuiping_clicked()
{
emit shuiping();
}

void Dialog_xz::on_pushButton_shuangyu_clicked()
{
emit shuangyu();
}
