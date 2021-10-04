#include "flash_programm.h"
#include "mainwindow.h"

// Команды
#define START_FLASH_PROGRAMM  1
#define FLASH_PROGRAMM        2
#define STOP_FLASH_PROGRAMM   3
#define ERASE_FLASH           4

//QFile file;
//int FilePosition=0; // может и не понадобится?

Flash_Programm::Flash_Programm()
{
  //connect(&MainWindow::Port,SIGNAL(readyRead()),this,SLOT(Get_Confirm())); // отслеживаем ответ по COM
    ArrayPos=0;
    Tx_Buff.resize(64);
}

void Flash_Programm::Start_Flash_Programming()
{
    Tx_Buff.clear();
    //ArrayPos=0;
    Tx_Buff[0]=START_FLASH_PROGRAMM;
    MainWindow::Port.write(Tx_Buff.data(),1);
}

void Flash_Programm::Flash_Programming(QByteArray *data_array) // записать 25 слов
{

    Tx_Buff.clear();
    Tx_Buff.resize(64);
    Tx_Buff.fill(0xFF,64);
    Tx_Buff[0]=2;
    if(ArrayPos>=data_array->size()) // если закончился массив данных
    {
        Stop_Flash_Programming();
        return;
    }
    if((data_array->size()-ArrayPos)<60) // если уже меньше 15 слов у нас осталось
    {
       for(int i=0;i<(data_array->size()-ArrayPos);i++)
            Tx_Buff[i+1]=data_array->at(ArrayPos+i);

        ArrayPos=data_array->size();
    }
    else // а иначе переписываем 15 слов
    {
     for(int i=0;i<60;i++)
     {
       Tx_Buff[i+1]=data_array->at(ArrayPos+i);
     // ArrayPos+=15;
     }
     ArrayPos+=60;
    }

    MainWindow::Port.write(Tx_Buff.data(),64);
    //return FilePosition;
}

void Flash_Programm::Stop_Flash_Programming(void)
{
   ArrayPos=0;
   Tx_Buff.clear();
   Tx_Buff[0]=STOP_FLASH_PROGRAMM;
   MainWindow::Port.write(Tx_Buff.data(),1);
}


