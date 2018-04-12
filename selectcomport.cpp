#include "selectcomport.h"
#include "ui_selectcomport.h"



#include <QSerialPortInfo>



SelectComPort::SelectComPort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectComPort)
{
    ui->setupUi(this);
    ui->label_2->setText("Disconnected");
}

SelectComPort::~SelectComPort()
{
    delete ui;
}

void SelectComPort::on_pushButton_2_clicked()
{
    ui->comboBox->clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comboBox->addItem(info.portName()+" : "+info.description());//+info.manufacturer());
    }
}


void SelectComPort::on_comboBox_currentIndexChanged(const QString &arg1)
{
    serial.close();
    ui->label_2->setText("Disconnected");
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (arg1==info.portName()+" : "+info.description()){
            serial.setPort(info);
            serial.setBaudRate(QSerialPort::Baud9600);
            if (serial.open(QIODevice::ReadWrite)){
                connect(&serial, SIGNAL(readyRead()),SLOT(handleSerialData()));
                ui->label_2->setText("Connected");
            }return;
        }
    }
    //serial.setPort(info);
    //serial.setBaudRate(QSerialPort::Baud9600);
    //if (serial.open(QIODevice::ReadWrite)){
    //    qDebug()<<serial.isOpen();
    //
    //    while(1){
    //        if(serial.waitForReadyRead(10)){
    //            QByteArray ba = serial.readAll();
    //
    //
    //            qDebug()<<ba ;
    //        }
    //    }
    //    serial.close();
    //}
}

void SelectComPort::handleSerialData()
{
    QByteArray ba = serial.readAll();
    QString str(ba);
    ui->textbox->insertPlainText(str);
}
