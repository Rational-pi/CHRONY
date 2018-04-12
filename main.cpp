#include "mainwindow.h"
#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//
//    return a.exec();
//}




#include <QCoreApplication>
#include <QSerialPort>
#include <QtSerialPort/QtSerialPort>
#include <QDebug>
#include <iostream>
#include <QSerialPortInfo>
#include <iostream>

std::ostream& operator << ( std::ostream& out, const QString& bs ){
    out << bs.toStdString();
    return out;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        std::cout << "Name        : " << info.portName()    << std::endl;
        std::cout << "Description : " << info.description() << std::endl;
        std::cout << "Manufacturer: " << info.manufacturer()<< std::endl << std::endl;

        //QSerialPort serial;
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
    return a.exec();
}
