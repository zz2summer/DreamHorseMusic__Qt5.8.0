#ifndef WIDGET_H
#define WIDGET_H

#include<QWidget>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QPixmap>
#include<QPalette>
#include<QStandardItemModel>
#include<QStandardItem>
#include<QAction>
#include<QMouseEvent>
#include<QList>
#include<QPaintEvent>
#include<QSqlTableModel>
#include"dialog.h"
class QMediaPlayer;
class QMediaPlaylist;
class QMenu;
class QAction;
class QSqlTableModel;
class Dialog;
class Form;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    void updateInfo();
    void updatePosition(qint64 position);
    void updateDuration(qint64 duration);
    void updatalistwidget_3(int value);
    void updatalistwidget_2(int value);
    void updatalistwidget(int value);
    void changeVolume(int values);
    void pushbuttonstyle();
    void pushbuttonstyle_2();
    void pushbuttonstyle_3();
    void pushbuttonstyle_4();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    ~Widget();
private slots:
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_9_clicked();

    void on_listWidget_3_doubleClicked(const QModelIndex &index);
    void on_listWidget_2_doubleClicked(const QModelIndex &index);
    void on_listWidget_doubleClicked(const QModelIndex &index);
    void on_listWidget_4_doubleClicked(const QModelIndex &index);

    void action1_slot();
    void action2_slot();
    void action3_slot();
    void action5_1_slot();
    void action5_2_slot();
    void action5_3_slot();
    void action6_slot();
    void action7_slot();
    void action8_slot();
    void ClearALL_1_slot();
    void ClearALL_2_slot();
    void ClearALL_3_slot();
    void ClearALL_4_slot();
    void action9_slot();
    void action10_slot();
    void action11_slot();
    void action12_1_slot();
    void action12_2_slot();
    void action12_3_slot();
    void Action1_slot();
    void Action2_slot();
    void Action3_slot();
    void Action4_slot();
    void Action5_slot();


    void Action1_2_slot();
    void Action2_2_slot();
    void Action3_2_slot();
    void Action4_2_slot();

    void Action1_3_slot();
    void Action2_3_slot();
    void Action3_3_slot();

    void Action_slot();
    void Action_1_slot();
    void Action_2_slot();
    void Action_3_slot();
    void Action_4_slot();

    void detila_slot();
    void on_pushButton_7_clicked();
    void contextMenuEvent(QContextMenuEvent *event);
    void on_pushButton_17_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_8_clicked();
    void on_listWidget_3_customContextMenuRequested(const QPoint &pos);
    void on_listWidget_2_customContextMenuRequested(const QPoint &pos);
    void on_listWidget_customContextMenuRequested(const QPoint &pos);
    void music_stateChang(QMediaPlayer::State state);
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_18_clicked();

    void on_listWidget_4_customContextMenuRequested(const QPoint &pos);
    void Next_slot();
    void Pre_slot();
    void nextlist_slot();
    void prelist_slot();
    void addV_slot();
    void subV_slot();
    void Locale_slot();
    void change_slot();
    void love_slot();
    void Data_slot(int row,int position,QMediaPlaylist *list,QMediaPlayer::State state,QMediaPlaylist::PlaybackMode model);
    void on_lineEdit_returnPressed();
    void PlaylistModel_slot(QMediaPlaylist::PlaybackMode model);
private:
    void CreateSortCut();

    Ui::Widget *ui;
    QMediaPlayer *music=NULL;

    QMediaPlaylist *playlist=NULL;
    QMediaPlaylist *playlist_2=NULL;
    QMediaPlaylist *playlist_3=NULL;


    QPixmap pix;
    QPalette pal;
    int count2=0;

    QAction *action1;
    QAction *action2;
    QAction *action3;

    QAction *action4_1;
    QAction *action4_2;
    QAction *action5_1;
    QAction *action5_2;
    QAction *action5_3;
    QAction *action6;
    QAction *action7;
    QAction *action8;
    QAction *ClearALL;
    QAction *ClearALL_1;
    QAction *ClearALL_2;
    QAction *ClearALL_3;
    QAction *ClearALL_4;

    QAction *action9;
    QAction *action10;
    QAction *action11;
    QAction *action12;
    QAction *action12_1;
    QAction *action12_2;
    QAction *action12_3;
    QAction *action13;
    QAction *detila;
    QMenu *menu;
    QPoint offset;
    double transparency;

    QSqlTableModel *model;
    QSqlTableModel *model_2;
    QSqlTableModel *model_3;

    QList<int> load;

    Dialog *Music=NULL;

};

#endif // WIDGET_H
