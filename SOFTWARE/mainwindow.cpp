#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QScrollBar>
#include <QIODevice>
#include <QThread>

    uint8_t index = 0;
    //QString str;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Serial");

    mSerial = new QSerialPort(this);
    updateSerialPort();

    ui->baudComboBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudComboBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudComboBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudComboBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);

    ui->sizeComboBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->sizeComboBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->sizeComboBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->sizeComboBox->addItem(QStringLiteral("8"), QSerialPort::Data8);



    QStringList parity = {"none"};
    ui -> parityComboBox -> addItems(parity);


    mSerialScanTimer = new QTimer(this);
    mSerialScanTimer->setInterval(5000);
    mSerialScanTimer->start();

    ui-> sttButton -> setEnabled(false);
    ui-> velButton -> setEnabled(false);
    ui-> posButton -> setEnabled(false);
    ui-> movButton -> setEnabled(false);


    connect(mSerialScanTimer, &QTimer::timeout, this, &MainWindow::updateSerialPort);
    connect(ui->lineEdit, &QLineEdit::returnPressed,this, &MainWindow::on_sendButton_clicked);
    connect(mSerial, &QSerialPort::readyRead, this, &MainWindow::serialport_read);


}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_sttButton_clicked()
{
        QByteArray str("02 47 53 54 54 00 00 01 00 00 00 00 00 00 00 00 16 03");
        QByteArray t = str.replace(" ", "");

        QString str1 = ui -> lineEdit->text();
        QByteArray str2 = str1.toUtf8().toHex();

        if (str2.size() < 16) {
            QByteArray filler(16 - str2.size(), '0');
                str2.append(filler);
        }

        t.replace(16, 16, str2);

        QByteArray bytes = QByteArray::fromHex(t);
        mSerial->write(bytes);
}


void MainWindow::on_movButton_clicked()
{
        QByteArray str("02 4D 4F 56 4C 00 00 01 00 00 00 00 00 00 00 00 16 03");
            QByteArray t = str.replace(" ", "");

            QString str1 = ui -> lineEdit->text();
            QByteArray str2 = str1.toUtf8().toHex();

            if (str2.size() < 16) {
                QByteArray filler(16 - str2.size(), '0');
                    str2.append(filler);
            }           

            t.replace(16, 16, str2);

            QByteArray bytes = QByteArray::fromHex(t);
            mSerial->write(bytes);
}


void MainWindow::on_velButton_clicked()
{
        QByteArray str("02 47 56 45 4C 00 00 01 00 00 00 00 00 00 00 00 16 03");
        QByteArray t = str.replace(" ", "");

        QString str1 = ui -> lineEdit->text();
        QByteArray str2 = str1.toUtf8().toHex();

        if (str2.size() < 16) {
            QByteArray filler(16 - str2.size(), '0');
                str2.append(filler);
        }

        t.replace(16, 16, str2);

        QByteArray bytes = QByteArray::fromHex(t);
        mSerial->write(bytes);
}


void MainWindow::on_posButton_clicked()
{
        QByteArray str("02 47 50 4F 53 00 00 01 00 00 00 00 00 00 00 00 16 03");
        QByteArray t = str.replace(" ", "");

        QString str1 = ui -> lineEdit->text();
        QByteArray str2 = str1.toUtf8().toHex();

        if (str2.size() < 16) {
            QByteArray filler(16 - str2.size(), '0');
                str2.append(filler);
        }

        t.replace(16, 16, str2);

        QByteArray bytes = QByteArray::fromHex(t);
        mSerial->write(bytes);
}



void MainWindow::updateSerialPort()
{
    mSerialPorts = QSerialPortInfo::availablePorts();
    ui->serialComboBox->clear();
    for(const QSerialPortInfo &port: mSerialPorts)
    {
        ui -> serialComboBox -> addItem(port.portName(),  port.systemLocation());
    }

}

void MainWindow::on_openButton_clicked()
{
    ui->openButton->setEnabled(false);
    QString serialLoc  =  ui->serialComboBox->currentData().toString();

    mSerial->setPortName(serialLoc);
    mSerial->setBaudRate(static_cast<QSerialPort::BaudRate>(ui->baudComboBox->itemData(ui->baudComboBox->currentIndex()).toInt()));
    mSerial->setDataBits(static_cast<QSerialPort::DataBits>(ui->sizeComboBox->itemData(ui->sizeComboBox->currentIndex()).toInt()));

    mSerial->setParity(QSerialPort::NoParity);
    mSerial->setStopBits(QSerialPort::OneStop);
    mSerial->setFlowControl(QSerialPort::NoFlowControl);

    if(mSerial->open(QIODevice::ReadWrite)) {

        QString text = "SERIAL: OK!\n";
        ui->textBrowser->insertPlainText(text);
    } else {
        QString text = "SERIAL: ERROR!\n";
        ui->textBrowser->insertPlainText(text);
    }
    ui-> sttButton -> setEnabled(true);
    ui-> velButton -> setEnabled(true);
    ui-> posButton -> setEnabled(true);
    ui-> movButton -> setEnabled(true);
    ui-> openButton ->setEnabled(true);
}


void MainWindow::on_sendButton_clicked()
{
    if(mSerial-> isOpen())
    {
        QString str = ui -> lineEdit->text();
        //ui->lineEdit->clear();
        //str.append("\r\n");
        if (str.size() < 18) {
            QString filler(18 - str.size(), 0);
                str.append(filler);
        }
        mSerial -> write(str.toLocal8Bit());
    }
    else
    {
        QString text = "Transmit mission failed!\n";
        ui->textBrowser->insertPlainText(text);
    }
}

void MainWindow::serialport_read()
{
    QString cmd = "Command recieved: ";
    QString data = "Data recieved: ";
    QThread::msleep(30);
    QByteArray data_rev = mSerial -> readAll();
    if(data_rev.size() < 17)
    {
        QString adc = QString::fromUtf8(data_rev);

        ui->lcdNumber->display(adc);
        data_rev.clear();
    }
    else
    {   QByteArray a = data_rev.mid(0, 4);
        QByteArray b = data_rev.mid(7, 8);

            QString temp = QString::fromUtf8(a);
            ui -> textBrowser -> insertPlainText(cmd);
            temp.append("\n");
            ui -> textBrowser -> insertPlainText(temp);

            QString temp2 = QString::fromUtf8(b);
            ui -> textBrowser -> insertPlainText(data);
            temp2.append("\n");
            ui -> textBrowser -> insertPlainText(temp2);

            a.clear();
            b.clear();
            temp.clear();
            temp2.clear();
            data_rev.clear();
    }
    QScrollBar *sb = ui->textBrowser->verticalScrollBar();
    sb->setValue(sb->maximum());
}

void MainWindow::dataProcessing()
{
    //QTimer::singleShot(100,this,[=]{serialport_read();});
}

void MainWindow::on_confirmButton_clicked()
{
    if(ui -> resetRadio -> isChecked())
    {
        QByteArray str("02 52 45 53 53 00 00 01 00 00 00 00 00 00 00 00 16 03");
        QByteArray t = str.replace(" ", "");
        QByteArray bytes = QByteArray::fromHex(t);
        mSerial->write(bytes);
        if(mSerial -> isWritable())
        {
            QString text = "Command sent: Reset PC13\r\n";
            ui -> textBrowser -> insertPlainText(text);
        }
    }
    else if(ui -> setRadio -> isChecked())
    {
        QByteArray str("02 53 45 54 54 00 00 01 00 00 00 00 00 00 00 00 16 03");
        QByteArray t = str.replace(" ", "");
        QByteArray bytes = QByteArray::fromHex(t);
        mSerial->write(bytes);
        if(mSerial -> isWritable())
        {
            QString text = "Command sent: Set PC13\r\n";
            ui -> textBrowser -> insertPlainText(text);
        }
    }
    else if(ui -> toogleRadio -> isChecked())
    {
        QByteArray str("02 54 4F 47 47 00 00 00 00 00 00 00 00 01 00 01 16 03");
        QByteArray t = str.replace(" ", "");
        QByteArray bytes = QByteArray::fromHex(t);
        mSerial->write(bytes);
        if(mSerial -> isWritable())
        {
            QString text = "Command sent: Toogle PC13\r\n";
            ui -> textBrowser -> insertPlainText(text);
        }
    }
}


void MainWindow::on_closeButton_clicked()
{
    if (mSerial->isOpen())
    {
        mSerial->close();
        QString text = "Serial Port: Close\n";
        ui->textBrowser->insertPlainText(text);
        ui-> sttButton -> setEnabled(false);
        ui-> velButton -> setEnabled(false);
        ui-> posButton -> setEnabled(false);
        ui-> movButton -> setEnabled(false);
    }

}


void MainWindow::on_btn_clear_clicked()
{
    ui->textBrowser->clear();
}

