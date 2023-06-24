/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *toogleRadio;
    QRadioButton *setRadio;
    QRadioButton *resetRadio;
    QPushButton *confirmButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *serialComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *baudComboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *sizeComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *parityComboBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *openButton;
    QPushButton *closeButton;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *sttButton;
    QPushButton *velButton;
    QVBoxLayout *verticalLayout_3;
    QPushButton *movButton;
    QPushButton *posButton;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QLCDNumber *lcdNumber;
    QLabel *label_6;
    QPushButton *btn_clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(730, 550);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(730, 550));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(290, 50, 271, 431));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(280, 30, 281, 461));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(600, 370, 131, 111));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../tai_lieu/logo/Logo BK.png")));
        label_2->setScaledContents(true);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(600, 40, 111, 171));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 91, 101));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        toogleRadio = new QRadioButton(layoutWidget);
        toogleRadio->setObjectName(QString::fromUtf8("toogleRadio"));

        verticalLayout_4->addWidget(toogleRadio);

        setRadio = new QRadioButton(layoutWidget);
        setRadio->setObjectName(QString::fromUtf8("setRadio"));

        verticalLayout_4->addWidget(setRadio);

        resetRadio = new QRadioButton(layoutWidget);
        resetRadio->setObjectName(QString::fromUtf8("resetRadio"));
        resetRadio->setChecked(true);

        verticalLayout_4->addWidget(resetRadio);

        confirmButton = new QPushButton(groupBox_3);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(10, 140, 91, 24));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 30, 251, 471));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(verticalLayoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 231, 200));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        serialComboBox = new QComboBox(layoutWidget1);
        serialComboBox->setObjectName(QString::fromUtf8("serialComboBox"));

        horizontalLayout_2->addWidget(serialComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        baudComboBox = new QComboBox(layoutWidget1);
        baudComboBox->setObjectName(QString::fromUtf8("baudComboBox"));

        horizontalLayout_3->addWidget(baudComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        sizeComboBox = new QComboBox(layoutWidget1);
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));

        horizontalLayout_4->addWidget(sizeComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        parityComboBox = new QComboBox(layoutWidget1);
        parityComboBox->setObjectName(QString::fromUtf8("parityComboBox"));

        horizontalLayout_5->addWidget(parityComboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        layoutWidget2 = new QWidget(groupBox_4);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 220, 201, 61));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        openButton = new QPushButton(layoutWidget2);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        horizontalLayout_6->addWidget(openButton);

        closeButton = new QPushButton(layoutWidget2);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_6->addWidget(closeButton);

        layoutWidget3 = new QWidget(groupBox_4);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 290, 231, 67));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sttButton = new QPushButton(layoutWidget3);
        sttButton->setObjectName(QString::fromUtf8("sttButton"));

        verticalLayout_2->addWidget(sttButton);

        velButton = new QPushButton(layoutWidget3);
        velButton->setObjectName(QString::fromUtf8("velButton"));

        verticalLayout_2->addWidget(velButton);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        movButton = new QPushButton(layoutWidget3);
        movButton->setObjectName(QString::fromUtf8("movButton"));

        verticalLayout_3->addWidget(movButton);

        posButton = new QPushButton(layoutWidget3);
        posButton->setObjectName(QString::fromUtf8("posButton"));

        verticalLayout_3->addWidget(posButton);


        horizontalLayout->addLayout(verticalLayout_3);

        groupBox_2 = new QGroupBox(groupBox_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 360, 211, 101));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 191, 31));
        sendButton = new QPushButton(groupBox_2);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(50, 60, 101, 31));

        verticalLayout_5->addWidget(groupBox_4);

        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(590, 300, 121, 81));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lcdNumber->setFont(font);
        lcdNumber->setAutoFillBackground(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(630, 270, 55, 16));
        QFont font1;
        font1.setPointSize(10);
        label_6->setFont(font1);
        label_6->setAutoFillBackground(true);
        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(570, 450, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        groupBox->raise();
        textBrowser->raise();
        label_2->raise();
        groupBox_3->raise();
        verticalLayoutWidget->raise();
        lcdNumber->raise();
        label_6->raise();
        btn_clear->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 730, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Recieved Data", nullptr));
        label_2->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "PC13 Mode", nullptr));
        toogleRadio->setText(QApplication::translate("MainWindow", "Toogle", nullptr));
        setRadio->setText(QApplication::translate("MainWindow", "SET", nullptr));
        resetRadio->setText(QApplication::translate("MainWindow", "RESET", nullptr));
        confirmButton->setText(QApplication::translate("MainWindow", "Confirm", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Serial Port", nullptr));
        label->setText(QApplication::translate("MainWindow", "COM", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "BaudRate", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Data Size", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Parity", nullptr));
        openButton->setText(QApplication::translate("MainWindow", "Open", nullptr));
        closeButton->setText(QApplication::translate("MainWindow", "Close", nullptr));
        sttButton->setText(QApplication::translate("MainWindow", "STATUS", nullptr));
        velButton->setText(QApplication::translate("MainWindow", "VELOCITY", nullptr));
        movButton->setText(QApplication::translate("MainWindow", "MOVEL", nullptr));
        posButton->setText(QApplication::translate("MainWindow", "POSITION", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Send Data", nullptr));
        sendButton->setText(QApplication::translate("MainWindow", "Send", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "  ADC", nullptr));
        btn_clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
