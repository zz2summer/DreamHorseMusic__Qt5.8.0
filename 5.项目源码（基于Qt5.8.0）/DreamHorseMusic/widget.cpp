#include "widget.h"
#include "ui_widget.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QFileDialog>
#include<QUrl>
#include<QDir>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlTableModel>
#include<QMenu>
#include<QPainter>
#include<qmath.h>
#include<QShortcut>
#include<QMessageBox>
#include<QProgressBar>
#include<QProgressDialog>
#include"dialog.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    CreateSortCut();
    Music=new Dialog();
    Music->setWindowFlags(Qt::FramelessWindowHint);

    action1=new QAction(this);
    action2=new QAction(this);
    action3=new QAction(this);
    action1->setIcon(QIcon(":/image/image/music_32px_1125557_easyicon.net.png"));
    action1->setText(tr("加入本地音乐"));
    action1->setShortcut(QKeySequence("Ctrl+O"));
    action2->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
    action2->setText(tr("加入我喜欢"));
    action2->setShortcut(QKeySequence("Ctrl+A"));
    action3->setIcon(QIcon(":/image/image/list_32px_1074296_easyicon.net.png"));
    action3->setText(tr("加入播放队列"));
    action3->setShortcut(QKeySequence("Ctrl+Z"));

    QMenu *menu1=new QMenu(this);
    menu1->addAction(action1);
    menu1->addAction(action2);
    menu1->addAction(action3);
    ui->pushButton->setMenu(menu1);

    action5_1=new QAction(this);
    action5_2=new QAction(this);
    action5_3=new QAction(this);

    action6=new QAction(this);
    action7=new QAction(this);
    action8=new QAction(this);
    ClearALL=new QAction(this);
    ClearALL_1=new QAction(this);
    ClearALL_2=new QAction(this);
    ClearALL_3=new QAction(this);
    ClearALL_4=new QAction(this);

    action5_1->setIcon(QIcon(":/image/image/pf2.png"));
    action5_1->setText(tr("1号皮肤"));
    action5_2->setIcon(QIcon(":/image/image/pf5.png"));
    action5_2->setText(tr("2号皮肤"));
    action5_3->setIcon(QIcon(":/image/image/pf4.png"));
    action5_3->setText(tr("自定义皮肤"));
    action5_3->setShortcut(QKeySequence("Ctrl+X"));

    QMenu *ChangeBackGroundMenu=new QMenu(this);
    ChangeBackGroundMenu->addAction(action5_1);
    ChangeBackGroundMenu->addAction(action5_2);
    ChangeBackGroundMenu->addAction(action5_3);

    ui->pushButton_6->setMenu(ChangeBackGroundMenu);

    action6->setIcon(QIcon(":/image/image/ooopic_1500873230.png"));
    action6->setText(tr("关于"));
    action7->setIcon(QIcon(":/image/image/ooopic_1500873272.png"));
    action7->setText(tr("使用介绍"));
    ClearALL->setIcon(QIcon(":/image/image/edit_clear_locationbar_ltr_32px_539686_easyicon.net.png"));
    ClearALL->setText(tr("清除"));

    ClearALL_1->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
    ClearALL_1->setText(tr("清除本地音乐列表"));
    ClearALL_1->setShortcut(QKeySequence("Ctrl+M"));
    ClearALL_2->setIcon(QIcon(":/image/image/like_outline_32px_1170275_easyicon.net.png"));
    ClearALL_2->setText(tr("清除我喜欢列表"));
    ClearALL_2->setShortcut(QKeySequence("Ctrl+N"));
    ClearALL_3->setIcon(QIcon(":/image/image/list_32px_1142913_easyicon.net.png"));
    ClearALL_3->setText(tr("清除播放队列"));
    ClearALL_3->setShortcut(QKeySequence("Ctrl+B"));
    ClearALL_4->setIcon(QIcon(":/image/image/playlist_27.690544412607px_1187707_easyicon.net.png"));
    ClearALL_4->setText(tr("清除所有列表"));
    ClearALL_4->setShortcut(QKeySequence("Ctrl+V"));
    QMenu *M=new QMenu(this);
    M->addAction(ClearALL_1);
    M->addAction(ClearALL_2);
    M->addAction(ClearALL_3);
    M->addAction(ClearALL_4);
    ClearALL->setMenu(M);

    action8->setIcon(QIcon(":/image/image/tc.png"));
    action8->setText(tr("退出"));
    action8->setShortcut(QKeySequence("Ctrl+Q"));
    QMenu *menu2=new QMenu(this);
    menu2->addAction(action6);
    menu2->addAction(action7);
    menu2->addAction(ClearALL);
    menu2->addAction(action8);
    ui->pushButton_5->setMenu(menu2);

    action9=new QAction(this);
    action9->setIcon(QIcon(":/image/image/pre1.png"));
    action9->setText(tr("播放上一首"));
    action10=new QAction(this);
    action10->setIcon(QIcon(":/image/image/next1.png"));
    action10->setText(tr("播放下一首"));
    action11=new QAction(this);
    action11->setIcon(QIcon(":/image/image/zangting.png"));
    action11->setText(tr("播放/暂停"));

    action12=new QAction(this);
    action12->setIcon(QIcon(":/image/image/moshi1.png"));
    action12->setText(tr("播放模式"));
    action12_1=new QAction(this);
    action12_1->setIcon(QIcon(":/image/image/player-icons_32px_1137007_easyicon.net.png"));
    action12_1->setText(tr("顺序播放"));
    action12_2=new QAction(this);
    action12_2->setIcon(QIcon(":/image/image/player-icons_32px_1137005_easyicon.net.png"));
    action12_2->setText(tr("随机播放"));
    action12_3=new QAction(this);
    action12_3->setIcon(QIcon(":/image/image/player-icons_32px_1137006_easyicon.net.png"));
    action12_3->setText(tr("单曲循环"));
    QMenu *temp1=new QMenu(this);
    temp1->addAction(action12_1);
    temp1->addAction(action12_2);
    temp1->addAction(action12_3);
    action12->setMenu(temp1);
    action13=new QAction(this);
    action13->setIcon(QIcon(":/image/image/tc.png"));
    action13->setShortcut(QKeySequence("Ctrl+Q"));
    action13->setText(tr("退出"));
    detila = new QAction(this);
    detila->setIcon(QIcon(":/image/image/inf.png"));
    detila->setText(tr("歌曲信息"));
    QSqlQuery query;
    query.exec("select * from WALLPAPER_DATA");
    query.next();
    QString FileName=query.value(0).toString();
    if(FileName=="")
    {
        pix.load(":/image/image/59106362042208421aaabcb9.jpg");
    }
    else
    {
        pix.load(FileName);
    }
    query.exec("select * from TRA_DATA");
    query.next();
    QString Values=query.value(0).toString();
    if(Values=="")
    {
        transparency=1;
    }
    else
    {
        transparency=Values.toDouble();
    }
    setWindowOpacity(transparency);
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);

    music=new QMediaPlayer(this);

    playlist =new QMediaPlaylist(this);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist_2=new QMediaPlaylist(this);
    playlist_2->setPlaybackMode(QMediaPlaylist::Loop);
    playlist_3=new QMediaPlaylist(this);
    playlist_3->setPlaybackMode(QMediaPlaylist::Loop);


    ui->pushButton_2->setIconSize(QSize(48,48));
    ui->pushButton_2->setIcon(QIcon(":/image/image/control_play_48px_1116020_easyicon.net.png"));
    ui->pushButton_15->setIconSize(QSize(32,32));
    ui->pushButton_15->setIcon(QIcon(":/image/image/arrow_left_square_32px_1187786_easyicon.net.png"));
    ui->pushButton_9->setIconSize(QSize(32,32));
    ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137007_easyicon.net.png"));
    ui->pushButton_14->setIconSize(QSize(32,32));
    ui->pushButton_14->setIcon(QIcon(":/image/image/like_outline_32px_1170275_easyicon.net.png"));

    ui->pushButton_8->setIconSize(QSize(32,32));
    ui->pushButton_8->setIcon(QIcon(":/image/image/yingliang.png"));



    ui->horizontalSlider->setToolTip(tr("播放进度"));
    ui->pushButton->setToolTip(tr("添加歌曲"));
    ui->pushButton_2->setToolTip(tr("暂停"));
    ui->pushButton_3->setToolTip(tr("下一首"));
    ui->pushButton_4->setToolTip(tr("上一首"));
    ui->pushButton_5->setToolTip(tr("设置"));
    ui->pushButton_6->setToolTip(tr("更换皮肤"));
    ui->pushButton_7->setToolTip(tr("定位"));
    ui->pushButton_8->setToolTip(tr("音量"));
    ui->pushButton_9->setToolTip(tr("顺序播放"));
    ui->pushButton_10->setToolTip(tr("本地音乐"));
    ui->pushButton_11->setToolTip(tr("我喜欢"));
    ui->pushButton_12->setToolTip(tr("播放队列"));
    ui->pushButton_13->setToolTip(tr("切换至极简模式/双击"));
    ui->pushButton_15->setToolTip(tr("隐藏播放列表"));
    ui->pushButton_17->setToolTip(tr("关闭"));
    ui->pushButton_16->setToolTip(tr("最小化"));

    ui->verticalSlider->hide();
    ui->verticalSlider->setValue(100);


    ui->horizontalSlider->setValue(0);
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_10->setStyleSheet("QPushButton"
    "{"
    "background-image: url(:/image/image/music_32px_1125557_easyicon.net.png);"
    "background-color: rgba(255, 255, 255,100);"
    "border-style:outset;"
    "border-color:rgba(255,255,255,0);"
    "border-radius:4px;"
    "}"
    "QPushButton:hover{"
    "background-color: rgb(255, 255, 255,100);"
    "}"
    "QPushButton:pressed{"
    " background-color: rgba(95, 95, 95,100);"
    "border-color:rgba(255,255,255,30);"
    "border-style:inset;"
    "color:rgba(0,0,0,100);"
   " }"
);


    model=new QSqlTableModel(this);
    model->setTable("HAHAHA");
    model->select();
    model_2=new QSqlTableModel(this);
    model_2->setTable("I_LIKE_DATA");
    model_2->select();
    model_3=new QSqlTableModel(this);
    model_3->setTable("NIMA");
    model_3->select();

    connect(music,&QMediaPlayer::metaDataAvailableChanged,this,&Widget::updateInfo);
    connect(music,&QMediaPlayer::positionChanged,this,&Widget::updatePosition);
    connect(music,&QMediaPlayer::durationChanged,this,&Widget::updateDuration);
    connect(ui->horizontalSlider,&QSlider::sliderMoved,music,&QMediaPlayer::setPosition);
    connect(playlist,&QMediaPlaylist::currentIndexChanged,this,&Widget::updatalistwidget_3);
    connect(playlist_2,&QMediaPlaylist::currentIndexChanged,this,&Widget::updatalistwidget_2);
    connect(playlist_3,&QMediaPlaylist::currentIndexChanged,this,&Widget::updatalistwidget);
    connect(action1,&QAction::triggered,this,&Widget::action1_slot);
    connect(action2,&QAction::triggered,this,&Widget::action2_slot);
    connect(action3,&QAction::triggered,this,&Widget::action3_slot);
    connect(action5_1,&QAction::triggered,this,&Widget::action5_1_slot);
    connect(action5_2,&QAction::triggered,this,&Widget::action5_2_slot);
    connect(action5_3,&QAction::triggered,this,&Widget::action5_3_slot);
    connect(action6,&QAction::triggered,this,&Widget::action6_slot);
    connect(action7,&QAction::triggered,this,&Widget::action7_slot);
    connect(action8,&QAction::triggered,this,&Widget::action8_slot);
    connect(ClearALL_1,&QAction::triggered,this,&Widget::ClearALL_1_slot);
    connect(ClearALL_2,&QAction::triggered,this,&Widget::ClearALL_2_slot);
    connect(ClearALL_3,&QAction::triggered,this,&Widget::ClearALL_3_slot);
    connect(ClearALL_4,&QAction::triggered,this,&Widget::ClearALL_4_slot);
    connect(action13,&QAction::triggered,this,&Widget::action8_slot);
    connect(action9,&QAction::triggered,this,&Widget::action9_slot);
    connect(action10,&QAction::triggered,this,&Widget::action10_slot);
    connect(action11,&QAction::triggered,this,&Widget::action11_slot);
    connect(action12_1,&QAction::triggered,this,&Widget::action12_1_slot);
    connect(action12_2,&QAction::triggered,this,&Widget::action12_2_slot);
    connect(action12_3,&QAction::triggered,this,&Widget::action12_3_slot);
    connect(ui->verticalSlider,&QSlider::valueChanged,this,&Widget::changeVolume);
    connect(music,&QMediaPlayer::stateChanged,this,&Widget::music_stateChang);
    connect(Music,&Dialog::Data,this,&Widget::Data_slot);
    connect(detila,&QAction::triggered,this,&Widget::detila_slot);
    connect(playlist,&QMediaPlaylist::playbackModeChanged,this,&Widget::PlaylistModel_slot);

    query.exec("select * from HAHAHA");
    while(query.next())
    {
        QString Name=query.value(1).toString();
        QString FileName=query.value(2).toString();
        if(Name!=""&&FileName!="")
        {
        QListWidgetItem *item1=new QListWidgetItem;
        item1->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
        item1->setText(Name);
        ui->listWidget_3->addItem(item1);
        playlist->addMedia(QUrl::fromLocalFile(FileName));

        }

    }
    query.exec("select * from I_LIKE_DATA");
    while(query.next())
    {
        QString Name=query.value(1).toString();
        QString FileName=query.value(2).toString();
        if(Name!=""&&FileName!="")
        {
        QListWidgetItem *item4=new QListWidgetItem;
        item4->setIcon(QIcon(":/image/image/like_outline_32px_1170275_easyicon.net.png"));
        item4->setText(Name);
        ui->listWidget_2->addItem(item4);
        playlist_2->addMedia(QUrl::fromLocalFile(FileName));
        }

    }
    query.exec("select * from NIMA");
    while(query.next())
    {
        QString Name=query.value(1).toString();
        QString FileName=query.value(2).toString();
        if(Name!=""&&FileName!="")
        {
        QListWidgetItem *item5=new QListWidgetItem;
       item5->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
       item5->setText(Name);
        ui->listWidget->addItem(item5);
        playlist_3->addMedia(QUrl::fromLocalFile(FileName));
        }

    }
    music->setPlaylist(playlist);
}


Widget::~Widget()//析构
{
    delete ui;
}
static QString Time(qint64 time)//转换时间
{
    qint64 seconds=time/1000;
    const qint64 minutes=seconds/60;
    seconds-=minutes*60;
    return QStringLiteral("%1:%2")
            .arg(minutes, 2, 10, QLatin1Char('0'))
            .arg(seconds, 2, 10, QLatin1Char('0'));
}
//更新文本，显示歌曲信息
void Widget::updateInfo()
{

    QString info;
    info=tr("正在播放:  ");
    if(music->isMetaDataAvailable())
    {
        QString title=music->metaData(QStringLiteral("Title")).toString();
        if(!title.isEmpty())
        {

            info+=title;
        }
        else
        {
            info+=tr("未知歌曲");
        }
        info+="-";
        QString author=music->metaData(QStringLiteral("Author")).toString();
        if(!author.isEmpty())
        {
            info+=author;
        }
        else
        {
          info+=tr("未知作者");
        }
    }
    ui->label->setText(info);
    if(music->playlist()==playlist_2)
    {
        ui->pushButton_14->setIcon(QIcon(":/image/image/like_32px_1101682_easyicon.net.png"));
        ui->pushButton_14->setToolTip(tr("我喜欢"));
    }
    else if(music->playlist()==playlist_3)
    {
        ui->pushButton_14->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
        ui->pushButton_14->setToolTip(tr("播放队列"));
    }
    else
    {
        QSqlQuery query;
        query.exec("select * from HAHAHA");
        model->setTable("HAHAHA");
        model->select();
        int row=playlist->currentIndex();
        int flag;
         flag=model->data(model->index(row,3)).toInt();
        if(flag)
        {
            ui->pushButton_14->setIcon(QIcon(":/image/image/like_32px_1101682_easyicon.net.png"));
            ui->pushButton_14->setToolTip(tr("我喜欢"));
        }
        else
        {
            ui->pushButton_14->setIcon(QIcon(":/image/image/like_outline_32px_1170275_easyicon.net.png"));
            ui->pushButton_14->setToolTip(tr("添加至我喜欢"));
        }

      }
}

void Widget::updatePosition(qint64 position)//更新播放位置
{
    ui->horizontalSlider->setValue(position);
    ui->label_2->setText(Time(position)+"/"+Time(music->duration()));
}
void Widget::updateDuration(qint64 duration)//更新播放进度
{

    ui->horizontalSlider->setRange(0,duration);
    ui->horizontalSlider->setEnabled(duration>0);
    ui->horizontalSlider->setPageStep(duration/10);
}

void Widget::pushbuttonstyle()//所有歌曲按钮亮
{
    ui->pushButton_10->setStyleSheet("QPushButton"
    "{"
    "background-image: url(:/image/image/music_32px_1125557_easyicon.net.png);"
    "background-color: rgba(255, 255, 255,100);"
    "border-style:outset;"
    "border-color:rgba(255,255,255,0);"
    "border-radius:4px;"
    "}"
    "QPushButton:hover{"
    "background-color: rgb(255, 255, 255,100);"
    "}"
    "QPushButton:pressed{"
    " background-color: rgba(95, 95, 95,100);"
    "border-color:rgba(255,255,255,30);"
    "border-style:inset;"
    "color:rgba(0,0,0,100);"
   " }");
    ui->pushButton_11->setStyleSheet("QPushButton"
    "{"
    "background-image: url(:/image/image/like_outline_32px_1170275_easyicon.net.png);"
    "background-color: rgba(255, 255, 255,0);"
    "border-style:outset;"
    "border-color:rgba(255,255,255,0);"
    "border-radius:4px;"
    "}"
     "QPushButton:hover{"
    "background-color: rgb(255, 255, 255,100);"
    "}"
    "QPushButton:pressed{"
     " background-color: rgba(95, 95, 95,100);"
     "border-color:rgba(255,255,255,30);"
     "border-style:inset;"
      "color:rgba(0,0,0,100);"
       " }");

    ui->pushButton_12->setStyleSheet("QPushButton"
   "{"
    "background-image: url(:/image/image/list_32px_1074296_easyicon.net.png);"
    "background-color: rgba(255, 255, 255,0);"
    "border-style:outset;"
    "border-color:rgba(255,255,255,0);"
    "border-radius:4px;"
    "}"
    "QPushButton:hover{"
    "background-color: rgb(255, 255, 255,100);"
    "}"
    "QPushButton:pressed{"
    "background-color: rgba(95, 95, 95,100);"
    "border-color:rgba(255,255,255,30);"
    "border-style:inset;"
    "color:rgba(0,0,0,100);"
  " }");
}

void Widget::pushbuttonstyle_2()//我喜欢按钮亮
{
    ui->pushButton_10->setStyleSheet("QPushButton"
    "{"
    "background-image: url(:/image/image/music_32px_1125557_easyicon.net.png);"
    "background-color: rgba(255, 255, 255,0);"
    "border-style:outset;"
    "border-color:rgba(255,255,255,0);"
    "border-radius:4px;"
    "}"
    "QPushButton:hover{"
    "background-color: rgb(255, 255, 255,100);"
    "}"
    "QPushButton:pressed{"
    " background-color: rgba(95, 95, 95,100);"
    "border-color:rgba(255,255,255,30);"
    "border-style:inset;"
    "color:rgba(0,0,0,100);"
   " }"
);
    ui->pushButton_11->setStyleSheet("QPushButton"
                                     "{"
                                     "background-image: url(:/image/image/like_outline_32px_1170275_easyicon.net.png);"
                                     "background-color: rgba(255, 255, 255,100);"
                                     "border-style:outset;"
                                     "border-color:rgba(255,255,255,0);"
                                     "border-radius:4px;"
                                     "}"
                                     "QPushButton:hover{"
                                     "background-color: rgb(255, 255, 255,100);"
                                     "}"
                                     "QPushButton:pressed{"
                                     " background-color: rgba(95, 95, 95,100);"
                                     "border-color:rgba(255,255,255,30);"
                                     "border-style:inset;"
                                     "color:rgba(0,0,0,100);"
                                    " }");

    ui->pushButton_12->setStyleSheet("QPushButton"
                                     "{"
                                     "	background-image: url(:/image/image/list_32px_1074296_easyicon.net.png);"
                                     "background-color: rgba(255, 255, 255,0);"
                                     "border-style:outset;"
                                     "border-color:rgba(255,255,255,0);"
                                     "border-radius:4px;"
                                     "}"
                                     "QPushButton:hover{"
                                     "background-color: rgb(255, 255, 255,100);"
                                     "}"
                                     "QPushButton:pressed{"
                                     " background-color: rgba(95, 95, 95,100);"
                                     "border-color:rgba(255,255,255,30);"
                                     "border-style:inset;"
                                     "color:rgba(0,0,0,100);"
                                    " }");

}
void Widget::pushbuttonstyle_3()//自定义播放列表按钮亮
{

    ui->pushButton_10->setStyleSheet("QPushButton"
    "{"
    "background-image: url(:/image/image/music_32px_1125557_easyicon.net.png);"
    "background-color: rgba(255, 255, 255,0);"
    "border-style:outset;"
    "border-color:rgba(255,255,255,0);"
    "border-radius:4px;"
    "}"
    "QPushButton:hover{"
    "background-color: rgb(255, 255, 255,100);"
    "}"
    "QPushButton:pressed{"
    " background-color: rgba(95, 95, 95,100);"
    "border-color:rgba(255,255,255,30);"
    "border-style:inset;"
    "color:rgba(0,0,0,100);"
   " }"
);
    ui->pushButton_11->setStyleSheet("QPushButton"
                                     "{"
                                     "background-image: url(:/image/image/like_outline_32px_1170275_easyicon.net.png);"
                                     "background-color: rgba(255, 255, 255,0);"
                                     "border-style:outset;"
                                     "border-color:rgba(255,255,255,0);"
                                     "border-radius:4px;"
                                     "}"
                                     "QPushButton:hover{"
                                     "background-color: rgb(255, 255, 255,100);"
                                     "}"
                                     "QPushButton:pressed{"
                                     " background-color: rgba(95, 95, 95,100);"
                                     "border-color:rgba(255,255,255,30);"
                                     "border-style:inset;"
                                     "color:rgba(0,0,0,100);"
                                    " }");

    ui->pushButton_12->setStyleSheet("QPushButton"
                                     "{"
                                     "	background-image: url(:/image/image/list_32px_1074296_easyicon.net.png);"
                                     "background-color: rgba(255, 255, 255,100);"
                                     "border-style:outset;"
                                     "border-color:rgba(255,255,255,0);"
                                     "border-radius:4px;"
                                     "}"
                                     "QPushButton:hover{"
                                     "background-color: rgb(255, 255, 255,100);"
                                     "}"
                                     "QPushButton:pressed{"
                                     " background-color: rgba(95, 95, 95,100);"
                                     "border-color:rgba(255,255,255,30);"
                                     "border-style:inset;"
                                     "color:rgba(0,0,0,100);"
                                    " }");
}
void Widget::pushbuttonstyle_4()
{

    ui->pushButton_10->setStyleSheet("QPushButton"
    "{"
    "background-image: url(:/image/image/music_32px_1125557_easyicon.net.png);"
    "background-color: rgba(255, 255, 255,0);"
    "border-style:outset;"
    "border-color:rgba(255,255,255,0);"
    "border-radius:4px;"
    "}"
    "QPushButton:hover{"
    "background-color: rgb(255, 255, 255,100);"
    "}"
    "QPushButton:pressed{"
    " background-color: rgba(95, 95, 95,100);"
    "border-color:rgba(255,255,255,30);"
    "border-style:inset;"
    "color:rgba(0,0,0,100);"
   " }"
);
    ui->pushButton_11->setStyleSheet("QPushButton"
                                     "{"
                                     "background-image: url(:/image/image/like_outline_32px_1170275_easyicon.net.png);"
                                     "background-color: rgba(255, 255, 255,0);"
                                     "border-style:outset;"
                                     "border-color:rgba(255,255,255,0);"
                                     "border-radius:4px;"
                                     "}"
                                     "QPushButton:hover{"
                                     "background-color: rgb(255, 255, 255,100);"
                                     "}"
                                     "QPushButton:pressed{"
                                     " background-color: rgba(95, 95, 95,100);"
                                     "border-color:rgba(255,255,255,30);"
                                     "border-style:inset;"
                                     "color:rgba(0,0,0,100);"
                                    " }");

    ui->pushButton_12->setStyleSheet("QPushButton"
                                     "{"
                                     "	background-image: url(:/image/image/list_32px_1074296_easyicon.net.png);"
                                     "background-color: rgba(255, 255, 255,0);"
                                     "border-style:outset;"
                                     "border-color:rgba(255,255,255,0);"
                                     "border-radius:4px;"
                                     "}"
                                     "QPushButton:hover{"
                                     "background-color: rgb(255, 255, 255,100);"
                                     "}"
                                     "QPushButton:pressed{"
                                     " background-color: rgba(95, 95, 95,100);"
                                     "border-color:rgba(255,255,255,30);"
                                     "border-style:inset;"
                                     "color:rgba(0,0,0,100);"
                                    " }");

}

void Widget::on_pushButton_10_clicked()//跳至所有音乐
{
    ui->stackedWidget->setCurrentIndex(0);
    pushbuttonstyle();
}

void Widget::on_pushButton_11_clicked()//跳至自我喜欢
{
    ui->stackedWidget->setCurrentIndex(1);
    pushbuttonstyle_2();
}


void Widget::on_pushButton_12_clicked()//跳至自定义播放列表
{
    ui->stackedWidget->setCurrentIndex(2);
    pushbuttonstyle_3();
}

//歌曲信息显示
void Widget::detila_slot()
{

    if(music->playlist()==playlist)
    {
        int row=playlist->currentIndex();
        QString temp=ui->label->text();
        QString Author=temp.split("-").last();
        QString MusicName=temp.remove("-"+Author).split(":  ").last();
        QString time=ui->label_2->text().split("/").last();
        model->setTable("HAHAHA");
        model->select();
        QString FileName=model->data(model->index(row,2)).toString();
        QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名 : %1  \n"
                                                 "作者 : %2 \n"
                                                 "时长 : %3 \n"
                                                 "文件路径 : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));


    }
    else if(music->playlist()==playlist_2)
    {

        int row=playlist_2->currentIndex();
        QString temp=ui->label->text();
        QString Author=temp.split("-").last();
        QString MusicName=temp.remove("-"+Author).split(":  ").last();
        QString time=ui->label_2->text().split("/").last();
        model_2->setTable("I_LIKE_DATA");
        model_2->select();
        QString FileName=model_2->data(model_2->index(row,2)).toString();
        QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名 : %1  \n"
                                                 "作者 : %2 \n"
                                                 "时长 : %3 \n"
                                                 "文件路径 : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));

    }
    else
    {
        int row=playlist_3->currentIndex();
        QString temp=ui->label->text();
        QString Author=temp.split("-").last();
        QString MusicName=temp.remove("-"+Author).split(":  ").last();
        QString time=ui->label_2->text().split("/").last();
        model_3->setTable("NIMA");
        model_3->select();
        QString FileName=model_3->data(model_3->index(row,2)).toString();
        QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名 : %1  \n"
                                                 "作者 : %2 \n"
                                                 "时长 : %3 \n"
                                                 "文件路径 : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));


    }
}

//清空列表
void Widget::ClearALL_1_slot()
{
    int values=QMessageBox::information(this,tr("清除本地音乐列表"),tr("确定清除本地音乐列表?                              ."),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(values==QMessageBox::Yes)
    {
        QSqlQuery query;
    query.exec("select * from HAHAHA");
    query.exec("delete from HAHAHA");
    ui->listWidget_3->clear();
    playlist->clear();

    }


}
void Widget::ClearALL_2_slot()
{
    int values=QMessageBox::information(this,tr("清除我喜欢列表"),tr("确定清除我喜欢列表?                              ."),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(values==QMessageBox::Yes)
    {
        QSqlQuery query;
    query.exec("select * from I_LIKE_DATA");
    query.exec("delete from I_LIKE_DATA");
    query.exec("select * from HAHAHA");
    query.prepare(QString("update HAHAHA set biaoji = ? where biaoji = 1"));
    query.bindValue(0,0);
    query.exec();
    ui->listWidget_2->clear();
    playlist_2->clear();

    }
}
void Widget::ClearALL_3_slot()
{
    int values=QMessageBox::information(this,tr("清除播放队列"),tr("确定清除播放队列?                              ."),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(values==QMessageBox::Yes)
    {
        QSqlQuery query;
    query.exec("select * from NIMA");
    query.exec("delete from NIMA");
    ui->listWidget->clear();
    playlist_3->clear();

    }


}
void Widget::ClearALL_4_slot()
{
    int values=QMessageBox::information(this,tr("清除所有列表"),tr("确定清除所有列表?                              ."),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(values==QMessageBox::Yes)
    {
    QSqlQuery query;

    query.exec("delete from HAHAHA");
      query.exec("delete from NIMA");
       query.exec("delete from I_LIKE_DATA");
    ui->listWidget_3->clear();
    ui->listWidget_2->clear();
    ui->listWidget->clear();
    playlist->clear();
    playlist_2->clear();
    playlist_3->clear();
    }
}

//添加菜单  添加至所有音乐
void Widget::action1_slot()
{
    ui->stackedWidget->setCurrentIndex(0);
    pushbuttonstyle();
    QSqlQuery query;
    query.exec("select * from HAHAHA");
    QStringList list=QFileDialog::getOpenFileNames(this,tr("文件"),"music",tr("音频文件(*.mp3)"));
    if(!list.isEmpty())
    {
    QProgressDialog *progressdialog=new QProgressDialog(this);
    progressdialog->setWindowModality(Qt::WindowModal);
    progressdialog->setMinimumDuration(100);
    progressdialog->resize(500,200);
    progressdialog->setWindowTitle(tr("添加歌曲"));
    progressdialog->setLabelText(tr("添加中                              ."));
    progressdialog->setCancelButtonText(tr("关闭"));
    progressdialog->setRange(0,list.size()-1);
    for(int i=0;i<list.size();i++)
    {
        QListWidgetItem *item=new QListWidgetItem;
        item->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
        QString path=QDir::toNativeSeparators(list.at(i));
        progressdialog->setValue(i);
        if(i==list.size()-1)
        {
            progressdialog->close();
        }
        if(progressdialog->wasCanceled())
            progressdialog->close();
        if(!path.isEmpty())
        {


           playlist->addMedia(QUrl::fromLocalFile(path));
           QString Name=path.split("\\").last();
           Name.remove(QString(".mp3"));
           item->setText(QString("%1").arg(Name));
           ui->listWidget_3->addItem(item);
           query.exec(QString("insert into HAHAHA values (%1,'%2','%3',%4)").arg(qrand()%10000).arg(Name).arg(path).arg(0));
        }
    }
    }
}
//添加菜单  添加至我喜欢
void Widget::action2_slot()
{
      ui->stackedWidget->setCurrentIndex(1);
      pushbuttonstyle_2();
    QSqlQuery query;
    query.exec("select *from I_LIKE_DATA");
    QStringList list = QFileDialog::getOpenFileNames(this,tr("所有文件"),"music",tr("音频文件(*.mp3)"));
    if(!list.isEmpty())
   { QProgressDialog *progressdialog=new QProgressDialog(this);
    progressdialog->setWindowModality(Qt::WindowModal);
    progressdialog->resize(500,200);
    progressdialog->setMinimumDuration(100);
    progressdialog->setWindowTitle(tr("添加歌曲"));
    progressdialog->setLabelText(tr("添加中                              ."));
    progressdialog->setCancelButtonText(tr("关闭"));
    progressdialog->setRange(0,list.size()-1);
    for(int i=0;i<list.size();i++)
    {
        QListWidgetItem *item2=new QListWidgetItem;
        item2->setIcon(QIcon(":/image/image/like_outline_32px_1170275_easyicon.net.png"));
        QString path=QDir::toNativeSeparators(list.at(i));
        progressdialog->setValue(i);
        if(i==list.size()-1)
        {
            progressdialog->close();
        }
        if(progressdialog->wasCanceled())
            progressdialog->close();
        if(!path.isEmpty())
        {
            playlist_2->addMedia(QUrl::fromLocalFile(path));
            QString Name=path.split("\\").last();
            Name.remove(QString(".mp3"));
            item2->setText(QString("%1").arg(Name));

            ui->listWidget_2->addItem(item2);
            query.exec(QString("insert into I_LIKE_DATA values (%1,'%2','%3')").arg(qrand()%10000).arg(Name).arg(path));
        }
    }
    }
}

void Widget::action3_slot()//添加菜单  添加至自定义菜单
{
  ui->stackedWidget->setCurrentIndex(2);
  pushbuttonstyle_3();
    QSqlQuery query;
    query.exec("select *from NIMA");
    QStringList list = QFileDialog::getOpenFileNames(this,tr("所有文件"),"music",tr("音频文件(*.mp3)"));
   if(!list.isEmpty())
   {
    QProgressDialog *progressdialog=new QProgressDialog(this);
    progressdialog->setWindowModality(Qt::WindowModal);
    progressdialog->setMinimumDuration(100);
    progressdialog->resize(500,200);
    progressdialog->setWindowTitle(tr("添加歌曲"));
    progressdialog->setLabelText(tr("添加中                              ."));
    progressdialog->setCancelButtonText(tr("关闭"));
    progressdialog->setRange(0,list.size()-1);
    for(int i=0;i<list.size();i++)
    {
        QListWidgetItem *item3=new QListWidgetItem;
        item3->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
        QString path=QDir::toNativeSeparators(list.at(i));
        progressdialog->setValue(i);
        if(i==list.size()-1)
        {
            progressdialog->close();
        }
        if(progressdialog->wasCanceled())
            progressdialog->close();
        if(!path.isEmpty())
        {
            playlist_3->addMedia(QUrl::fromLocalFile(path));
            QString Name=path.split("\\").last();
            Name.remove(QString(".mp3"));
            item3->setText(QString("%1").arg(Name));
            ui->listWidget->addItem(item3);
            query.exec(QString("insert into NIMA values (%1,'%2','%3')").arg(qrand()%10000).arg(Name).arg(path));
        }
    }
   }

}
//默认背景1
void Widget::action5_1_slot()
{
    QString FileName=":/image/image/59106362042208421aaabcb9.jpg";
    QSqlQuery query;
    query.exec("delete from WALLPAPER_DATA");
    query.exec(QString("insert into WALLPAPER_DATA values('%1')").arg(FileName));
    pix.load(FileName);
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
}
//默认背景2
void Widget::action5_2_slot()
{

    QString FileName=":/image/image/59373528e7bce75645eb757a.jpg";
    QSqlQuery query;
    query.exec("delete from WALLPAPER_DATA");
    query.exec(QString("insert into WALLPAPER_DATA values('%1')").arg(FileName));
    pix.load(FileName);
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
}
//自定义背景
void Widget::action5_3_slot()//设置菜单  添加图片
{

    QString FileName=QFileDialog::getOpenFileName(this,tr("文件"),"./bgPicture",tr("图片文件(*jpg *png)"));
    if(FileName!="")
    {
        QSqlQuery query;
        query.exec("delete from WALLPAPER_DATA");
        query.exec(QString("insert into WALLPAPER_DATA values('%1')").arg(FileName));
        pix.load(FileName);
        pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
        setPalette(pal);
    }
}
//设置  关于
void Widget::action6_slot()
{

QMessageBox::about(this,tr("关于"),tr("                 梦马音乐                \n"
                                    "                             夏天         \n"
                                    "    梦马音乐版权归属梦码集团，任何见解，任何看法，\n"
                                    "敬请随意发表，反正……我也不会改。                 \n"
                                    "    如需转用，随意就好，使用愉快！             \n"));



}

//设置菜单  使用
void Widget::action7_slot()
{QMessageBox::about(this,tr("使用"),tr("向前切换列表:A     向后切换列表:D\n"
                                      "增加音量:W         减少音量:S\n"
                                      "切换播放模式:E      添加我喜欢:R\n"
                                      "定位播放列表:Q      切换上一曲：4\n"
                                      "菜单栏：右键        切换下一曲：6\n"
                                      "界面切换：左键双击   播放暂停：空格\n"
                                      "更多功能，更多期待，欢迎自由探索…… "));


}
//主窗口右键菜单 关闭
void Widget::action8_slot()
{

   close();

}
//主窗口右键菜单 播放下一曲
void Widget::action9_slot()
{

    if(music->playlist()==playlist)
    {

        int currentIndex=playlist->currentIndex();
        ui->stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
        if(--currentIndex<0)
        {

            currentIndex=0;


        }
       playlist->setCurrentIndex(currentIndex);

    }
    else if(music->playlist()==playlist_2)
    {

        int currentIndex=playlist_2->currentIndex();
        ui->stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        if(--currentIndex<0)
        {
            currentIndex=0;
        }
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if(music->playlist()==playlist_3)
    {
        int currentIndex=playlist_3->currentIndex();
        ui->stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        if(--currentIndex<0)
        {
            currentIndex=0;
        }
        playlist_3->setCurrentIndex(currentIndex);
    }
     music->play();
}

//主窗口右键菜单 播放下一曲
void Widget::action10_slot()
{

    if(music->playlist()==playlist)
     {
        int currentIndex=playlist->currentIndex();
        ui->stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
        if(++currentIndex==playlist->mediaCount())
        {
            currentIndex=0;

        }
        playlist->setCurrentIndex(currentIndex);

    }
    else if(music->playlist()==playlist_2)
    {
        int currentIndex=playlist_2->currentIndex();
        ui->stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        if(++currentIndex==playlist_2->mediaCount())
        {
            currentIndex=0;

        }
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if(music->playlist()==playlist_3)
    {

        int currentIndex=playlist_3->currentIndex();
        ui->stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        if(++currentIndex==playlist_3->mediaCount())
        {
            currentIndex=0;

        }
        playlist_3->setCurrentIndex(currentIndex);

    }
    music->play();
}

//播放暂停
void Widget::action11_slot()
{
   if(music->state()==QMediaPlayer::PlayingState)
   {
       music->pause();
   }
   else
   {
       music->play();
   }

}

//主窗口右键菜单 顺序播放
void Widget::action12_1_slot()
{
    ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137007_easyicon.net.png"));
    ui->pushButton_9->setToolTip(tr("顺序播放"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist_2->setPlaybackMode(QMediaPlaylist::Loop);
    playlist_3->setPlaybackMode(QMediaPlaylist::Loop);

}
//主窗口右键菜单 随机播放
void Widget::action12_2_slot()
{

    ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137005_easyicon.net.png"));
    ui->pushButton_9->setToolTip(tr("随机播放"));
    playlist->setPlaybackMode(QMediaPlaylist::Random);
    playlist_2->setPlaybackMode(QMediaPlaylist::Random);
    playlist_3->setPlaybackMode(QMediaPlaylist::Random);
}
//主窗口右键菜单 单曲循环
void Widget::action12_3_slot()
{

    ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137006_easyicon.net.png"));
    ui->pushButton_9->setToolTip(tr("单曲循环"));
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    playlist_2->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    playlist_3->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

}

//播放and暂停
void Widget::on_pushButton_2_clicked()
{

   if(music->state()==QMediaPlayer::PlayingState)
    {
       ui->pushButton_2->setIcon(QIcon(":/image/image/control_play_48px_1116020_easyicon.net.png"));
       ui->pushButton_2->setToolTip(tr("暂停"));
       music->pause();


    }
    else
    {
       ui->pushButton_2->setIcon(QIcon(":/image/image/control_pause_48px_1116018_easyicon.net.png"));
       ui->pushButton_2->setToolTip(tr("播放"));
       music->play();

    }
}

void Widget::on_pushButton_3_clicked()//播放下一曲
{

    if(music->playlist()==playlist)
     {
        int currentIndex=playlist->currentIndex();
        ui->stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
        if(++currentIndex==playlist->mediaCount())
        {
            currentIndex=0;

        }
        playlist->setCurrentIndex(currentIndex);

    }
    else if(music->playlist()==playlist_2)
    {
        int currentIndex=playlist_2->currentIndex();
        ui->stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        if(++currentIndex==playlist_2->mediaCount())
        {
            currentIndex=0;

        }
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if(music->playlist()==playlist_3)
    {

        int currentIndex=playlist_3->currentIndex();
        ui->stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        if(++currentIndex==playlist_3->mediaCount())
        {
            currentIndex=0;

        }
        playlist_3->setCurrentIndex(currentIndex);

    }
    music->play();

}

void Widget::on_pushButton_4_clicked()//播放上一曲
{

    if(music->playlist()==playlist)
    {

        int currentIndex=playlist->currentIndex();
        ui->stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
        if(--currentIndex<0)
        {

            currentIndex=0;


        }
       playlist->setCurrentIndex(currentIndex);

    }
    else if(music->playlist()==playlist_2)
    {

        int currentIndex=playlist_2->currentIndex();
        ui->stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        if(--currentIndex<0)
        {
            currentIndex=0;
        }
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if(music->playlist()==playlist_3)
    {
        int currentIndex=playlist_3->currentIndex();
        ui->stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        if(--currentIndex<0)
        {
            currentIndex=0;
        }
        playlist_3->setCurrentIndex(currentIndex);
    }
     music->play();
}
void Widget::updatalistwidget_3(int value)//更新listWidget_3
{

   ui->listWidget_3->item(value)->setSelected(true);

}
void Widget::updatalistwidget_2(int value)//更新listWidget_2
{

   ui->listWidget_2->item(value)->setSelected(true);


}
void Widget::updatalistwidget(int value)//更新listWidget
{

    ui->listWidget->item(value)->setSelected(true);

}

void Widget::on_listWidget_3_doubleClicked(const QModelIndex &index)//双击播放playlist
{
    music->setPlaylist(playlist);
    playlist->setCurrentIndex(ui->listWidget_3->currentIndex().row());
    music->play();
}
void Widget::music_stateChang(QMediaPlayer::State state)//播放状态改变
{


    if(state==QMediaPlayer::PlayingState)
    {
        ui->pushButton_2->setIcon(QIcon(":/image/image/control_pause_48px_1116018_easyicon.net.png"));
        ui->pushButton_2->setToolTip(tr("播放"));


    }
    else
    {

        ui->pushButton_2->setIcon(QIcon(":/image/image/control_play_48px_1116020_easyicon.net.png"));
        ui->pushButton_2->setToolTip(tr("暂停"));

    }
}
//隐藏stackedWidget
void Widget::on_pushButton_15_clicked()
{
    if(ui->stackedWidget->isHidden())
    {
        ui->pushButton_15->setIcon(QIcon(":/image/image/arrow_left_square_32px_1187786_easyicon.net.png"));
        ui->pushButton_15->setToolTip(tr("隐藏播放列表"));
        ui->stackedWidget->show();
        ui->pushButton_10->show();
        ui->pushButton_11->show();
        ui->pushButton_12->show();
        ui->label->move(QPoint(340,520));
        ui->pushButton_15->move(QPoint(260,10));
        ui->label_3->move(350,390);
        ui->label_4->move(540,430);
    }
    else
    {
        ui->pushButton_15->setIcon(QIcon(":/image/image/arrow_right_square_32px_1187789_easyicon.net.png"));
        ui->pushButton_15->setToolTip(tr("显示播放列表"));
        ui->stackedWidget->hide();
        ui->pushButton_10->hide();
        ui->pushButton_11->hide();
        ui->pushButton_12->hide();
        ui->label->move(QPoint(200,520));
        ui->pushButton_15->move(QPoint(10,10));
        ui->label_3->move(100,390);
        ui->label_4->move(410,430);
    }
}

//播放模式
void Widget::on_pushButton_9_clicked()
{

    if(playlist->playbackMode()==QMediaPlaylist::Loop)
    {
        ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137005_easyicon.net.png"));
        ui->pushButton_9->setToolTip(tr("随机播放"));
        playlist->setPlaybackMode(QMediaPlaylist::Random);
        playlist_2->setPlaybackMode(QMediaPlaylist::Random);
        playlist_3->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if(playlist->playbackMode()==QMediaPlaylist::Random)
    {
        ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137006_easyicon.net.png"));
        ui->pushButton_9->setToolTip(tr("单曲循环"));
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playlist_2->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playlist_3->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);


    }
    else if(playlist->playbackMode()==QMediaPlaylist::CurrentItemInLoop)
    {
        ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137007_easyicon.net.png"));
        ui->pushButton_9->setToolTip(tr("顺序播放"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        playlist_2->setPlaybackMode(QMediaPlaylist::Loop);
        playlist_3->setPlaybackMode(QMediaPlaylist::Loop);

    }

}

void Widget::on_listWidget_2_doubleClicked(const QModelIndex &index)//双击播放playlist_2
{


      music->setPlaylist(playlist_2);
      playlist_2->setCurrentIndex( ui->listWidget_2->currentIndex().row());
      music->play();


}


void Widget::on_listWidget_doubleClicked(const QModelIndex &index)//双击播放playlist_3
{

       music->setPlaylist(playlist_3);
       playlist_3->setCurrentIndex( ui->listWidget->currentIndex().row());
       music->play();



}


void Widget::on_pushButton_7_clicked()//定位
{


    if(music->playlist()==playlist)
    {
        ui->stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
        ui->listWidget_3->item(playlist->currentIndex())->setSelected(true);

    }
    else if(music->playlist()==playlist_2)
    {

        ui->stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        ui->listWidget_2->item(playlist_2->currentIndex())->setSelected(true);

    }
    else if(music->playlist()==playlist_3)
    {

        ui->stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        ui->listWidget->item(playlist_3->currentIndex())->setSelected(true);
    }

}
void Widget::mousePressEvent(QMouseEvent *event)//拖拽
{


        offset=event->globalPos()-pos();
        event->accept();
        ui->verticalSlider->hide();


}
void Widget::mouseMoveEvent(QMouseEvent *event)//拖拽
{
 move(event->globalPos()-offset);
        event->accept();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)//拖拽
{
    offset=QPoint();
    event->accept();

}
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    hide();
    int i;
    if(music->playlist()==playlist)
    {
        i=0;
    }
    else if(music->playlist()==playlist_2)
    {
        i=1;
    }
    else
    {
        i=2;
    }
    Music->setPlaylist(music->playlist(),music->playlist()->currentIndex(),music->position(),music->volume(),music->state(),playlist->playbackMode(),i);
    music->pause();
    if(Music->exec()==Dialog::Accepted)
    {
      show();
    }

}

void Widget::contextMenuEvent(QContextMenuEvent *event)//主窗口右键菜单
{

    menu = new QMenu(this);
    menu->addAction(action1);
    menu->addAction(action2);
    menu->addAction(action3);
    menu->addAction(action9);
    menu->addAction(action10);
    menu->addAction(action11);
    menu->addAction(ClearALL_3);
    menu->addAction(action12);
    menu->addAction(ClearALL);
    menu->addAction(detila);
    menu->addAction(action13);
    menu->exec(QCursor::pos());

}

void Widget::on_pushButton_17_clicked()//关闭
{
    close();
}

void Widget::on_pushButton_16_clicked()//最小化
{
    showMinimized();

}

void Widget::on_pushButton_8_clicked()//隐藏verticalSlider
{
   if(ui->verticalSlider->isHidden())
        ui->verticalSlider->show();
   else
    ui->verticalSlider->hide();
}

//改变音量
void Widget::changeVolume(int values)
{
    if(values==0)
    {
        ui->pushButton_8->setIcon(QIcon(":/image/image/jy.png"));
    }
    else
    {
        ui->pushButton_8->setIcon(QIcon(":/image/image/yingliang.png"));
    }
    music->setVolume(values);

}

//listWidget_3右键菜单
void Widget::on_listWidget_3_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem *curItem=ui->listWidget_3->itemAt(pos);
    if(curItem==NULL)
    {
        return ;
    }
    QMenu *Menu=new QMenu(this);
    QAction *Action1=new QAction(this);
    QAction *Action2=new QAction(this);
    QAction *Action4=new QAction(this);
    QAction *Action3=new QAction(this);
    QAction *Action5=new QAction(this);
    Action1->setIcon(QIcon(":/image/image/bofang1.png"));
    Action1->setText(tr("播放/暂停"));
    Action2->setIcon(QIcon(":/image/image/like_outline_32px_1170275_easyicon.net.png"));
    Action2->setText(tr("添加至我喜欢"));
    Action4->setIcon(QIcon(":/image/image/list_32px_1142913_easyicon.net.png"));
    Action4->setText(tr("添加至播放队列"));
    Action3->setIcon(QIcon(":/image/image/delete_32px_1168909_easyicon.net.png"));
    Action3->setText(tr("删除"));
    Action5->setIcon(QIcon(":/image/image/inf.png"));
    Action5->setText(tr("歌曲信息"));
    Menu->addAction(Action1);
    Menu->addAction(Action2);
    Menu->addAction(Action4);
    Menu->addAction(Action5);
    Menu->addAction(Action3);
    connect(Action1,&QAction::triggered,this,&Widget::Action1_slot);
    connect(Action2,&QAction::triggered,this,&Widget::Action2_slot);
    connect(Action4,&QAction::triggered,this,&Widget::Action4_slot);
    connect(Action3,&QAction::triggered,this,&Widget::Action3_slot);
    connect(Action5,&QAction::triggered,this,&Widget::Action5_slot);
    Menu->exec(QCursor::pos());
    delete Menu;
    delete Action1;
    delete Action2;
    delete Action3;
    delete Action4;
    delete Action5;


}
void Widget::Action1_slot()//listWidget_3右键菜单 1
{



if(music->playlist()==playlist)
{
    if(ui->listWidget_3->item(playlist->currentIndex())->isSelected())
    {

        if(music->state()==QMediaPlayer::PlayingState)
        {

            music->pause();
        }
        else
        {
            music->play();
        }
    }
    else
    {
        playlist->setCurrentIndex(ui->listWidget_3->currentIndex().row());
        music->play();

    }
}
    else
    {
     music->setPlaylist(playlist);
    playlist->setCurrentIndex(ui->listWidget_3->currentIndex().row());
    music->play();
    }

}
void Widget::Action2_slot()//listWidget_3右键菜单 2
{
    model->setTable("HAHAHA");
    model->select();
    int row=ui->listWidget_3->currentIndex().row();
    int flag=model->data(model->index(row,3)).toInt();
    if(flag==0)
    {
    QString Text=ui->listWidget_3->item(row)->text();
    QListWidgetItem *ITEMM=new QListWidgetItem;
    ITEMM->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
    ITEMM->setText(QString("%1").arg(Text));
    ui->listWidget_2->addItem(ITEMM);
    QSqlQuery query;
    playlist_2->addMedia(playlist->media(row));
    model->setTable("HAHAHA");
    model->select();
    QString MusicName=model->data(model->index(row,1)).toString();
    QString FileName=model->data(model->index(row,2)).toString();

    model->setData(model->index(row,3),1);
    model->submitAll();
    query.exec("select * from I_LIKE_DATA");
    query.exec(QString("insert into I_LIKE_DATA values (%1,'%2','%3')").arg(qrand()%10000).arg(MusicName).arg(FileName));
    ui->stackedWidget->setCurrentIndex(1);
    pushbuttonstyle_2();
    if(music->playlist()==playlist)
    {

    if(playlist->currentIndex()==row)
{
    ui->pushButton_14->setIcon(QIcon(":/image/image/like_32px_1101682_easyicon.net.png"));
    ui->pushButton_14->setToolTip(tr("我喜欢"));
}

    }
    }
    else
    {

     QMessageBox::information(this,tr("提示"),tr("该歌曲已添加                              ."),QMessageBox::Yes);

    }
}
void Widget::Action4_slot()//listWidget_3右键菜单 4
{


    int row=ui->listWidget_3->currentIndex().row();
    QString Text=ui->listWidget_3->item(row)->text();
    QListWidgetItem *ITEMM1=new QListWidgetItem;
    ITEMM1->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
    ITEMM1->setText(QString("%1").arg(Text));
    ui->listWidget->addItem(ITEMM1);
    model->setTable("HAHAHA");
    model->select();
    playlist_3->addMedia(playlist->media(row));
    QSqlQuery query;
    QString MusicName=model->data(model->index(row,1)).toString();
    QString FileName=model->data(model->index(row,2)).toString();

    query.exec("select * from NIMA");
    query.exec(QString("insert into NIMA values (%1,'%2','%3')").arg(qrand()%10000).arg(MusicName).arg(FileName));
    ui->stackedWidget->setCurrentIndex(2);
    pushbuttonstyle_3();

}
void Widget::Action5_slot()
{
    int row=ui->listWidget_3->currentIndex().row();
    QString temp=ui->listWidget_3->currentIndex().data().toString();
    QString MusicName=temp.split(" - ").last();
    QString Author=temp.remove(" - "+MusicName);
    model->setTable("HAHAHA");
    model->select();
    QString FileName=model->data(model->index(row,2)).toString();
    QString time;
    if(music->playlist()==playlist)
    {

        if(row=playlist->currentIndex())
        {
            time=Time(music->duration());
        }
        else
        {
            time="00:00";
        }
    }
    else
    {
        time="00:00";
    }
    QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名 : %1  \n"
                                             "作者 : %2 \n"
                                             "时长 : %3\n "
                                             "文件路径 : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));

}

void Widget::Action3_slot()//listWidget_3右键菜单 3
{
  if(music->playlist()==playlist)
  {
    int Row=playlist->currentIndex();
    int row=ui->listWidget_3->currentIndex().row();
    if(row<Row)
    {
        int Position;
        if(music->state()==QMediaPlayer::PlayingState)
        {
            Position=music->position();
        }
        playlist->setCurrentIndex(0);
        ui->listWidget_3->takeItem(row);
        playlist->removeMedia(row,row);
        model->setTable("HAHAHA");
        model->select();
        model->removeRow(row);
        model->submitAll();
        music->setPlaylist(playlist);
        playlist->setCurrentIndex(Row-1);
        music->setPosition(Position);
        ui->horizontalSlider->setValue(Position);
        music->play();
    }
    else
    {
        ui->listWidget_3->takeItem(row);
        playlist->removeMedia(row,row);
        model->setTable("HAHAHA");
        model->select();
        model->removeRow(row);
        model->submitAll();
    }
}
else
{
    int row=ui->listWidget_3->currentIndex().row();
    ui->listWidget_3->takeItem(row);
    playlist->removeMedia(row,row);
    model->setTable("HAHAHA");
    model->select();
    model->removeRow(row);
    model->submitAll();
}

}

void Widget::on_listWidget_2_customContextMenuRequested(const QPoint &pos)//listWidget_2右键菜单
{
    QListWidgetItem *curItem1=ui->listWidget_2->itemAt(pos);
    if(curItem1==NULL)
    {
        return ;
    }
    QMenu *Menu1=new QMenu(this);
    QAction *Action1_2=new QAction(this);
    QAction *Action2_2=new QAction(this);
    QAction *Action3_2=new QAction(this);
    QAction *Action4_2=new QAction(this);
    Action1_2->setIcon(QIcon(":/image/image/bofang1.png"));
    Action1_2->setText(tr("播放/暂停"));

    Action3_2->setIcon(QIcon(":/image/image/list_32px_1142913_easyicon.net.png"));
    Action3_2->setText(tr("添加至播放队列"));

    Action2_2->setIcon(QIcon(":/image/image/delete_32px_1168909_easyicon.net.png"));
    Action2_2->setText(tr("移除"));
    Action4_2->setIcon(QIcon(":/image/image/inf.png"));
    Action4_2->setText(tr("歌曲信息"));
    Menu1->addAction(Action1_2);
    Menu1->addAction(Action3_2);
    Menu1->addAction(Action4_2);
    Menu1->addAction(Action2_2);
    connect(Action1_2,&QAction::triggered,this,&Widget::Action1_2_slot);
    connect(Action2_2,&QAction::triggered,this,&Widget::Action2_2_slot);
    connect(Action3_2,&QAction::triggered,this,&Widget::Action3_2_slot);
    connect(Action4_2,&QAction::triggered,this,&Widget::Action4_2_slot);
    Menu1->exec(QCursor::pos());
    delete Menu1;
    delete Action1_2;
    delete Action2_2;
    delete Action3_2;
    delete Action4_2;

}
void Widget::Action1_2_slot()//listWidget_2右键菜单 1
{

    if(music->playlist()==playlist_2)
    {
    if(ui->listWidget_2->item(playlist_2->currentIndex())->isSelected())
    {


        if(music->state()==QMediaPlayer::PlayingState)
        {
            music->pause();
        }
        else
        {
            music->play();
        }
    }
    else
    {
        playlist_2->setCurrentIndex(ui->listWidget_2->currentIndex().row());

        music->play();
    }
    }
    else
    {
        music->setPlaylist(playlist_2);
    playlist_2->setCurrentIndex(ui->listWidget_2->currentIndex().row());

    music->play();
    }

}
void Widget::Action3_2_slot()
{

    int row=ui->listWidget_2->currentIndex().row();
    QString Text=ui->listWidget_2->item(row)->text();
    QListWidgetItem *ITEMM1=new QListWidgetItem;
    ITEMM1->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
    ITEMM1->setText(QString("%1").arg(Text));
    ui->listWidget->addItem(ITEMM1);
    model_2->setTable("I_LIKE_DATA");
    model_2->select();
    playlist_3->addMedia(playlist_2->media(row));
    QSqlQuery query;
    QString MusicName=model_2->data(model_2->index(row,1)).toString();
    QString FileName=model_2->data(model_2->index(row,2)).toString();

    query.exec("select * from NIMA");
    query.exec(QString("insert into NIMA values (%1,'%2','%3')").arg(qrand()%10000).arg(MusicName).arg(FileName));
    ui->stackedWidget->setCurrentIndex(2);
    pushbuttonstyle_3();
}
void Widget::Action4_2_slot()
{

    int row=ui->listWidget_2->currentIndex().row();
    QString temp=ui->listWidget_2->currentIndex().data().toString();
    QString MusicName=temp.split(" - ").last();
    QString Author=temp.remove(" - "+MusicName);
    model_2->setTable("I_LIKE_DATA");
    model_2->select();
    QString FileName=model_2->data(model_2->index(row,2)).toString();
    QString time;
    if(music->playlist()==playlist_2)
    {

        if(row=playlist_2->currentIndex())
        {
            time=Time(music->duration());
        }
        else
        {
            time="00:00";
        }
    }
    else
    {
        time="00:00";
    }
    QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名 : %1  \n"
                                             "作者 : %2 \n"
                                             "时长 : %3 \n"
                                             "文件路径 : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));

}

void Widget::Action2_2_slot()//listWidget_2右键菜单 2
{
    QString MusicName=ui->listWidget_2->currentItem()->text();
    if(music->playlist()==playlist_2)
    {

        int Row=playlist_2->currentIndex();
        int row=ui->listWidget_2->currentIndex().row();

        if(row<Row)
        {
            int Position;
            if(music->state()==QMediaPlayer::PlayingState)
            {

                Position=music->position();
            }
            playlist_2->setCurrentIndex(0);
            ui->listWidget_2->takeItem(row);
            playlist_2->removeMedia(row,row);
            model_2->setTable("I_LIKE_DATA");
            model_2->select();
            model_2->removeRow(row);
            model_2->submitAll();

            music->setPlaylist(playlist_2);
            playlist_2->setCurrentIndex(Row-1);
            music->setPosition(Position);
            ui->horizontalSlider->setValue(Position);
            music->play();
        }
        else
        {
            ui->listWidget_2->takeItem(row);
            playlist_2->removeMedia(row,row);
            model_2->setTable("I_LIKE_DATA");
            model_2->select();
            model_2->removeRow(row);
            model_2->submitAll();
        }
    }
    else
    {
        int row=ui->listWidget_2->currentIndex().row();
        ui->listWidget_2->takeItem(row);
        playlist_2->removeMedia(row,row);
        model_2->setTable("I_LIKE_DATA");
        model_2->select();
        model_2->removeRow(row);
        model_2->submitAll();
    }
    QSqlQuery query;
    query.exec("select * from HAHAHA");
    query.prepare(QString("update HAHAHA set biaoji = ? where MusicName = '%1' ").arg(MusicName));
    query.bindValue(0,0);
    query.exec();
}

void Widget::on_listWidget_customContextMenuRequested(const QPoint &pos)//listWidget右键菜单
{
    QListWidgetItem *curItem2=ui->listWidget->itemAt(pos);
    if(curItem2==NULL)
    {
        return ;
    }
    QMenu *Menu2=new QMenu(this);
    QAction *Action1_3=new QAction(this);
    QAction *Action3_3=new QAction(this);
    QAction *Action2_3=new QAction(this);
    Action1_3->setIcon(QIcon(":/image/image/bofang1.png"));
    Action1_3->setText(tr("播放/暂停"));
    Action2_3->setIcon(QIcon(":/image/image/delete_32px_1168909_easyicon.net.png"));
    Action2_3->setText(tr("移除"));
    Action3_3->setIcon(QIcon(":/image/image/inf.png"));
    Action3_3->setText(tr("歌曲信息"));
    Menu2->addAction(Action1_3);
    Menu2->addAction(Action3_3);
    Menu2->addAction(Action2_3);
    connect(Action1_3,&QAction::triggered,this,&Widget::Action1_3_slot);
    connect(Action2_3,&QAction::triggered,this,&Widget::Action2_3_slot);
    connect(Action3_3,&QAction::triggered,this,&Widget::Action3_3_slot);
    Menu2->exec(QCursor::pos());
    delete Menu2;
    delete Action1_3;
    delete Action2_3;

}
void Widget::Action1_3_slot()//listWidget右键菜单 1
{

    if(music->playlist()==playlist_3)
    {


    if(ui->listWidget->item(playlist_3->currentIndex())->isSelected())
    {

        if(music->state()==QMediaPlayer::PlayingState)
        {
            music->pause();
        }
        else
        {
            music->play();
        }
    }
    else
    {

        playlist_3->setCurrentIndex(ui->listWidget->currentIndex().row());
        music->play();
    }

    }
    else
    {
        music->setPlaylist(playlist_3);
    playlist_3->setCurrentIndex(ui->listWidget->currentIndex().row());
    music->play();
    }

}
void Widget::Action3_3_slot()
{

    int row=ui->listWidget->currentIndex().row();
    QString temp=ui->listWidget->currentIndex().data().toString();
    QString MusicName=temp.split(" - ").last();
    QString Author=temp.remove(" - "+MusicName);
    model_3->setTable("NIMA");
    model_3->select();
    QString FileName=model_3->data(model_3->index(row,2)).toString();
    QString time;
    if(music->playlist()==playlist_3)
    {

        if(row=playlist_3->currentIndex())
        {
            time=Time(music->duration());
        }
        else
        {
            time="00:00";
        }
    }
    else
    {
        time="00:00";
    }
    QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名 : %1  \n"
                                             "作者 : %2 \n"
                                             "时长 : %3 \n"
                                             "文件路径 : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));
}

void Widget::Action2_3_slot()//listWidget右键菜单 2
{
    if(music->playlist()==playlist_3)
    {

        int Row=playlist_3->currentIndex();
        int row=ui->listWidget->currentIndex().row();
        if(row<Row)
        {
            int Position;
            if(music->state()==QMediaPlayer::PlayingState)
            {

                Position=music->position();
            }
            playlist_3->setCurrentIndex(0);
            ui->listWidget->takeItem(row);
            playlist_3->removeMedia(row,row);
            model_3->setTable("NIMA");
            model_3->select();
            model_3->removeRow(row);
            model_3->submitAll();

            music->setPlaylist(playlist_3);
            playlist_3->setCurrentIndex(Row-1);
            music->setPosition(Position);
            ui->horizontalSlider->setValue(Position);
            music->play();
        }
        else
        {
            ui->listWidget->takeItem(row);
            playlist_3->removeMedia(row,row);
            model_3->setTable("NIMA");
            model_3->select();
            model_3->removeRow(row);
            model_3->submitAll();

        }


    }
    else
    {
        int row=ui->listWidget->currentIndex().row();
        ui->listWidget->takeItem(row);
        playlist_3->removeMedia(row,row);
        model_3->setTable("NIMA");
        model_3->select();
        model_3->removeRow(row);
        model_3->submitAll();
    }

}


void Widget::on_pushButton_13_clicked()
{

    hide();
    int i;
    if(music->playlist()==playlist)
    {
        i=0;
    }
    else if(music->playlist()==playlist_2)
    {
        i=1;
    }
    else
    {
        i=2;
    }
    Music->setPlaylist(music->playlist(),music->playlist()->currentIndex(),music->position(),music->volume(),music->state(),playlist->playbackMode(),i);
    music->pause();
    if(Music->exec()==Dialog::Accepted)
    {

        show();

    }


}

void Widget::Data_slot(int row,int position,QMediaPlaylist *list,QMediaPlayer::State state,QMediaPlaylist::PlaybackMode model)
{
    playlist->setPlaybackMode(model);
    playlist_2->setPlaybackMode(model);
    playlist_3->setPlaybackMode(model);
    if(list==playlist)
    {


        playlist->setCurrentIndex(row);
        music->setPosition(position);
        if(state==QMediaPlayer::PlayingState)
        music->play();


    }
    else  if(list==playlist)
    {


        playlist_2->setCurrentIndex(row);
        music->setPosition(position);
        if(state==QMediaPlayer::PlayingState)
        music->play();


    }
    else
    {
       playlist_3->setCurrentIndex(row);
       music->setPosition(position);
       if(state==QMediaPlayer::PlayingState)
       music->play();

    }

}

void Widget::on_pushButton_14_clicked()
{
    if(music->playlist()==playlist)
    {

        int row=playlist->currentIndex();
        model->setTable("HAHAHA");
        model->select();
        int flag=model->data(model->index(row,3)).toInt();
        if(flag==0)
        {
            ui->pushButton_14->setIcon(QIcon(":/image/image/like_32px_1101682_easyicon.net.png"));
            ui->pushButton_14->setToolTip(tr("我喜欢"));
            int row=playlist->currentIndex();
            QString Text=ui->listWidget_3->item(row)->text();
            QListWidgetItem *ITEMM2=new QListWidgetItem;
            ITEMM2->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
            ITEMM2->setText(QString("%1").arg(Text));
            ui->listWidget_2->addItem(ITEMM2);
            playlist_2->addMedia(playlist->media(row));
            QSqlQuery query;
            model->setTable("HAHAHA");
            model->select();
            QString MusicName=model->data(model->index(row,1)).toString();
            QString FileName=model->data(model->index(row,2)).toString();
            model->setData(model->index(row,3),1);
            model->submitAll();
            query.exec("select * from I_LIKE_DATA");
            query.exec(QString("insert into I_LIKE_DATA values (%1,'%2','%3')").arg(qrand()%10000).arg(MusicName).arg(FileName));
        }

    }

}

//搜索歌曲
void Widget::on_pushButton_18_clicked()
{
    QString text=ui->lineEdit->text();
    if(text!="")
    {
    load.clear();
    ui->listWidget_4->clear();
   std::string MusicName=ui->lineEdit->text().toStdString();
   const char* MusicName1=MusicName.c_str();
   ui->stackedWidget->setCurrentIndex(3);
   int Count=ui->listWidget_3->count();
   pushbuttonstyle_4();
   for(int i=0;i<Count;i++)
   {

       QString Text=ui->listWidget_3->item(i)->text();
       QString Name=Text.split("- ").last();
       std::string Name1=Name.toStdString();
       const  char *Name2=Name1.c_str();
       QString Author=Text.remove(" - "+Name);
       std::string Author1=Author.toStdString();
       const char *Author2=Author1.c_str();
       if(strstr(Name2,MusicName1)||strstr(Author2,MusicName1))
       {
        QString Text=ui->listWidget_3->item(i)->text();
        QListWidgetItem *item20=new QListWidgetItem;
        item20->setIcon(QIcon(":/image/image/sss.png"));
        item20->setText(Text);
        ui->listWidget_4->addItem(item20);
        load.push_back(i);

       }
   }
   ui->lineEdit->clear();
}
}

void Widget::on_listWidget_4_doubleClicked(const QModelIndex &index)
{

    music->setPlaylist(playlist);
    playlist->setCurrentIndex(load[ui->listWidget_4->currentIndex().row()]);
    music->play();
}

void Widget::on_listWidget_4_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem *ITEM20=ui->listWidget_4->itemAt(pos);
    if(ITEM20==NULL)
    {

        return ;
    }
    QMenu *MENU20=new QMenu(this);
    QAction *Action =new QAction(this);
    QAction *Action1 =new QAction(this);
    QAction *Action2 =new QAction(this);
    QAction *Action3 =new QAction(this);
    QAction *Action4 =new QAction(this);
    Action->setIcon(QIcon(":/image/image/bofang1.png"));
    Action->setText(tr("播放/暂停"));
    Action1->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
    Action1->setText(tr("添加至我喜欢"));
    Action2->setIcon(QIcon(":/image/image/list_32px_1074296_easyicon.net.png"));
    Action2->setText(tr("添加至播放队列"));
    Action3->setIcon(QIcon(":/image/image/delete_32px_1168909_easyicon.net.png"));
    Action3->setText(tr("删除歌曲"));
    Action4->setIcon(QIcon(":/image/image/inf.png"));
    Action4->setText(tr("歌曲信息"));
    connect(Action,&QAction::triggered,this,&Widget::Action_slot);
    connect(Action1,&QAction::triggered,this,&Widget::Action_1_slot);
    connect(Action2,&QAction::triggered,this,&Widget::Action_2_slot);
    connect(Action3,&QAction::triggered,this,&Widget::Action_3_slot);
    connect(Action4,&QAction::triggered,this,&Widget::Action_4_slot);
    MENU20->addAction(Action);
    MENU20->addAction(Action1);
    MENU20->addAction(Action2);
    MENU20->addAction(Action4);
    MENU20->addAction(Action3);
    MENU20->exec(QCursor::pos());
    delete Action;
    delete Action1;
    delete Action2;
    delete Action3;
    delete Action4;
    delete MENU20;
}
void Widget::Action_slot()
{

    int row=ui->listWidget_4->currentIndex().row();

    if(music->playlist()==playlist)
    {

        if(load[row]==playlist->currentIndex())
        {

            if(music->state()==QMediaPlayer::PlayingState)
            {

                music->pause();
            }
            else
            {
                music->play();
            }
        }
        else
        {
            playlist->setCurrentIndex(load[row]);

            music->play();

            ui->listWidget_3->item(load[row])->setSelected(true);

        }
    }
        else
        {
         music->setPlaylist(playlist);
         playlist->setCurrentIndex(load[row]);
         music->play();
        }
}
void Widget::Action_1_slot()
{
    model->setTable("HAHAHA");
    model->select();
    int row=ui->listWidget_4->currentIndex().row();
    int flag=model->data(model->index(load[row],3)).toInt();
    if(flag==0)
    {
    QString Text=ui->listWidget_3->item(load[row])->text();
    QListWidgetItem *ITEMM=new QListWidgetItem;
    ITEMM->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
    ITEMM->setText(QString("%1").arg(Text));
    ui->listWidget_2->addItem(ITEMM);
    QSqlQuery query;
    playlist_2->addMedia(playlist->media(load[row]));
    model->setTable("HAHAHA");
    model->select();
    QString MusicName=model->data(model->index(load[row],1)).toString();
    QString FileName=model->data(model->index(load[row],2)).toString();

    model->setData(model->index(load[row],3),1);
    model->submitAll();
    query.exec("select * from I_LIKE_DATA");
    query.exec(QString("insert into I_LIKE_DATA values (%1,'%2','%3')").arg(qrand()%10000).arg(MusicName).arg(FileName));
    ui->stackedWidget->setCurrentIndex(1);
    pushbuttonstyle_2();
    if(music->playlist()==playlist)
    {

    if(playlist->currentIndex()==load[row])
    {
    ui->pushButton_14->setIcon(QIcon(":/image/image/like_32px_1101682_easyicon.net.png"));
    ui->pushButton_14->setToolTip(tr("我喜欢"));
    }

    }
    }
    else
    {
     QMessageBox::information(this,tr("提示"),tr("该歌曲已添加                              ."),QMessageBox::Yes);
    }

}
void Widget::Action_2_slot()
{
    int row=ui->listWidget_4->currentIndex().row();
    QString Text=ui->listWidget_3->item(load[row])->text();
    QListWidgetItem *ITEMM1=new QListWidgetItem;
    ITEMM1->setIcon(QIcon(":/image/image/music_not_25.570093457944px_1171234_easyicon.net.png"));
    ITEMM1->setText(QString("%1").arg(Text));
    ui->listWidget->addItem(ITEMM1);
    model->setTable("HAHAHA");
    model->select();
    playlist_3->addMedia(playlist->media(load[row]));
    QSqlQuery query;
    QString MusicName=model->data(model->index(load[row],1)).toString();
    QString FileName=model->data(model->index(load[row],2)).toString();

    query.exec("select * from NIMA");
    query.exec(QString("insert into NIMA values (%1,'%2','%3')").arg(qrand()%10000).arg(MusicName).arg(FileName));
    ui->stackedWidget->setCurrentIndex(2);
    pushbuttonstyle_3();


}
void Widget::Action_4_slot()
{
    int row=ui->listWidget_4->currentIndex().row();
    QString temp=ui->listWidget_4->currentIndex().data().toString();
    QString MusicName=temp.split(" - ").last();
    QString Author=temp.remove(" - "+MusicName);
    model->setTable("HAHAHA");
    model->select();
    QString FileName=model->data(model->index(load[row],2)).toString();
    QString time;
    if(music->playlist()==playlist)
    {
        if(load[row]=playlist->currentIndex())
        {
            time=Time(music->duration());
        }
        else
        {
            time="00:00";
        }
    }
    else
    {
        time="00:00";
    }
    QMessageBox::about(this,tr("歌曲信息"),tr("歌曲名 : %1  \n"
                                             "作者 : %2 \n"
                                             "时长 : %3 \n"
                                             "文件路径 : %4\n").arg(MusicName).arg(Author).arg(time).arg(FileName));
}

void Widget::Action_3_slot()
{

    if(music->playlist()==playlist)
    {

        int Row=playlist->currentIndex();
        int row=ui->listWidget_4->currentIndex().row();
        if(load[row]<Row)
        {
            int Position;
            if(music->state()==QMediaPlayer::PlayingState)
            {
                Position=music->position();
            }
            playlist->setCurrentIndex(0);
            ui->listWidget_3->takeItem(load[row]);
            ui->listWidget_4->takeItem(row);
            playlist->removeMedia(load[row],load[row]);
            model->setTable("HAHAHA");
            model->select();
            model->removeRow(load[row]);
            model->submitAll();
            music->setPlaylist(playlist);
            playlist->setCurrentIndex(Row-1);
            music->setPosition(Position);
            ui->horizontalSlider->setValue(Position);
            music->play();
        }
        else
        {
            ui->listWidget_4->takeItem(row);
            ui->listWidget_3->takeItem(load[row]);
            playlist->removeMedia(load[row],load[row]);
            model->setTable("HAHAHA");
            model->select();
            model->removeRow(load[row]);
            model->submitAll();

        }


    }
    else
    {
        int row=ui->listWidget_4->currentIndex().row();
        ui->listWidget_4->takeItem(row);
        ui->listWidget_3->takeItem(load[row]);
        playlist->removeMedia(load[row],load[row]);
        model->setTable("HAHAHA");
        model->select();
        model->removeRow(load[row]);
        model->submitAll();
    }
}

void Widget::CreateSortCut()
{
    QShortcut *QUIT=new QShortcut(QKeySequence::Quit,this);
    connect(QUIT,&QShortcut::activated,QCoreApplication::quit);

    QShortcut *play=new QShortcut(Qt::Key_Space,this);
    connect(play,&QShortcut::activated,this,&Widget::action11_slot);
    QShortcut *next=new QShortcut(Qt::Key_Right,this);
    QShortcut *next1=new QShortcut(Qt::Key_6,this);
    connect(next,&QShortcut::activated,this,&Widget::Next_slot);
    connect(next1,&QShortcut::activated,this,&Widget::Next_slot);
    QShortcut *pre=new QShortcut(Qt::Key_Left,this);
    QShortcut *pre1=new QShortcut(Qt::Key_4,this);
    connect(pre,&QShortcut::activated,this,&Widget::Pre_slot);
    connect(pre1,&QShortcut::activated,this,&Widget::Pre_slot);
    QShortcut *nextlist=new QShortcut(Qt::Key_D,this);
    connect(nextlist,&QShortcut::activated,this,&Widget::nextlist_slot);
    QShortcut *prelist=new QShortcut(Qt::Key_A,this);
    connect(prelist,&QShortcut::activated,this,&Widget::prelist_slot);
    QShortcut *addV=new QShortcut(Qt::Key_W,this);
    connect(addV,&QShortcut::activated,this,&Widget::addV_slot);
    QShortcut *subV=new QShortcut(Qt::Key_S,this);
    connect(subV,&QShortcut::activated,this,&Widget::subV_slot);
    QShortcut *Locole=new QShortcut(Qt::Key_Q,this);
    connect(Locole,&QShortcut::activated,this,&Widget::Locale_slot);
    QShortcut *change=new QShortcut(Qt::Key_E,this);
    connect(change,&QShortcut::activated,this,&Widget::change_slot);
    QShortcut *love=new QShortcut(Qt::Key_R,this);
    connect(love,&QShortcut::activated,this,&Widget::love_slot);



}
void Widget::Next_slot()
{

    if(music->playlist()==playlist)
     {
        int currentIndex=playlist->currentIndex();
        ui->stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
        if(++currentIndex==playlist->mediaCount())
        {
            currentIndex=0;

        }
        playlist->setCurrentIndex(currentIndex);

    }
    else if(music->playlist()==playlist_2)
    {
        int currentIndex=playlist_2->currentIndex();
        ui->stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        if(++currentIndex==playlist_2->mediaCount())
        {
            currentIndex=0;

        }
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if(music->playlist()==playlist_3)
    {

        int currentIndex=playlist_3->currentIndex();
        ui->stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        if(++currentIndex==playlist_3->mediaCount())
        {
            currentIndex=0;

        }
        playlist_3->setCurrentIndex(currentIndex);

    }
    music->play();
}
void Widget::Pre_slot()
{
    if(music->playlist()==playlist)
    {

        int currentIndex=playlist->currentIndex();
        ui->stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
        if(--currentIndex<0)
        {

            currentIndex=0;


        }
       playlist->setCurrentIndex(currentIndex);

    }
    else if(music->playlist()==playlist_2)
    {

        int currentIndex=playlist_2->currentIndex();
        ui->stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        if(--currentIndex<0)
        {
            currentIndex=0;
        }
        playlist_2->setCurrentIndex(currentIndex);
    }
    else if(music->playlist()==playlist_3)
    {
        int currentIndex=playlist_3->currentIndex();
        ui->stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        if(--currentIndex<0)
        {
            currentIndex=0;
        }
        playlist_3->setCurrentIndex(currentIndex);
    }
     music->play();


}
void Widget::nextlist_slot()
{
    int current=ui->stackedWidget->currentIndex();

    if(current<2)
    {
        current++;
        ui->stackedWidget->setCurrentIndex(current);
        if(current==0)
        {

            pushbuttonstyle();

        }
        else if(current==1)
        {

            pushbuttonstyle_2();

        }
        else
        {

            pushbuttonstyle_3();

        }

    }


}
void Widget::prelist_slot()
{

    int current=ui->stackedWidget->currentIndex();
    if(current>0)
    {

        current--;
        ui->stackedWidget->setCurrentIndex(current);

        if(current==0)
        {

            pushbuttonstyle();

        }
        else if(current==1)
        {

            pushbuttonstyle_2();

        }
        else
        {

            pushbuttonstyle_3();

        }


    }


}
void Widget::addV_slot()
{

    ui->verticalSlider->show();
    int values=ui->verticalSlider->value();
    if(values<100)
    {
        values++;
        ui->verticalSlider->setValue(values);
    }
}
void Widget::subV_slot()
{
    ui->verticalSlider->show();
    int values=ui->verticalSlider->value();
    if(values>0)
    {

        values--;
        ui->verticalSlider->setValue(values);

    }
}
void Widget::Locale_slot()
{


    if(music->playlist()==playlist)
    {
        ui->stackedWidget->setCurrentIndex(0);
        pushbuttonstyle();
        ui->listWidget_3->item(playlist->currentIndex())->setSelected(true);

    }
    else if(music->playlist()==playlist_2)
    {

        ui->stackedWidget->setCurrentIndex(1);
        pushbuttonstyle_2();
        ui->listWidget_2->item(playlist_2->currentIndex())->setSelected(true);

    }
    else if(music->playlist()==playlist_3)
    {

        ui->stackedWidget->setCurrentIndex(2);
        pushbuttonstyle_3();
        ui->listWidget->item(playlist_3->currentIndex())->setSelected(true);
    }
}
void Widget::change_slot()
{

    count2++;
    if(count2%3==1)
    {

        ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137005_easyicon.net.png"));
        ui->pushButton_9->setToolTip(tr("随机播放"));
        playlist->setPlaybackMode(QMediaPlaylist::Random);
        playlist_2->setPlaybackMode(QMediaPlaylist::Random);
        playlist_3->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if(count2%3==2)
    {
        ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137006_easyicon.net.png"));
        ui->pushButton_9->setToolTip(tr("单曲循环"));
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playlist_2->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        playlist_3->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);


    }
    else
    {
        ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137007_easyicon.net.png"));
        ui->pushButton_9->setToolTip(tr("顺序播放"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        playlist_2->setPlaybackMode(QMediaPlaylist::Loop);
        playlist_3->setPlaybackMode(QMediaPlaylist::Loop);

    }
}
void Widget::love_slot()
{

    if(music->playlist()==playlist)
    {

        int row=playlist->currentIndex();
        model->setTable("HAHAHA");
        model->select();
        int flag=model->data(model->index(row,3)).toInt();
        if(flag==0)
        {
            ui->pushButton_14->setIcon(QIcon(":/image/image/like_32px_1101682_easyicon.net.png"));
            ui->pushButton_14->setToolTip(tr("我喜欢"));
            int row=playlist->currentIndex();
            QString Text=ui->listWidget_3->item(row)->text();
            QListWidgetItem *ITEMM2=new QListWidgetItem;
            ITEMM2->setIcon(QIcon(":/image/image/like_outline_32px_1101681_easyicon.net.png"));
            ITEMM2->setText(QString("%1").arg(Text));
            ui->listWidget_2->addItem(ITEMM2);
            playlist_2->addMedia(playlist->media(row));
            QSqlQuery query;
            model->setTable("HAHAHA");
            model->select();
            QString MusicName=model->data(model->index(row,1)).toString();
            QString FileName=model->data(model->index(row,2)).toString();
            model->setData(model->index(row,3),1);
            model->submitAll();
            query.exec("select * from I_LIKE_DATA");
            query.exec(QString("insert into I_LIKE_DATA values (%1,'%2','%3')").arg(qrand()%10000).arg(MusicName).arg(FileName));
        }

    }

}

void Widget::on_lineEdit_returnPressed()
{
    QString text=ui->lineEdit->text();
    if(text!="")
    {
        load.clear();
    ui->listWidget_4->clear();
   std::string MusicName=ui->lineEdit->text().toStdString();
   const char* MusicName1=MusicName.c_str();
   ui->stackedWidget->setCurrentIndex(3);
   int Count=ui->listWidget_3->count();
   pushbuttonstyle_4();
   for(int i=0;i<Count;i++)
   {

       QString Text=ui->listWidget_3->item(i)->text();
       QString Name=Text.split("- ").last();
       std::string Name1=Name.toStdString();
       const  char *Name2=Name1.c_str();
       QString Author=Text.remove(" - "+Name);
       std::string Author1=Author.toStdString();
       const char *Author2=Author1.c_str();
       qDebug()<<Name;
       qDebug()<<Author;
       if(strstr(Name2,MusicName1)||strstr(Author2,MusicName1))
       {
        QString Text=ui->listWidget_3->item(i)->text();
        QListWidgetItem *item20=new QListWidgetItem;
        item20->setIcon(QIcon(":/image/image/sss.png"));
        item20->setText(Text);
        ui->listWidget_4->addItem(item20);
        load.push_back(i);
       }
   }
   ui->lineEdit->clear();
    }
}
void Widget::PlaylistModel_slot(QMediaPlaylist::PlaybackMode model)
{

    if(model==QMediaPlaylist::Loop)
    {
        ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137007_easyicon.net.png"));
        ui->pushButton_9->setToolTip(tr("顺序播放"));

    }
    else if(model==QMediaPlaylist::Random)
    {
        ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137005_easyicon.net.png"));
        ui->pushButton_9->setToolTip(tr("随机播放"));

    }
    else if(model==QMediaPlaylist::CurrentItemInLoop)
    {
        ui->pushButton_9->setIcon(QIcon(":/image/image/player-icons_32px_1137006_easyicon.net.png"));
        ui->pushButton_9->setToolTip(tr("单曲循环"));
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    }
}

