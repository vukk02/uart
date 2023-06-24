#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_sttButton_clicked();
    void on_movButton_clicked();
    void on_velButton_clicked();
    void on_posButton_clicked();
    void on_openButton_clicked();
    void on_sendButton_clicked();
    void serialport_read();
    void dataProcessing();
    void on_confirmButton_clicked();

    void on_closeButton_clicked();

    void on_btn_clear_clicked();

private:
    void updateSerialPort();
    QSerialPort *mSerial;
    QList <QSerialPortInfo> mSerialPorts;
    QTimer *mSerialScanTimer;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
