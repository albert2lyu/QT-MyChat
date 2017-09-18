#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QDateTime>
#include <QString>
#include <QDir>
#include <QFile>
#include <QKeyEvent>
#include <QDebug>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = 0);
    explicit ChatWindow(int receive_port,QString send_ip,int send_port,QString send_account,QWidget *parent = 0);
    ~ChatWindow();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::ChatWindow *ui;
    QUdpSocket *receiver;
    QUdpSocket *sender;
    QString udp_send_account;
    QString udp_send_ip;
    int udp_send_port;
    int udp_receive_port;

private slots:
    void processPendingDatagram();

    void on_pushButton_send_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_chatdata_toggled(bool checked);
};

#endif // CHATWINDOW_H
