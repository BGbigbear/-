#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"schedule.h"
#include<QDebug>
#include"QMessageBox"
#include"QListWidgetItem"
#include"QContextMenuEvent"
#include"time.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ScheduleOperate=new scheduleoperate;

    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    //定义右键时弹出的菜单栏
    popMenu = new QMenu(this);
    action_Delete = new QAction(tr("删除"), this);
    action_Edit= new QAction(tr("编辑"), this);
    popMenu->addAction(action_Delete);
    popMenu->addAction(action_Edit);



    //连接信号与槽
    connect(this->action_Delete, SIGNAL(triggered()), this, SLOT(onActionDelete()));
    connect(this->action_Edit,SIGNAL(triggered()),this,SLOT(onActionEdit()));


    mytimer=new QTimer(this);
    connect(mytimer, SIGNAL(timeout()),this, SLOT(timerresponse()));
    mytimer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ScheduleOperate;
    delete ui;
}

//添加事件按钮
void MainWindow::on_pushbutton_add_clicked()
{
    //弹出对话框，用户可输入相应内容
    dialog=new Dialog(this);
    dialog->setModal(true);
    dialog->show();
    dialog->exec();

    //点击了对话框的“确定”按钮，即可添加事件
    if(dialog->result()==dialog->Accepted)
    {
        //获取用户输入的事件的相关信息
        QString t=dialog->getTitle();//事件名
        QDateTime s=dialog->getstart();//事件开始时间
        QDateTime e=dialog->getend();//事件结束时间
        QString d=dialog->getdetail();//事件详细信息

        //确保结束时间不能小于开始时间
        if(e<s)
        {
            QMessageBox::information(this, "警告","结束时间不能早于开始时间");
            return;
        }

        //确保事件标题不能为空
        if(t.isEmpty())
        {
            QMessageBox::information(this, "警告","事件名不能为空");
            return;
        }

        //用用户输入的数据实例化一个schedule对象
        schedule sche(t,d,s,e);

        //获取开始时间和结束时间的日期
        QDate D1=s.date();
        QDate D2=e.date();

        //开始日期和结束日期在同一天，只用在该日期的事件集合中添加该事件
        if(D2==D1)
        {
            ScheduleOperate->add_schedule(D1,sche);
        }
        else if(D2>D1)
        {
            //开始日期和结束日期不在同一天，则这两个日期之间的所有日期都要添加该事件
            while(D1<=D2)
            {
                ScheduleOperate->add_schedule(D1,sche);
                D1=D1.addDays(1);
            }
        }
    }

    //在listWidght中显示日历控件当前所选择的日期下的所有事件
    QDate date=ui->calendarWidget->selectedDate();//获取日历控件当前所选的日期
    QVector<schedule>* temp=ScheduleOperate->getschedule(date);//获取该日期下的所有事件的集合
    if(temp==nullptr)
    {
        //当前日期下没有事件，清空listWidght内容即可
        ui->listWidget->clear();
    }
    else
    {
        //当前日期下有事件
        //先清空listWidght内容
        ui->listWidget->clear();
        //遍历日期下所有事件，并显示事件标题到listWidght上
        if(temp != nullptr)
        {
           for(int i=0; i<temp->size(); ++i)
           {
               if(!(*temp)[i].get_is_delete())
               {
                   ui->listWidget->addItem((*temp)[i].getname());
               }
           }
        }
    }
    delete dialog;
}


//点击日历控件的相应函数
void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    //获取当前点击的日期下的所有事件并将事件标题显示在listWidght上
    QVector<schedule>* temp=ScheduleOperate->getschedule(date);
    if(temp==nullptr)
    {
        ui->listWidget->clear();
    }
    else
    {
        ui->listWidget->clear();
        if(temp != nullptr)
        {
           for(int i=0; i<temp->size(); ++i)
           {
               if(!(*temp)[i].get_is_delete())
               {
                   ui->listWidget->addItem((*temp)[i].getname());
               }
           }
        }
    }
}


//删除事件
void MainWindow::onActionDelete()
{
    QDate date=ui->calendarWidget->selectedDate();//获取当前点击的日期
    QList<QListWidgetItem*> items=ui->listWidget->selectedItems();
    if(items.empty()){
        return;
    }
    QString delete_s=items.first()->text();//获取要删除的事件名


    //获取要删除的事件的起始日期和结束日期
    QVector<schedule>* temp=ScheduleOperate->getschedule(date);   
    QDate D1,D2;
    for(int i=0;i<temp->size();i++)
    {
        if((*temp)[i].getname()==delete_s&&!(*temp)[i].get_is_delete())
        {
            D1=(*temp)[i].getstart().date();
            D2=(*temp)[i].getend().date();
            break;
        }
    }
    //起始日期与结束日期相同，只用删除一遍
    if(D1==D2)
    {
        QVector<schedule>* temp1=ScheduleOperate->getschedule(D1);
        for(int i=0;i<temp1->size();i++)
        {
            if((*temp1)[i].getname()==delete_s&&!(*temp1)[i].get_is_delete())
            {
                (*temp1)[i].Delete();//删除该事件
                ui->listWidget->clear();//清空listWidght
                if(temp1 != nullptr)//重新显示listWidght的内容
                {
                    for(int i=0;i<temp1->size();i++)
                    {
                        if(!(*temp1)[i].get_is_delete())
                        {
                            ui->listWidget->addItem((*temp1)[i].getname());
                        }
                    }
                }
                return;
            }
        }
    }
    //起始日期与结束日期不同，要删除多遍
    else if(D2>D1)
    {
        while(D1<=D2)
        {
            QVector<schedule>* temp2=ScheduleOperate->getschedule(D1);
            for(int i=0;i<temp2->size();i++)
            {
                if((*temp2)[i].getname()==delete_s&&!(*temp2)[i].get_is_delete())
                {
                    (*temp2)[i].Delete();//删除事件
                }
            }
            D1=D1.addDays(1);//D1增加一天
        }
        //获取当前点击的日期下的所有事件并将事件标题显示在listWidght上
        QVector<schedule>* temp3=ScheduleOperate->getschedule(date);
        if(temp3==nullptr)
        {
            ui->listWidget->clear();
        }
        else
        {
            ui->listWidget->clear();
            if(temp3 != nullptr)
            {
               for(int i=0; i<temp3->size(); ++i)
               {
                   if(!(*temp3)[i].get_is_delete())
                   {
                       ui->listWidget->addItem((*temp3)[i].getname());
                   }
               }
            }
        }
    }
}


//编辑事件
void MainWindow::onActionEdit()
{
    QDate date=ui->calendarWidget->selectedDate();
    QList<QListWidgetItem*> items=ui->listWidget->selectedItems();
    if(items.empty()){
        return;
    }
    QString edit_s=items.first()->text();

    QVector<schedule>* temp=ScheduleOperate->getschedule(date);
    for(int i=0;i<temp->size();++i)
    {
        if((*temp)[i].getname()==edit_s&&!(*temp)[i].get_is_delete())
        {
            //记录下更改前的事件的内容
            QString detail=(*temp)[i].getdetail();
            QDateTime start=(*temp)[i].getstart();
            QDateTime end=(*temp)[i].getend();
            //弹出对话框，用户在对话框中对原本的事件信息编辑
            dialog_edit=new Dialog(edit_s,start,end,detail,this);
            dialog_edit->setModal(true);
            dialog_edit->show();
            dialog_edit->exec();

            //更改时间信息后点击了对话框的“确定”按钮，确定更改
            if(dialog_edit->result()==dialog_edit->Accepted)
            {
                //记录下更改后的事件信息
                QString t=dialog_edit->getTitle();
                QString d=dialog_edit->getdetail();
                QDateTime s=dialog_edit->getstart();
                QDateTime e=dialog_edit->getend();
                //必须保证结束时间大于开始时间
                if(e<s)
                {
                    QMessageBox::information(this, "警告","结束时间不能早于开始时间");
                    return;
                }

                //确保事件标题不能为空
                if(t.isEmpty())
                {
                    QMessageBox::information(this, "警告","事件名不能为空");
                    return;
                }

                //找到该日期下的原事件，将原事件删除
                QVector<schedule>* temp=ScheduleOperate->getschedule(date);
                for(int i=0;i<temp->size();++i)
                {
                    if((*temp)[i].getname()==edit_s&&!(*temp)[i].get_is_delete())
                    {
                        QDate D1=(*temp)[i].getstart().date();
                        QDate D2=(*temp)[i].getend().date();
                        while(D1<=D2)
                        {
                            QVector<schedule>* temp1=ScheduleOperate->getschedule(D1);
                            for(int i=0;i<temp1->size();i++)
                            {
                                if((*temp1)[i].getname()==edit_s&&!(*temp1)[i].get_is_delete())
                                {
                                    (*temp1)[i].Delete();
                                }
                            }
                            D1=D1.addDays(1);
                        }
                        break;
                    }
                }
                //重新加入编辑后的事件
                schedule sche(t,d,s,e);
                QDate D3=s.date();
                QDate D4=e.date();
                while(D3<=D4)
                {
                    ScheduleOperate->add_schedule(D3,sche);
                    D3=D3.addDays(1);
                }
            }

            //在listWidght上显示当天的事件
            ui->listWidget->clear();//首先清空原有的内容
            QDate date=ui->calendarWidget->selectedDate();//获取日历空间所选中的日期
            QVector<schedule>* temp=ScheduleOperate->getschedule(date);//获取该日期下的所有事件的集合
            if(temp==nullptr)
            {
                ui->listWidget->clear();
            }
            else
            {
                ui->listWidget->clear();
                if(temp != nullptr)
                {
                   for(int i=0; i<temp->size(); ++i)
                   {
                       if(!(*temp)[i].get_is_delete())
                       {
                           ui->listWidget->addItem((*temp)[i].getname());
                       }
                   }
                }
            }
            delete dialog_edit;
            return;
        }
    }
}

//到结束时间弹出窗口
void MainWindow::timerresponse()
{
    if(mytimer->isActive())
    {
    QDate date=QDate::currentDate();
    QVector<schedule>* temp=ScheduleOperate->getschedule(date);
    if(temp==NULL)
    {
        return;
    }
    for(int i=0;i<temp->size();++i)
    {
        if((*temp)[i].getend().time().hour()==QDateTime::currentDateTime().time().hour()&&
                (*temp)[i].getend().time().minute()==QDateTime::currentDateTime().time().minute()&&
                !(*temp)[i].get_is_delete()&&!(*temp)[i].is_time)
        {
            warndialog=new WarnDialog((*temp)[i].getname());
            warndialog->setModal(false);
            warndialog->show();
            (*temp)[i].is_time=true;
        }
    }
    }
}


int MainWindow::getdate()
{
    int day=ui->calendarWidget->selectedDate().day();
    int month=ui->calendarWidget->selectedDate().month();
    int year=ui->calendarWidget->selectedDate().year();
    int date=day+month+year;
    srand(date);
    date=1 + rand() % 3;
    return date;
}

void MainWindow::baiyang()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  白羊座今日运势较好，得到朋友的帮助多，好好珍惜这样的友情。在感情运势方面表现尚好，不要冷战，有矛盾当场说开会比较好。在事业运势方面表现还行，工作能力有提升。");
    case(2):
        ui->textBrowser->setText("  白羊座今日运势尚好，和朋友约一约还不错。在感情运势方面表现尚可，感情需要培养，多花点时间很值得。在事业运势方面表现一般，容易退缩，害怕丢了面子，变得越来越胆小了。在财运运势方面表现普通，赚钱阻碍往往来自自己身边的人，有些想法并没有得到认可。在健康运势方面表现泛泛，经常吃外卖对身体不好，容易养成重口味的习惯，最好选择自己做饭。");
    case(3):
        ui->textBrowser->setText("  今日白羊座的整体运势表现很不错，运势关键词是配合，生活处处都需要配合，能够做到友好配合，那么白羊座的发展会变得顺利起来。今天白羊座能够做到好好配合，形象在变好，人气在提升，得到的好运也会越来越多的");
    }


}

void MainWindow::jingniu()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  金牛座今日运势还行，不要随意质疑别人的能力。在感情运势方面表现一般，不喜欢就说不喜欢，拖拖拉拉的会给别人不切实际的幻想，更容易因此招惹烂桃花");
    case(2):
        ui->textBrowser->setText("  金牛座今日运势普通，争抢的生活会让自己觉得辛苦。在感情运势方面表现泛泛，拿别人来和自己的伴侣比较并不好，会伤及感情。在事业运势方面表现平平，方向错误的时候努力也不一定会有好结果。在财运运势方面表现中等，听信陌生人带来的赚钱消息，收入降低的可能性会更大一点。在健康运势方面表现泛泛，习惯熬夜会给身体带来负担，上火问题会加重");
    case(3):
        ui->textBrowser->setText("  今日金牛座的整体运势表现大致尚可，运势关键词是服软，固执很容易给自己的生活制造新的麻烦，服软其实并没有那么的困难，金牛座要做好这方面的准备，偶尔的低姿态会给生活带来便利，从长远的发展来考虑，金牛座需要改变自己");
    }

}

void MainWindow::shuangzi()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  双子座今日运势较好，有主见会让生活变得轻松。在感情运势方面表现还行，试试看新感情，别总是封闭自己的心。在事业运势方面表现不错，独立性很强，工作效率高。");
    case(2):
        ui->textBrowser->setText("  双子座今日运势还行，别戴有色眼镜看待别人。在感情运势方面表现尚好，不要揭伴侣的伤疤，这样会影响感情发展。在事业运势方面表现尚可，做不了的工作要提前汇报，不能隐瞒不报。在财运运势方面表现泛泛，隐藏经济实力会更合适，找双子座借钱的人变得越来越多了。在健康运势方面表现一般，皮肤状况并不好，记住不能熬夜，保持愉快的心情也很重要");
    case(3):
        ui->textBrowser->setText("  今日双子座的整体运势表现大体良好，运势关键词是暂停，冲太快也容易出事情，对双子座来说今天需要调整方向，因此完成了手头上的事情之后可以稍微暂停一下。双子座制定新的发展方向要考虑长远一点，这样更有利于发展");
    }
}

void MainWindow::juxie()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  巨蟹座今日运势较好，亲和力让人缘变好，不会觉得孤单。在感情运势方面表现尚好，相亲前要打扮自己，不能不修边幅就出现。在事业运势方面表现较好，被领导看好");
    case(2):
        ui->textBrowser->setText("  巨蟹座今日运势较好，和志同道合的人交谈会觉得开心。在感情运势方面表现尚好，喜欢就说出来，别害羞。在事业运势方面表现较好，被信任多，同事会默默地支持巨蟹座。在财运运势方面表现尚可，不可以过度依赖身边人的赚钱能力，好好学习提升能力才是最重要的事情。在健康运势方面表现尚好，锻炼身体很不错，可以选择适合自己的运动项目，循序渐进就好");
    case(3):
        ui->textBrowser->setText("  今日巨蟹座的整体运势表现大致尚可，运势关键词是原谅，别和过去纠缠，原谅别人的过程对巨蟹座来说有好处，原谅了巨蟹座才能够真的放下过去，因此本周需要不断的调整自己的心情，不钻牛角尖就对了");
    }
}

void MainWindow::sanguang()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  狮子座今日运势尚好，减少身上的戾气，会更受欢迎一点。在感情运势方面表现一般，偷偷摸摸的恋爱并不好，这样不能够给对方带来安全感。在事业运势方面表现还行，事业发展速度变快，最好要控制速度，求稳更合适。在财运运势方面表现中等，眼红别人的收入容易让自己变得偏激，收入并没有得到提升。在健康运势方面表现平平，不要穿袜子睡觉，对身体不好");
    case(2):
        ui->textBrowser->setText("  狮子座今日运势良好，多和前辈沟通交流，改变生活的现状。在感情运势方面表现尚可，感情上的习惯也很重要，需要包容伴侣的习惯。在事业运势方面表现较好，有远见让自己得到的关注多，会有伯乐赏识。在财运运势方面表现极佳，偏财运很旺，和身边的人分享一下也很不错。在健康运势方面表现不错，身体恢复状态好，好好照顾自己自然会有好的改变");
    case(3):
        ui->textBrowser->setText("  今日狮子座的整体运势表现相当不错，运势关键词是兴趣，人一旦对一些事情一些人有了兴趣，那么积极性就能够得到提升，今天狮子座会主动的培养自己的兴趣，他们面对生活的时候开始容易得到满足，积极性只会上升不会下降");
    }
}


void MainWindow::chunv()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  处女座今日运势不错，改变自己的态度，会得到大家的喜欢。在感情运势方面表现不错，新感情的到来让自己有了信心，会甜蜜发展。在事业运势方面表现较好，新领导的出现让职场变动变多，需要时间适应。在财运运势方面表现较好，做好守财的工作，这样能够让生活变得稳定，经济烦恼也会减少。在健康运势方面表现较好，戒酒戒烟是好事情，身体会慢慢变好");
    case(2):
        ui->textBrowser->setText("  处女座今日运势还行，远离那些虚情假意的朋友，会有好生活。在感情运势方面表现较好，维护好自己想要的感情，不能随意生气。在事业运势方面表现中等，小心同事使坏，职场自我保护意识需要提升。在财运运势方面表现尚可，自己拿主意最好，省得日后产生后悔感。在健康运势方面表现尚好，不可以用眼过度，适当的让眼睛放松一下会比较好，需要预防视力下降");
    case(3):
        ui->textBrowser->setText("  今日处女座的整体运势表现算是普通，运势关键词是理智，生活中影响到处女座判断的人事物有很多，今天处女座要控制好自己的情绪并不容易，不过还是要尝试着控制看看，失去了理智的处女座是容易给生活带来新的麻烦");
    }
}

void MainWindow::tiancheng()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  天秤座今日运势良好，勇气十足，得到自己想要的。在感情运势方面表现不错，提升感情责任感，得到异性的喜欢多。在事业运势方面表现较好，遵守职场规则，工作便利会变多。在财运运势方面表现较好，钱财不外露，赚钱自己花最好，低调的生活方式可以让自己远离小人的纠缠。在健康运势方面表现还行，可以在客厅摆放点绿植，净化空气很不错，也可以让心情得到放松");
    case(2):
        ui->textBrowser->setText("  天秤座今日运势中等，不能做闭门造车这类事情。在感情运势方面表现一般，没有信心就更应该好好的表现，需要一点勇气。在事业运势方面表现尚可，合理的安排工作，可以提升效率，也减少了失误。在财运运势方面表现泛泛，朋友之间的借钱也要处理好，不要因此带来钱财纠纷。在健康运势方面表现普通，压力大会带来掉发问题，需要缓解和释放压力");
    case(3):
        ui->textBrowser->setText("  今日天秤座的整体运势表现大体良好，运势关键词是气质，气质是可以培养的，拥有好的气质看起来会特别的迷人，今天天秤座的气质会得到提升，得到的关注多了之后后续得到的机会也会变多，会有一连串好的连锁反应出现");
    }
}

void MainWindow::tianxie()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  天蝎座今日运势良好，慢慢改变自己，优点会变多。在感情运势方面表现还行，取得伴侣的信任需要时间，好好表现吧。在事业运势方面表现不错，带着责任感在工作，得到领导的提拔多。在财运运势方面表现较好，放长线钓大鱼的效果很不错，收入会有明显的上升，可以好好的犒劳自己。在健康运势方面表现较好，养好胃很不错，吃饭最好是细嚼慢咽的，这样有利于消化");
    case(2):
        ui->textBrowser->setText("  天蝎座今日运势还行，做好自己该做的事情，责任要明确。在感情运势方面表现中等，感情上经常会觉得没有把握，容易迷失方向。在事业运势方面表现泛泛，接到了自己不擅长的工作，接下来需要花比较多的时间在工作上。在财运运势方面表现尚好，赚钱太快很容易让自己感到不安，脚踏实地会更好。在健康运势方面表现尚可，晚上应该少吃点甜食，对身体不好");
    case(3):
        ui->textBrowser->setText("  天蝎座的整体运势表现大致尚可，运势关键词是面对，逃避并不能解决问题，面对虽然对天蝎座来说是有困难的事情，但是只有选择面对才有解决问题的可能，今天天蝎座要想生活变得顺利，那么好好面对生活才是正确的");
    }
}

void MainWindow::sheshou()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  射手座今日运势较好，被肯定多，会让人越来越喜欢。在感情运势方面表现较好，表白成功，喜欢的人刚好也喜欢着自己。在事业运势方面表现尚好，耽误同事的工作可不好，不要打扰别人做事情。在财运运势方面表现还行，别人分享赚钱机会，好好筛选适合自己的机会，而不是全盘接受。在健康运势方面表现尚可，睡前不适合有激烈运动，反而会破坏睡眠质量");
    case(2):
        ui->textBrowser->setText("  射手座今日运势较好，和小朋友在一起会觉得放松。在感情运势方面表现还行，和伴侣一起规划未来的感觉很不错。在事业运势方面表现尚可，虽然有竞争，但是能够摆正心态，社交关系要多关注。在财运运势方面表现较好，友情给的帮助多，因为朋友赚了不少钱，有能力犒劳自己。在健康运势方面表现尚可，交通安全不能忽略，开车分心容易引发事故");
    case(3):
        ui->textBrowser->setText("  今日射手座的整体运势表现较为普通，运势关键词是谨慎，大大咧咧的习惯会给自己的生活带来麻烦，凡事都应该谨慎一点，生活处处有陷阱，今天的生活对射手座设置的考验比较多，别轻易相信别人说的话，别因为别人的观点影响自己的选择");
    }
}

void MainWindow::moxie()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  摩羯座今日运势尚好，莽撞做事情很糟糕。在感情运势方面表现一般，过于强势，对伴侣的约束多，对方并不一定开心。在事业运势方面表现尚可，竞争对手的出现对工作发展有冲击，不能小看。在财运运势方面表现一般，钱财损失多，丢失贵重物品的可能性大，外出要做好防盗工作。在健康运势方面表现还行，少喝饮料多喝水，自己做饭吃更有利健康，不要经常吃外卖");
    case(2):
        ui->textBrowser->setText("  摩羯座今日运势较好，勤快一点会有好的改变。在感情运势方面表现还行，不适合远距离恋爱，应该结束这种状态。在事业运势方面表现尚好，工作发展不能靠别人，需要在自己身上花时间。在财运运势方面表现较好，接受别人的帮助，赚钱偶尔也需要合作，别太要面子了。在健康运势方面表现尚好，睡觉打呼噜和身体状况有关系，情况严重的还是需要检查看看");
    case(3):
        ui->textBrowser->setText("  今日摩羯座的整体运势表现大致尚可，运势关键词是社交，不要小看社交对生活的影响，摩羯座总是独来独往并不是好事情，多和别人接触走动，那么摩羯座得到的发展会更好，今天不能拒绝别人主动提供的帮助，大大方方的接受会更合适");
    }
}

void MainWindow::shuiping()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  水瓶座今日运势尚好，输赢对自己很重要，胜负心比较强。在感情运势方面表现泛泛，没有把握，面对感情会扭扭捏捏的。在事业运势方面表现还行，不妨再尝试看看，别因为一次的失败就选择放弃。在财运运势方面表现中等，赚钱上多思考，别因为别人的看法而改变自己的原则。在健康运势方面表现尚可，出现伤口要及时处理，避免发炎带来的麻烦，细心一点会更好");
    case(2):
        ui->textBrowser->setText("  水瓶座今日运势还行，只要自己想做就能够很好的完成。在感情运势方面表现尚好，拒绝相亲，并不想用这种方式得到爱情。在事业运势方面表现较好，工作忙碌起来了，因为被领导看重。在财运运势方面表现尚可，别因为一时的失败就垂头丧气的，赚钱偶尔遇见困难也是很正常的事情。在健康运势方面表现较好，重口味的饮食习惯在慢慢的改变，少盐少油对身体好");
    case(3):
        ui->textBrowser->setText("  今日水瓶座的整体运势表现很好，运势关键词是乐观，因为有乐观的状况才能够顺利的克服困难，今天水瓶座凡事都能够想开，不抱怨也不责怪，懂得主动的承担起自己应该要承担的责任，得到的信任和支持变得越来越多了");
    }
}

void MainWindow::shuangyu()
{
    int date=getdate();
    switch (date)
    {
    case(1):
        ui->textBrowser->setText("  双鱼座今日运势较好，不在意别人的看法，自己的生活自己做主。在感情运势方面表现尚好，暗恋有见光的可能，慢慢的被对方接受。在事业运势方面表现还行，能够在工作上找到乐趣，积极性比较高。在财运运势方面表现尚可，副业变动大，能够带来好的收入，坚持去做会得到自己想要的收获。在健康运势方面表现尚好，交通安全多注意，开车不能接打电话");
    case(2):
        ui->textBrowser->setText("  双鱼座今日运势较好，热热闹闹的家庭气氛很不错。在感情运势方面表现还行，别盲目的付出，需要看清对方的真心。在事业运势方面表现较好，脚踏实地的去做会得到认可，别太担心了。在财运运势方面表现尚可，赚钱上想要走捷径可不是什么好事情，容易因此吃亏，反而增加了经济压力。在健康运势方面表现较好，吃饭速度不能太快，会影响到消化，增加肠胃不适感");
    case(3):
        ui->textBrowser->setText("  今天双鱼座的整体运势表现算是普通，运势关键词是忍耐，和别人计较太多最后吃亏的只会是自己，双鱼座要多忍耐一点，忍一时风平浪静还是有些好处的。今天在生活中遇见的阻碍比较多，对自己来说会是一种考验，能不能经受住考验就看自己了");
    }
}


void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    popMenu->exec(QCursor::pos());//显示菜单栏
}


void MainWindow::on_action1_triggered()
{
    dialog_xz=new Dialog_xz;
    dialog_xz->setModal(true);
    dialog_xz->setFixedSize(254,120);
    connect(dialog_xz,SIGNAL(baiyang()),this,SLOT(baiyang()));
    connect(dialog_xz,SIGNAL(shuiping()),this,SLOT(shuiping()));
    connect(dialog_xz,SIGNAL(jingniu()),this,SLOT(jingniu()));
    connect(dialog_xz,SIGNAL(shuangzi()),this,SLOT(shuangzi()));
    connect(dialog_xz,SIGNAL(juxie()),this,SLOT(juxie()));
    connect(dialog_xz,SIGNAL(sanguang()),this,SLOT(sanguang()));
    connect(dialog_xz,SIGNAL(chunv()),this,SLOT(chunv()));
    connect(dialog_xz,SIGNAL(tiancheng()),this,SLOT(tiancheng()));
    connect(dialog_xz,SIGNAL(tianxie()),this,SLOT(tianxie()));
    connect(dialog_xz,SIGNAL(sheshou()),this,SLOT(sheshou()));
    connect(dialog_xz,SIGNAL(moxie()),this,SLOT(moxie()));
    connect(dialog_xz,SIGNAL(shuangyu()),this,SLOT(shuangyu()));
    dialog_xz->show();
}

void MainWindow::on_action2_triggered()
{
    QMessageBox *dialog_help=new QMessageBox(this);
    dialog_help->setWindowTitle("帮助");
    dialog_help->setText("添加事件后需要点击相应的日期才能在下方事件栏显示，遇到添加事件失败请不要惊慌，看看天数是否有误");
    dialog_help->show();
}

void MainWindow::on_action3_triggered()
{
    QMessageBox *dialog_about=new QMessageBox(this);
    dialog_about->setWindowTitle("关于");
    dialog_about->setText("大学生时间管理软件\n"
                          "制作者：Bug和我作队");
    dialog_about->show();
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1=="白羊座")
        {
        baiyang();
        }
    else if(arg1=="金牛座")
        {
        jingniu();
    }
    else if(arg1=="双子座")
        {shuangzi();}
    else if(arg1=="巨蟹座")
    {juxie();}
    else if(arg1=="狮子座")
        {sanguang();}
    else if(arg1=="处女座")
        {chunv();}
    else if(arg1=="天秤座")
        {tiancheng();}
    else if(arg1=="天蝎座")
        {tianxie();}
    else if(arg1=="射手座")
        {sheshou();}
    else if(arg1=="魔蝎座")
        {moxie();}
    else if(arg1=="水瓶座")
        {shuiping();}
    else if(arg1=="双鱼座")
        {shuangyu();}
    else if(arg1=="选择你的星座")
    {ui->textBrowser->clear();}
}
