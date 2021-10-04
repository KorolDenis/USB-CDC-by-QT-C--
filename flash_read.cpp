#include "flash_read.h"

#define START_FLASH_READ      5
#define FLASH_READ            6
#define STOP_FLASH_READ       7

Flash_Read::Flash_Read()
{

}

void Flash_Read::Start_Flash_Read(void)
{
    ArrayPos=0;
    Tx_Buff.clear();
    Tx_Buff[0]=START_FLASH_READ;
    MainWindow::Port.write(Tx_Buff.data(),1);
}
void Flash_Read::Flash_Reading(void) // запрашиваем новые данные прошивки
{
    char* data;
    Tx_Buff.clear();
    Tx_Buff[0]=FLASH_READ;
    data=Tx_Buff.data();
    MainWindow::Port.write(data,1);
}
void Flash_Read::Flash_Parsing(QByteArray *input,QByteArray *data_array)
{
    // parsing stop
    int End_Parsing;
    QByteArray check_word(4,0xFF);
    if(input->contains(check_word)) End_Parsing=input->indexOf(check_word);
    else End_Parsing=60;

    for(int i=0;i<End_Parsing;i++)
        data_array->insert(ArrayPos+i,input->at(i+1));
    ArrayPos+=60;
    Flash_Reading(); // прочитали и новый пакет запрашиваем.
}
void Flash_Read::Stop_Flash_Read(void)
{

}
