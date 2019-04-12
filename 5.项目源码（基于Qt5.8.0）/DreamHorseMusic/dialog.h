#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QPoint>
#include<QMouseEvent>
#include<QPixmap>
#include<QPalette>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QAction>
#include<QAction>
#include"widget.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
void mousePressEvent(QMouseEvent *event);
void mouseMoveEvent(QMouseEvent *event);
void mouseReleaseEvent(QMouseEvent *event);
void mouseDoubleClickEvent(QMouseEvent *event);
void contextMenuEvent(QContextMenuEvent *event);
void setPlaylist(QMediaPlaylist *list,int row,int position,int volume,QMediaPlayer::State state,QMediaPlaylist::PlaybackMode playmodel,int i);
void updateText();
void updatePosition(qint64 position);
void updateDuration(qint64 duration);
void stateChange(QMediaPlayer::State state);
void PlaybackModel_slot(QMediaPlaylist::PlaybackMode model);
signals:
void Data(int row,int position,QMediaPlaylist *list,QMediaPlayer::State state,QMediaPlaylist::PlaybackMode model);
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();
    void play_slot();
    void next_slot();
    void pre_slot();
    void action1_slot();
    void action2_slot();
    void action3_slot();
    void action4_slot();

    void quit_slot();
    void on_pushButton_7_clicked();

private:
    Ui::Dialog *ui;
    QPoint offset;
    QPixmap pix;
    QPalette pal;

    QAction *play;
    QAction *next;
    QAction *pre;

    QAction *action;
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;

    QAction *quit;

    QMenu *menu;
    QMediaPlayer *music;
    QMediaPlaylist *playlist;
    double TouMin;
    int count=0;
};

#endif // DIALOG_H
