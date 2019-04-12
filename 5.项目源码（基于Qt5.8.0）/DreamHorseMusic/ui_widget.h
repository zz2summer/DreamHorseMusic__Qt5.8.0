/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QListWidget *listWidget_3;
    QWidget *page_3;
    QListWidget *listWidget_2;
    QWidget *page_2;
    QListWidget *listWidget;
    QWidget *page_4;
    QListWidget *listWidget_4;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QSlider *verticalSlider;
    QLineEdit *lineEdit;
    QPushButton *pushButton_18;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->setEnabled(true);
        Widget->resize(920, 615);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(920, 615));
        Widget->setMaximumSize(QSize(920, 615));
        Widget->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/ios8_Music_32px_1173465_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QLatin1String("QWidget#Widget\n"
"{\n"
"\n"
"    border:1px solid #5F5F5F;\n"
"	\n"
"	border-radius:0px;\n"
"}"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(780, 5, 32, 32));
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/add_32px_1163593_easyicon.net.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 560, 48, 48));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(190, 570, 491, 31));
        horizontalSlider->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalSlider->setStyleSheet(QString::fromUtf8("\n"
"    QSlider::add-page:Horizontal\n"
"     {     \n"
"background-color: rgba(255, 255, 255,100);\n"
"        height:4px;  \n"
"     } \n"
"     QSlider::sub-page:Horizontal   \n"
"    {  \n"
"background-color: rgb(255, 255, 255);\n"
"        height:4px;\n"
"     }\n"
"    QSlider::groove:Horizontal   \n"
"    { \n"
"        background:transparent; \n"
"        height:4px;\n"
"    }  \n"
"    QSlider::handle:Horizontal  \n"
"    { \n"
"        height:16px; \n"
"        width:16px; \n"
"	\n"
"	border-image: url(:/image/image/\345\234\206\345\275\242 (9).png);\n"
"  margin: -6 0px; \n"
"    }\n"
"      \n"
""));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(570, 549, 111, 21));
        label_2->setStyleSheet(QLatin1String("font: 75 italic 11pt \"Comic Sans MS\";\n"
"color: rgb(112, 112, 112);"));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 560, 48, 48));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"\n"
"	background-image: url(:/image/image/control_fastforward_48px_1116016_easyicon.net.png);\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 560, 48, 48));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"	background-image: url(:/image/image/control_rewind_48px_1116022_easyicon.net.png);\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(730, 5, 32, 32));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/setting_32px_1143813_easyicon.net.png);\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(680, 5, 32, 32));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/image/image/\347\232\256\350\202\244 (1).png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(820, 570, 32, 32));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	background-image: url(:/image/image/\345\256\232\344\275\215 (1).png);\n"
"\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(870, 570, 32, 32));
        pushButton_8->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(770, 570, 32, 32));
        pushButton_9->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_10 = new QPushButton(Widget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(10, 10, 32, 32));
        pushButton_10->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"\n"
"	background-image: url(:/image/image/music_32px_1125557_easyicon.net.png);\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_11 = new QPushButton(Widget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(100, 10, 32, 32));
        pushButton_11->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"\n"
"	\n"
"	background-image: url(:/image/image/like_outline_32px_1170275_easyicon.net.png);\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_12 = new QPushButton(Widget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(180, 10, 31, 31));
        pushButton_12->setStyleSheet(QLatin1String("\n"
"QPushButton\n"
"{\n"
"\n"
"	background-image: url(:/image/image/list_32px_1074296_easyicon.net.png);\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(1, 50, 300, 500));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        listWidget_3 = new QListWidget(page);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));
        listWidget_3->setGeometry(QRect(1, 0, 300, 500));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        listWidget_3->setFont(font);
        listWidget_3->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget_3->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Comic Sans MS\";\n"
"background-color:transparent;"));
        listWidget_3->setFrameShape(QFrame::NoFrame);
        listWidget_3->setFrameShadow(QFrame::Raised);
        listWidget_3->setLineWidth(1);
        listWidget_3->setMidLineWidth(1);
        listWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        listWidget_2 = new QListWidget(page_3);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(1, 0, 300, 500));
        listWidget_2->setFont(font);
        listWidget_2->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget_2->setStyleSheet(QLatin1String("font: 75 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"background-color:transparent;"));
        listWidget_2->setFrameShape(QFrame::NoFrame);
        listWidget_2->setFrameShadow(QFrame::Plain);
        listWidget_2->setLineWidth(0);
        listWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_2->setBatchSize(100);
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        listWidget = new QListWidget(page_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(1, 0, 300, 500));
        listWidget->setFont(font);
        listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"background-color:transparent;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Comic Sans MS\";\n"
"\n"
"\n"
"}"));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Plain);
        listWidget->setLineWidth(0);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSortingEnabled(false);
        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        listWidget_4 = new QListWidget(page_4);
        listWidget_4->setObjectName(QStringLiteral("listWidget_4"));
        listWidget_4->setGeometry(QRect(1, 0, 300, 500));
        listWidget_4->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget_4->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"background-color:transparent;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 11pt \"Comic Sans MS\";\n"
"\n"
"\n"
"}"));
        listWidget_4->setFrameShape(QFrame::NoFrame);
        listWidget_4->setLineWidth(0);
        listWidget_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stackedWidget->addWidget(page_4);
        pushButton_13 = new QPushButton(Widget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(630, 5, 32, 32));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/image/image/\351\200\200\345\207\272 (3).png);\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_14 = new QPushButton(Widget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(720, 570, 32, 32));
        pushButton_14->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 520, 521, 20));
        label->setStyleSheet(QLatin1String("font: 75 11pt \"Comic Sans MS\";\n"
"color: rgb(112, 112, 112);"));
        pushButton_15 = new QPushButton(Widget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(260, 10, 32, 32));
        pushButton_15->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_16 = new QPushButton(Widget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(830, 5, 32, 32));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/image/image/\346\234\200\345\260\217\345\214\226 (1).png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_17 = new QPushButton(Widget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(880, 5, 32, 32));
        pushButton_17->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"background-image: url(:/image/image/\345\217\211\345\217\267.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"background-color: rgba(255, 255, 255,100);\n"
"	;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        verticalSlider = new QSlider(Widget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(870, 400, 35, 161));
        verticalSlider->setCursor(QCursor(Qt::PointingHandCursor));
        verticalSlider->setStyleSheet(QString::fromUtf8(" QSlider \n"
"    {  \n"
"        background-color: rgba(20, 20, 20,200);\n"
"        min-width:5px; \n"
"        max-width:5px;\n"
"        border:15px solid rgba(25, 38, 58,100); \n"
"    }\n"
"     QSlider::add-page:vertical\n"
"     {      \n"
"       \n"
"	background-color: rgb(250, 250, 0);\n"
"        width:4px;\n"
"     }\n"
"     QSlider::sub-page:vertical  \n"
"    {\n"
"        background-color: rgb(87, 97, 106); \n"
"        width:4px;\n"
"     }\n"
"    QSlider::groove:vertical \n"
"    {\n"
"        background:transparent;\n"
"        width:6px;\n"
"    }\n"
"    QSlider::handle:vertical \n"
"    {\n"
"         height: 13px;\n"
"        width:13px;\n"
" \n"
" margin: -0 -4px; \n"
"	border-image: url(:/image/image/\345\234\206\345\275\242 (10).png);\n"
"     }"));
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setTickPosition(QSlider::NoTicks);
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(330, 10, 200, 32));
        lineEdit->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color: rgba(255, 255, 255,150);\n"
"border-style:outset;\n"
"\n"
"border-width:0px;\n"
"\n"
"border-radius:10px;\n"
"border-color: rgba(0,0,0,100);\n"
"font:bold 14px;\n"
"color:rgba(0,0,0,100);\n"
"padding:6px;\n"
"}"));
        pushButton_18 = new QPushButton(Widget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(540, 10, 32, 32));
        pushButton_18->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/ss.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"border-style:outset;\n"
"border-color:rgba(255,255,255,0);\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 390, 390, 32));
        label_3->setStyleSheet(QLatin1String("font: 75 italic 12pt \"Comic Sans MS\";\n"
"color: rgb(75, 75, 75);"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(540, 430, 330, 32));
        label_4->setStyleSheet(QLatin1String("font: 75 italic 12pt \"Comic Sans MS\";\n"
"color: rgb(75, 75, 75);"));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\346\210\221\347\232\204\351\237\263\344\271\220", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        label->setText(QString());
        pushButton_15->setText(QString());
        pushButton_16->setText(QString());
        pushButton_17->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("Widget", "\350\276\223\345\205\245\346\255\214\346\233\262\346\210\226\346\255\214\346\211\213", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QApplication::translate("Widget", "\350\276\223\345\205\245\346\255\214\346\233\262", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        pushButton_18->setToolTip(QApplication::translate("Widget", "\346\220\234\347\264\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_18->setText(QString());
        label_3->setText(QApplication::translate("Widget", "You may only be a person in this world,", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "but for someone,you're the world.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
