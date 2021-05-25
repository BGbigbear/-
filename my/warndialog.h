#ifndef WARNDIALOG_H
#define WARNDIALOG_H

#include <QDialog>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QPoint>
#include <QTimer>

namespace Ui {
class WarnDialog;
}

class WarnDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarnDialog(QWidget *parent = 0);
    explicit WarnDialog(QString name,QWidget *parent=0);
    ~WarnDialog();

private:
    Ui::WarnDialog *ui;
    QDesktopWidget desktop;
};

#endif // WARNDIALOG_H
