#ifndef FLASH_PROGRAMM_H
#define FLASH_PROGRAMM_H

#include "mainwindow.h"
#include <QByteArray>
#include <QMessageBox>
#include <QFile>

class Flash_Programm : QObject
{
    Q_OBJECT
public:    
    Flash_Programm();
    void Start_Flash_Programming(void);
    void Flash_Programming(QByteArray *data_array);
    void Stop_Flash_Programming(void);
private slots:

private:


    QByteArray Tx_Buff;
    QByteArray Rx_Buff;
    int ArrayPos;

};

#endif // FLASH_PROGRAMM_H
