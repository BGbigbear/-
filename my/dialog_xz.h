#ifndef DIALOG_XZ_H
#define DIALOG_XZ_H

#include <QDialog>

namespace Ui {
class Dialog_xz;
}

class Dialog_xz : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_xz(QWidget *parent = nullptr);
    ~Dialog_xz();

signals:
    void baiyang();
    void jingniu();
    void shuangzi();
    void juxie();
    void sanguang();
    void chunv();
    void tiancheng();
    void tianxie();
    void sheshou();
    void moxie();
    void shuiping();
    void shuangyu();

private slots:
    void on_pushButton_baiyang_clicked();

    void on_pushButton_jinniu_clicked();

    void on_pushButton_shuangzi_clicked();

    void on_pushButton_juxie_clicked();

    void on_pushButton_sanguang_clicked();

    void on_pushButton_chunv_clicked();

    void on_pushButton_tiancheng_clicked();

    void on_pushButton_tianxie_clicked();

    void on_pushButton_sheshou_clicked();

    void on_pushButton_moxie_clicked();

    void on_pushButton_shuiping_clicked();

    void on_pushButton_shuangyu_clicked();

private:
    Ui::Dialog_xz *ui;
};

#endif // DIALOG_XZ_H
