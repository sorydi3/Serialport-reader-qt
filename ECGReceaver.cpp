#include "ecgreceaver.h"

ECGreceaver::ECGreceaver(QObject *parent) : QObject{parent}
{


}

ECGreceaver::ECGreceaver()
{
    serialPort.setPortName("COM2");
    serialPort.setBaudRate(QSerialPort::Baud9600);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::TwoStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);
    openPort();
    connect(&serialPort,SIGNAL(readyRead()),this,SLOT(readData()));

}



void ECGreceaver::readData()
{
 qDebug() << "data ready";
 qDebug() << serialPort.readAll();
}

void ECGreceaver::openPort()
{
    serialPort.open(QSerialPort::ReadOnly);
}

bool ECGreceaver::isOpentPort()
{
    return serialPort.isOpen();
}
