#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QString>

namespace Ui {
class userwidget;
}

class userwidget : public QWidget
{
    Q_OBJECT

public:
    explicit userwidget(QWidget *parent = 0);
    explicit userwidget(int receive_port,QString send_ip ,int send_port,QString send_account,QWidget *parent = 0);
    ~userwidget();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    Ui::userwidget *ui;
    QString udp_send_ip;
    int udp_send_port;
    int udp_receive_port;
    QString udp_send_account;
};

#endif // USERWIDGET_H
