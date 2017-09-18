#include "userwidget.h"
#include "ui_userwidget.h"
#include "chatwindow.h"

userwidget::userwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userwidget)
{
    ui->setupUi(this);

    ui->label_name->setText("friend");
}

userwidget::userwidget(int receive_port,QString send_ip,int send_port,QString send_account,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userwidget)
{
    ui->setupUi(this);
    udp_receive_port = receive_port;
    udp_send_ip = send_ip;
    udp_send_port = send_port;
    udp_send_account = send_account;
    ui->label_pic->setPixmap(QPixmap(QString(":/userPic/%1.jpg").arg(udp_send_account)));
    ui->label_name->setText(QObject::tr("%1").arg(udp_send_account));
    ui->label_diy->setText(QObject::tr("%1:%2").arg(udp_send_ip).arg(udp_send_port));
}

userwidget::~userwidget()
{
    delete ui;
}

void userwidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        ChatWindow *chat = new ChatWindow(udp_receive_port,udp_send_ip,udp_send_port,udp_send_account);
        chat->show();
    }
}
