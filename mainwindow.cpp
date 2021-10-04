#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "flash_programm.h"
#include "flash_read.h"


QSerialPort MainWindow::Port;
//Ui::MainWindow MainWindow::*ui;
Flash_Programm Flash;
Flash_Read Flash_r;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //TimerUpdateCOM.start(1000); // каждую секунду проверять порты

    ui->setupUi(this);
    IsFileOpen=false;
    COM_connect=false;

    connect(&Port,SIGNAL(readyRead()),this,SLOT(ReceiveData()));
    //connect(&TimerUpdateCOM,SIGNAL(timeout()),this,SLOT(UpdateCOM()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_COM_Connect_clicked()
{
    //Port.setPortName(ui->ComPortList->currentText());
    QString Message;

    if(Port.open(QIODevice::ReadWrite))
    {
        ui->COM_Connect->setText("Отключить");
        COM_connect=true;
        Message.append(QTime::currentTime().toString());
        Message.append(" : Устройство подключено.");
        ui->Logs->append(Message);
    }
    else
    {
        COM_connect=false;
        Port.close();
        ui->COM_Connect->setText("Подключить");
        Message.append(QTime::currentTime().toString());
        Message.append(" : Устройство отключено.");
        ui->Logs->append(Message);
    }
}


void MainWindow::on_Programm_clicked()
{
  if(COM_connect)
  {
  QString Message;
  if(IsFileOpen)
  {
      Flash.Start_Flash_Programming();
      Message.append(QTime::currentTime().toString());
      Message.append(" : Загрузка прошивки...");
      ui->Logs->append(Message);
  }
  else
  {
      Message.append(QTime::currentTime().toString());
      Message.append(" : Не открыт файл прошивки!");
      ui->Logs->append(Message);
  }
  }

}


void MainWindow::on_UpdateCOM_clicked()
{
    int temp_size;
    QString Message;
    Message.append(QTime::currentTime().toString());
    Message.append(" : Обновление COM портов...");
    ui->Logs->append(Message);
    PortList=PortInfo.availablePorts(); // взяли список всех доступных портов
    temp_size=PortList.size();
    PortNames.clear();
    for(int i=0;i<temp_size;i++) PortNames<<PortList.value(i).portName(); // записали все названия портов из списка доступных

    if(temp_size!=0)
    {
        ui->ComPortList->clear();
        ui->ComPortList->addItems(PortNames);
        Message.clear();
        Message.append(QTime::currentTime().toString());
        Message.append(" : Список СОМ портов обновлен.");
        ui->Logs->append(Message);
    }
    else
    {
        PortNames<<"Пусто";
        ui->ComPortList->clear();
        ui->ComPortList->addItems(PortNames);
        Message.clear();
        Message.append(QTime::currentTime().toString());
        Message.append(" : СОМ порты не обнаружены.");
        ui->Logs->append(Message);
    }
}


void MainWindow::on_ComPortList_currentIndexChanged(const QString &arg1)
{
    Port.setPortName(arg1);
}

void MainWindow::ReceiveData(void)
{
    QByteArray input_packet;
    input_packet.resize(64);
    QString Message;
    input_packet=Port.readAll();
    if(input_packet.at(0)==1) Flash.Flash_Programming(&Data_buffer); // если готов к прошивке, начинаем шить
    if(input_packet.at(0)==2) Flash.Flash_Programming(&Data_buffer); // шьем
    if(input_packet.at(0)==3) // сообщил о завершении прошивки
    {

        Message.append(QTime::currentTime().toString());
        Message.append(" : Прошивка загружена!");
        ui->Logs->append(Message);
    }
    if(input_packet.at(0)==4)
    {
        Message.append(QTime::currentTime().toString());
        Message.append(" : Прошивка удалена!");
        ui->Logs->append(Message);
    }
    if(input_packet.at(0)==5)
    {
        Data_buffer.clear(); // перед записью в буфер чистим его
        Flash_r.Flash_Reading();
    }
    if(input_packet.at(0)==6) Flash_r.Flash_Parsing(&input_packet,&Data_buffer); // пришел ответ от МК, парсим пакет
    if(input_packet.at(0)==7) // пришел ответ о том что конец чтения
    {
        Message.append(QTime::currentTime().toString());
        Message.append(" : Прошивка считана!");
        ui->Logs->append(Message);
        Load_Table();
    }
}

void MainWindow::on_Erase_clicked()
{
    if(COM_connect)
    {
    QString Message;
    Message.append(QTime::currentTime().toString());
    Message.append(" : Удаление прошивки...");
    ui->Logs->append(Message);
    char* data;
    QByteArray Tx_Buff;
    Tx_Buff.clear();
    Tx_Buff[0]=4;
    data=Tx_Buff.data();
    MainWindow::Port.write(data,1);
    }
}


void MainWindow::on_OpenFile_clicked()
{
    int FileSize;
    QString Message;
    QString Opened_File;

    Opened_File.clear();
    Opened_File=QFileDialog::getOpenFileName(this,"Открыть файл");
    if(!(Opened_File.isEmpty())) // если есть название файла
    {
    QFile file_table(Opened_File);
    IsFileOpen=true;

    if(file_table.open(QIODevice::ReadOnly))
    {
        FileSize=file_table.size();
        Data_buffer.resize(FileSize);
        if(file_table.read(Data_buffer.data(),FileSize)==FileSize)
        {
            Message.append(QTime::currentTime().toString());
            Message.append(" : Открыт файл: ");
            Message.append(Opened_File);
            ui->Logs->append(Message);
            Message.clear();

            Message.append(QTime::currentTime().toString());
            Message.append(QString(" : Размер файла %1 байт").arg(FileSize));
            ui->Logs->append(Message);
        }
    }
    file_table.close();
    Load_Table();
    }

}


void MainWindow::on_ClearLogs_clicked()
{
    ui->Logs->clear();
}

void MainWindow::Load_Table(void)
{
    QTableWidgetItem *TI;

    union
    {
        unsigned int word;
        char byte[4];
    }Convert;
    QStringList headers;

    ui->tableWidget->setRowCount(Data_buffer.size()/16+1);
    for(int i=0;i<Data_buffer.size();i+=16) // генерируем все заголовки для строк
        headers.append(QString("0x").append(QString("%1").arg(i,8,16,QLatin1Char('0')).toUpper()));
    ui->tableWidget->setVerticalHeaderLabels(headers);

    for(int j=0;j<(Data_buffer.size()/16);j++)
    {
     for(int i=0;i<4;i++)
     {
      Convert.byte[0]=Data_buffer.at((j*16)+(i*4)+0);
      Convert.byte[1]=Data_buffer.at((j*16)+(i*4)+1);
      Convert.byte[2]=Data_buffer.at((j*16)+(i*4)+2);
      Convert.byte[3]=Data_buffer.at((j*16)+(i*4)+3);
      TI= new QTableWidgetItem(QString("%1").arg(Convert.word,8,16,QLatin1Char('0')).toUpper());
      ui->tableWidget->setItem(j,i,TI);
     }
    }
    if((Data_buffer.size()%16)!=0) // если есть остаток то и его грузим
    {
        for(int i=0;i<((Data_buffer.size()%16)/4);i++)
        {
         Convert.byte[0]=Data_buffer.at((Data_buffer.size()/16*16)+(i*4)+0);
         Convert.byte[1]=Data_buffer.at((Data_buffer.size()/16*16)+(i*4)+1);
         Convert.byte[2]=Data_buffer.at((Data_buffer.size()/16*16)+(i*4)+2);
         Convert.byte[3]=Data_buffer.at((Data_buffer.size()/16*16)+(i*4)+3);
         TI= new QTableWidgetItem(QString("%1").arg(Convert.word,8,16,QLatin1Char('0')).toUpper());
         ui->tableWidget->setItem(Data_buffer.size()/16,i,TI);
        }
    }

}

void MainWindow::on_Read_clicked()
{
    if(COM_connect)
    {
    Flash_r.Start_Flash_Read();
    QString Message;
    Message.append(QTime::currentTime().toString());
    Message.append(" : Чтение прошивки из Flash-памяти...");
    ui->Logs->append(Message);
    }
}

void MainWindow::on_Save_clicked()
{
    QString Message;
    QString Saved_File;

    Saved_File.clear();
    Saved_File=QFileDialog::getSaveFileName(this,"Cохранить файл", "*.bin");
    if(!(Saved_File.isEmpty()))
    {
     Message.append(QTime::currentTime().toString());
     Message.append(" : Сохранение файла: ");
     Message.append(Saved_File);
     ui->Logs->append(Message);

     QFile File(Saved_File);
     File.open(QIODevice::WriteOnly);
     File.write(Data_buffer.data(),Data_buffer.size()-1);
     File.close();
    }
}

