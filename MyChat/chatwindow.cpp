#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("聊天界面"));
    ui->textEdit_2->hide();
    this->setFixedSize(400,410);

    receiver = new QUdpSocket(this);
    receiver->bind(udp_receive_port, QUdpSocket::ShareAddress);
    connect(receiver, &QUdpSocket::readyRead, this, &ChatWindow::processPendingDatagram);

    sender = new QUdpSocket(this);
}

ChatWindow::ChatWindow(int receive_port,QString send_ip,int send_port,QString send_account,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("聊天界面"));
    ui->textEdit_2->hide();
    this->setFixedSize(400,410);

    receiver = new QUdpSocket(this);
    udp_receive_port = receive_port;
    receiver->bind(udp_receive_port, QUdpSocket::ShareAddress);
    connect(receiver, &QUdpSocket::readyRead, this, &ChatWindow::processPendingDatagram);

    sender = new QUdpSocket(this);
    udp_send_ip = send_ip;
    udp_send_port = send_port;
    udp_send_account = send_account;
    ui->label_name->setText(QObject::tr(" %1 -> %2  %3:%4").arg(udp_receive_port).arg(udp_send_account).arg(udp_send_ip).arg(udp_send_port));
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        {
            qDebug()<< QObject::tr("-- Qt 事件机制,键盘事件(Ctrl + Enter)");
            qDebug()<< QObject::tr("press: Ctrl + Enter");
            if(event->isAutoRepeat()) return;
            on_pushButton_send_clicked();
        }
    }
}

void ChatWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        {
            qDebug()<< QObject::tr("release: Ctrl + Enter");
            if(event->isAutoRepeat()) return;
        }
    }
}

void ChatWindow::processPendingDatagram()
{
    // 拥有等待的数据报
    while(receiver->hasPendingDatagrams())
    {
        QByteArray datagram;

        // 让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
        datagram.resize(receiver->pendingDatagramSize());

        // 接收数据报，将其存放到datagram中
        receiver->readDatagram(datagram.data(), datagram.size());
        //QListWidgetItem *item2=new QListWidgetItem(datagram);
        //item2->setForeground (Qt::red);//前景色(文字颜色)
        ui->listWidget->addItem(datagram);


        QDir userDir(QDir::currentPath());
        userDir.mkdir("userDir");
        userDir.cd("userDir");
        QFile file(userDir.absolutePath() + QString("/%1.txt").arg(udp_send_account));
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
            qDebug() << file.errorString();
        file.write(datagram);
        file.close();
    }
}

void ChatWindow::on_pushButton_send_clicked()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString strData = currentTime.toString("%1  yyyy-MM-dd hh:mm:ss\n").arg(udp_receive_port);

    QByteArray datagram = strData.toUtf8();
    //sender->writeDatagram(datagram.data(), datagram.size(),QHostAddress(udp_send_ip), udp_send_port);

    datagram += ui->textEdit->toPlainText().toUtf8();
    datagram += "\n";
    ui->listWidget->addItem(datagram);
    sender->writeDatagram(datagram.data(), datagram.size(),
                          QHostAddress(udp_send_ip), udp_send_port);


    QDir userDir(QDir::currentPath());
    userDir.mkdir("userDir");
    userDir.cd("userDir");
    QFile file(userDir.absolutePath() + QString("/%1.txt").arg(udp_send_account));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        qDebug() << file.errorString();
    file.write(datagram);
    file.close();
    ui->textEdit->setText("");
}

void ChatWindow::on_pushButton_close_clicked()
{
    close();
}

void ChatWindow::on_pushButton_chatdata_toggled(bool checked)
{
    ui->textEdit_2->setVisible(checked);
    if(checked)
    {
        ui->pushButton_chatdata->setText(tr("隐藏记录"));
        this->setFixedSize(668,410);
        QDir userDir(QDir::currentPath());
        userDir.mkdir("userDir");
        userDir.cd("userDir");
        QFile file(userDir.absolutePath() + QObject::tr("/%1.txt").arg(udp_send_account));
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
          qDebug() << file.errorString();

        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QByteArray line = file.readAll();
        QString temp = "-- 聊天记录：\n\n";
        temp += codec->toUnicode(line);

        qDebug() << QObject::tr("聊天记录：") << endl << temp;
        ui->textEdit_2->setText(temp);
        file.close();
    }
    else{
        ui->pushButton_chatdata->setText(tr("聊天记录"));
        this->setFixedSize(400,410);
    }
}
