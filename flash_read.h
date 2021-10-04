#ifndef FLASH_READ_H
#define FLASH_READ_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QByteArray>
#include <QTableWidgetItem>

class Flash_Read : public QObject
{
    Q_OBJECT

public:
    Flash_Read();
    void Start_Flash_Read(void);
    void Flash_Reading(void);
    void Flash_Parsing(QByteArray *input,QByteArray *data_array);
    void Stop_Flash_Read(void);
signals:

private:
    QByteArray Rx_Buff;
    QByteArray Tx_Buff;
    int ArrayPos;
};

#endif // FLASH_READ_H
