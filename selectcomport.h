#ifndef SELECTCOMPORT_H
#define SELECTCOMPORT_H

#include <QWidget>


#include <QSerialPort>

namespace Ui {
class SelectComPort;
}

class SelectComPort : public QWidget
{
    Q_OBJECT

public:
    explicit SelectComPort(QWidget *parent = 0);
    ~SelectComPort();

private slots:
    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void handleSerialData();

private:
    Ui::SelectComPort *ui;
    QSerialPort serial;
};

#endif // SELECTCOMPORT_H
