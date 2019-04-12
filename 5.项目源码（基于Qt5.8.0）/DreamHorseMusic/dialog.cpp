#include "dialog.h"
#include "ui_dialog.h"
#include<QPixmap>
#include<QPalette>
#include<QIcon>
#include<QMenu>
#include<QAction>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QShortcut>
#include<QFileDialog>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.next();
    QString FileName=query.value(0).toString();
    if(FileName=="")
    {
    pix.load(":/image/image/589d8aa99fd71a2af1b3c3ee (2).jpg");
    }
    else
    {

        pix.load(FileName);
    }
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);

    query.exec("select * from Toumin_DATA");
    query.next();
    QString Temp=query.value(0).toString();
    if(Temp=="")
    {
        TouMin=1.0;
    }
    else
    {
        TouMin=Temp.toDouble();
    }
    setWindowOpacity(TouMin);
    ui->pushButton_2->setIconSize(QSize(48,48));
    ui->pushButton_2->setIcon(QIcon(":/image/image/control_play_48px_1116020_easyicon.net.png"));
    ui->pushButton->setToolTip(tr("上一首"));
    ui->pushButton_2->setToolTip(tr("暂停"));
    ui->pushButton_3->setToolTip(tr("下一首"));
    ui->pushButton_4->setToolTip(tr("关闭"));
    ui->pushButton_5->setToolTip(tr("最小化"));
    ui->pushButton_6->setToolTip(tr("返回主窗口/双击"));
    ui->horizontalSlider->setToolTip(tr("播放进度"));

    music=new QMediaPlayer(this);
    playlist=new QMediaPlaylist(this);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    play=new QAction(this);
    next=new QAction(this);
    pre =new QAction(this);
    play->setIcon(QIcon(":/image/image/bofang1.png"));
    play->setText(tr("播放/暂停"));
    next->setIcon(QIcon(":/image/image/next1.png"));
    next->setText(tr("下一首"));
    pre->setIcon(QIcon(":/image/image/pre1.png"));
    pre->setText(tr("上一首"));

    action=new QAction(this);
    action1=new QAction(this);
    action2=new QAction(this);
    action3=new QAction(this);
    action4=new QAction(this);
    action->setIcon(QIcon(":/image/image/pf.png"));
    action->setText(tr("设置皮肤"));

    action1->setIcon(QIcon(":/image/image/pf2.png"));
    action1->setText(tr("默认皮肤1"));
    action2->setIcon(QIcon(":/image/image/pf5.png"));
    action2->setText(tr("默认皮肤2"));
    action3->setIcon(QIcon(":/image/image/pf3.png"));
    action3->setText(tr("默认皮肤3"));
    action4->setIcon(QIcon(":/image/image/pf4.png"));
    action4->setText(tr("自定义皮肤"));

    QMenu *Menu=new QMenu(this);
    Menu->addAction(action1);
    Menu->addAction(action2);
    Menu->addAction(action3);
    Menu->addAction(action4);
    action->setMenu(Menu);
    quit=new QAction(this);
    quit->setIcon(QIcon(":/image/image/tc.png"));

    quit->setText(tr("退出"));


    connect(music,&QMediaPlayer::metaDataAvailableChanged,this,&Dialog::updateText);
    connect(music,&QMediaPlayer::positionChanged,this,&Dialog::updatePosition);
    connect(music,&QMediaPlayer::durationChanged,this,&Dialog::updateDuration);
    connect(music,&QMediaPlayer::stateChanged,this,&Dialog::stateChange);
    connect(ui->horizontalSlider,&QSlider::sliderMoved,music,&QMediaPlayer::setPosition);
    connect(play,&QAction::triggered,this,&Dialog::play_slot);
    connect(next,&QAction::triggered,this,&Dialog::next_slot);
    connect(pre,&QAction::triggered,this,&Dialog::pre_slot);
    connect(action1,&QAction::triggered,this,&Dialog::action1_slot);
    connect(action2,&QAction::triggered,this,&Dialog::action2_slot);
    connect(action3,&QAction::triggered,this,&Dialog::action3_slot);
    connect(action4,&QAction::triggered,this,&Dialog::action4_slot);
    connect(quit,&QAction::triggered,this,&Dialog::quit_slot);
    connect(playlist,&QMediaPlaylist::playbackModeChanged,this,&Dialog::PlaybackModel_slot);

    ui->pushButton_7->setIconSize(QSize(32,32));
    ui->pushButton_7->setIcon(QIcon(":/image/image/player-icons_32px_1137007_easyicon.net.png"));
    ui->pushButton_7->setToolTip(tr("顺序播放"));

    ui->pushButton_8->setIconSize(QSize(32,32));
    ui->pushButton_8->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
    ui->pushButton_8->setToolTip(tr("本地音乐列表"));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_4_clicked()
{
    QCoreApplication::quit();
}

void Dialog::on_pushButton_6_clicked()
{
    emit Data(playlist->currentIndex(),music->position(),playlist,music->state(),playlist->playbackMode());
    music->pause();
    accept();
}

void Dialog::on_pushButton_5_clicked()
{
    showMinimized();
}
void Dialog::mousePressEvent(QMouseEvent *event)
{

    offset=event->globalPos()-pos();
    event->accept();

}
void Dialog::mouseMoveEvent(QMouseEvent *event)
{

    move(event->globalPos()-offset);
    event->accept();
}
void Dialog::mouseReleaseEvent(QMouseEvent *event)
{

    offset=QPoint();
    event->accept();
}
void Dialog::mouseDoubleClickEvent(QMouseEvent *event)
{
     emit Data(playlist->currentIndex(),music->position(),playlist,music->state(),playlist->playbackMode());

     music->pause();
     accept();
}

void Dialog::setPlaylist(QMediaPlaylist *list,int row,int position,int volume,QMediaPlayer::State state,QMediaPlaylist::PlaybackMode playmodel,int i)
{
    playlist=list;
    music->setPlaylist(playlist);
    playlist->setCurrentIndex(row);
    music->setPosition(position);
    music->setVolume(volume);

    if(state==QMediaPlayer::PlayingState)
        music->play();
    playlist->setPlaybackMode(playmodel);

    if(i==0)
    {
        ui->pushButton_8->setIcon(QIcon(":/image/image/Music_32px_1144946_easyicon.net.png"));
        ui->pushButton_8->setToolTip(tr("本地歌曲列表"));
    }
    else if(i==1)
    {
        ui->pushButton_8->setIcon(QIcon(":/image/image/like_32px_1101682_easyicon.net.png"));
        ui->pushButton_8->setToolTip(tr("我喜欢列表"));
    }
    else if(i==2)
    {
        ui->pushButton_8->setIcon(QIcon(":/image/image/list_32px_1074296_easyicon.net.png"));
        ui->pushButton_8->setToolTip(tr("播放队列列表"));
    }

}
void Dialog::updateText()
{

    QString Text;
    if(music->isMetaDataAvailable())
    {
        QString Title=music->metaData(QStringLiteral("Title")).toString();
        if(!Title.isEmpty())
            Text=Title;
        else
            Text+=tr("未知歌曲");
        Text+="-";
        QString Author=music->metaData(QStringLiteral("Author")).toString();
        if(!Author.isEmpty())
            Text+=Author;
        else
            Text+=tr("未知作者");
    }
    ui->label->setText(Text);

}
static QString Time(qint64 time)
{
    int sec=time/1000;
    int min=sec/60;
    sec-=min*60;
    return QStringLiteral("%1:%2")
            .arg(min, 2, 10, QLatin1Char('0'))
            .arg(sec, 2, 10, QLatin1Char('0'));
}
void Dialog::updatePosition(qint64 position)
{
    ui->horizontalSlider->setValue(position);
    ui->label_2->setText(Time(position)+"/"+Time(music->duration()));

}
void Dialog::updateDuration(qint64 duration)
{
    ui->horizontalSlider->setRange(0,duration);
    ui->horizontalSlider->setEnabled(duration>0);
    ui->horizontalSlider->setPageStep(duration/10);

}

void Dialog::on_pushButton_2_clicked()
{
    if(music->state()==QMediaPlayer::PlayingState)
    {
        music->pause();
        ui->pushButton_2->setIcon(QIcon(":/image/image/control_play_48px_1116020_easyicon.net.png"));
        ui->pushButton_2->setToolTip(tr("暂停"));
    }
    else
    {
        music->play();
        ui->pushButton_2->setIcon(QIcon(":/image/image/control_pause_48px_1116018_easyicon.net.png"));
        ui->pushButton_2->setToolTip(tr("播放"));
    }
}
void Dialog::stateChange(QMediaPlayer::State state)
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

void Dialog::on_pushButton_3_clicked()
{
    int currentIndex=playlist->currentIndex();
    if(++currentIndex==playlist->mediaCount())
        currentIndex=0;
    playlist->setCurrentIndex(currentIndex);
}

void Dialog::on_pushButton_clicked()
{
    int currentIndex=playlist->currentIndex();
    if(--currentIndex<0)
        currentIndex=0;
   playlist->setCurrentIndex(currentIndex);
}

void Dialog::contextMenuEvent(QContextMenuEvent *event)
{
    menu=new QMenu(this);
    menu->addAction(play);
    menu->addAction(next);
    menu->addAction(pre);
    menu->addAction(action);
    menu->addAction(quit);
    menu->exec(QCursor::pos());
}

void Dialog::play_slot()
{
    if(music->state()==QMediaPlayer::PlayingState)
        music->pause();
    else
        music->play();
}

void Dialog::next_slot()
{
    int currentIndex=playlist->currentIndex();
    if(++currentIndex==playlist->mediaCount())
        currentIndex=0;
    playlist->setCurrentIndex(currentIndex);
}
void Dialog::pre_slot()
{
    int currentIndex=playlist->currentIndex();
    if(--currentIndex<0)
        currentIndex=0;
   playlist->setCurrentIndex(currentIndex);
}
void Dialog::action1_slot()
{
    QString FileName=":/image/image/589d8aa99fd71a2af1b3c3ee (2).jpg";
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.exec("delete from Bizi_DATA");
    query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));

    pix.load(FileName);
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
}
void Dialog::action2_slot()
{
    QString FileName=":/image/image/5971bd2fe7bce76b7e577a90 (2).jpg";
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.exec("delete from Bizi_DATA");
    query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));

    pix.load(FileName);
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
}
void Dialog::action3_slot()
{
    QString FileName=":/image/image/nihao.jpg";
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.exec("delete from Bizi_DATA");
    query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));
    pix.load(FileName);
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
}
void Dialog::action4_slot()
{
QString FileName=QFileDialog::getOpenFileName(this,tr("文件"),"../DreamHorseMusic11/bgPicture",tr("图片文件(*jpg *png)"));
if(FileName!="")
{
    QSqlQuery query;
    query.exec("select * from Bizi_DATA");
    query.exec("delete from Bizi_DATA");
    query.exec(QString("insert into Bizi_DATA values ('%1')").arg(FileName));
    pix.load(FileName);
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);

}
}

void Dialog::quit_slot()
{
    QCoreApplication::quit();
}

void Dialog::on_pushButton_7_clicked()
{
    if(playlist->playbackMode()==QMediaPlaylist::Loop)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/player-icons_32px_1137005_easyicon.net.png"));
        ui->pushButton_7->setToolTip(tr("随机播放"));
        playlist->setPlaybackMode(QMediaPlaylist::Random);
    }
    else if(playlist->playbackMode()==QMediaPlaylist::Random)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/player-icons_32px_1137006_easyicon.net.png"));
        ui->pushButton_7->setToolTip(tr("单曲循环"));
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    }
    else if(playlist->playbackMode()==QMediaPlaylist::CurrentItemInLoop)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/player-icons_32px_1137007_easyicon.net.png"));
        ui->pushButton_7->setToolTip(tr("顺序播放"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
    }
}
void Dialog::PlaybackModel_slot(QMediaPlaylist::PlaybackMode model)
{

    if(model==QMediaPlaylist::Loop)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/player-icons_32px_1137007_easyicon.net.png"));
        ui->pushButton_7->setToolTip(tr("顺序播放"));
    }
    else if(model==QMediaPlaylist::Random)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/player-icons_32px_1137005_easyicon.net.png"));
        ui->pushButton_7->setToolTip(tr("随机播放"));
    }
    else if(model==QMediaPlaylist::CurrentItemInLoop)
    {
        ui->pushButton_7->setIcon(QIcon(":/image/image/player-icons_32px_1137006_easyicon.net.png"));
        ui->pushButton_7->setToolTip(tr("单曲循环"));
        playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    }
}
