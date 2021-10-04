#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringList>
#include <QString>
#include <QByteArray>
#include <QTimer>
#include <QList>
#include <QFileDialog>
#include <QTime>
#include "flash_programm.h"
#include "flash_read.h"
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QSerialPort Port;

private slots:

    void on_COM_Connect_clicked();

    void on_Programm_clicked();

    void on_UpdateCOM_clicked();

    void on_ComPortList_currentIndexChanged(const QString &arg1);

    void ReceiveData(void);

    void on_Erase_clicked();

    void on_OpenFile_clicked();

    void on_ClearLogs_clicked();


    void on_Read_clicked();

    void on_Save_clicked();

private:
    Ui::MainWindow *ui;
    QTimer TimerUpdateCOM;
   // QSerialPort Port;
    QSerialPortInfo PortInfo;
    QList<QSerialPortInfo> PortList;
    QStringList PortNames;
    bool COM_connect;
    bool IsFileOpen;


    QStringList TableHeaders;

    QByteArray Data_buffer;

    void Load_Table(void);
};
#endif // MAINWINDOW_H
