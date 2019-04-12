#include "widget.h"
#include <QApplication>
#include"connection.h"
#include<QTime>
int main(int argc, char *argv[])
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QApplication a(argc, argv);
    if(!CreatConnection())
    {
        return 1;
    }
    Widget w;
    w.setWindowIcon(QIcon(":/image/image/ios8_Music_48px_1173465_easyicon.net.png"));
    w.setWindowTitle(QObject::tr("梦马音乐"));

    w.setWindowFlags(Qt::FramelessWindowHint);

    w.show();
    return a.exec();
}

