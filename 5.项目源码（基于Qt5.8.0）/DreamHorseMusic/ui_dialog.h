/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSlider *horizontalSlider;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(525, 141);
        Dialog->setMinimumSize(QSize(525, 141));
        Dialog->setMaximumSize(QSize(525, 141));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/ios8_Music_32px_1173465_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setStyleSheet(QLatin1String("/*QDialog#Dialog\n"
"{\n"
"\n"
"    border:1px solid #5F5F5F;\n"
"	\n"
"	border-radius:0px;\n"
"}*/"));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 80, 48, 48));
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"	background-image: url(:/image/image/control_rewind_48px_1116022_easyicon.net.png);\n"
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
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 80, 48, 48));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
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
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 80, 48, 48));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"	background-image: url(:/image/image/control_fastforward_48px_1116016_easyicon.net.png);\n"
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
        horizontalSlider = new QSlider(Dialog);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 60, 505, 22));
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
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 351, 21));
        label->setStyleSheet(QLatin1String("font: 75 11pt \"Comic Sans MS\";\n"
"color: rgb(112, 112, 112);"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 40, 101, 20));
        label_2->setStyleSheet(QLatin1String("font: 75 italic 9pt \"Comic Sans MS\";\n"
"color: rgb(112, 112, 112);"));
        pushButton_4 = new QPushButton(Dialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(488, 5, 32, 32));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	background-image: url(:/image/image/\345\217\211\345\217\267.png);\n"
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
        pushButton_5 = new QPushButton(Dialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(448, 5, 32, 32));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	background-image: url(:/image/image/\346\234\200\345\260\217\345\214\226 (1).png);\n"
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
        pushButton_7 = new QPushButton(Dialog);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 90, 32, 32));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
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
        pushButton_8 = new QPushButton(Dialog);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(480, 90, 32, 32));
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
""));
        pushButton_6 = new QPushButton(Dialog);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(5, 5, 48, 48));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"	background-image: url(:/image/image/ios8_Music_48px_1173465_easyicon.net.png);\n"
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

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\346\210\221\347\232\204\351\237\263\344\271\220", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
