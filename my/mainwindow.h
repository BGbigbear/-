#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"dialog.h"
#include"warndialog.h"
#include"scheduleoperater.h"
#include"QListWidget"
#include"dialog_xz.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //void onCustomContextMenuRequested(const QPoint &pos);

    int getdate();


    ~MainWindow();

private slots:
    void on_pushbutton_add_clicked();//点击“添加事件”按钮

    void on_calendarWidget_clicked(const QDate &date);//点击日历控件

    void onActionDelete();//删除事件

    void onActionEdit();//编辑事件



    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void timerresponse();//到计划结束事件弹出窗口



    //void on_pushbutton_add_clicked();



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



    void on_action1_triggered();

    void on_action2_triggered();

    void on_action3_triggered();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Dialog* dialog;//创建事件时的对话框
    Dialog* dialog_edit;//编辑事件时对话框
    scheduleoperate* ScheduleOperate=nullptr;//事件操作类

    QMenu *popMenu;//弹出菜单
    QAction *action_Delete;//删除
    QAction *action_Edit;//编辑

    WarnDialog* warndialog;//事件提醒窗口
    QTimer* mytimer;//计时器

    Dialog_xz *dialog_xz;
};

#endif // MAINWINDOW_H
