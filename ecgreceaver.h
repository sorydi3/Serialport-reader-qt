#ifndef ECGRECEAVER_H
#define ECGRECEAVER_H
#include <QObject>
#include <QSerialPort>
#include <QDebug>

class ECGreceaver :  public QObject

{
    Q_OBJECT

public:
    ECGreceaver(QObject *parent);
    ECGreceaver();

protected slots:
    void readData();

private:
    void openPort();
    bool isOpentPort();

protected:

    QSerialPort serialPort;
};

#endif // ECGRECEAVER_H
