#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatwindow.h"
#include "logonscreen.h"
#include "userwidget.h"

//,Qt::FramelessWindowHint
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("主界面"));

    LogonScreen *login = new LogonScreen(this);//登录界面
    connect( login,SIGNAL(user_signal(QString)),this,SLOT(getUserValue(QString)) );
    if( login->exec() == QDialog::Accepted )
    {
        ui->label_title->setText(QObject::tr("account:%1").arg(user_account));
        this->show();
        vertical_layout = new QVBoxLayout(ui->page_friend);
        matchUserFriend();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::createConnection()
{
    //添加数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名称
    db.setDatabaseName("memory.db");
    //打开数据库
    if(!db.open())
    {
        qDebug()<<QObject::tr("打开数据库失败");
        return false;
    }
    return true;
}

void MainWindow::matchUserFriend()
{
    //连接数据库
    if(createConnection())
    {
        qDebug()<< QObject::tr("-- 主界面：数据库连接成功");
    }

    QSqlQuery query;
    query.exec(QString("select account,password,ip,port from user where account = '%1'").arg(user_account));
    query.next();
    user_port = query.value(3).toInt();
    qDebug()<< QObject::tr("account: %1").arg(user_account);
    qDebug()<< QObject::tr("ip: %1").arg(query.value(2).toString());
    qDebug()<< QObject::tr("port: %1").arg(user_port);

    qDebug() << QObject::tr("-- 用户好友列表：");
    query.exec("select account,password,ip,port from user");
    while(query.next())
    {
        QString value0 = query.value(0).toString();
        QString value1 = query.value(1).toString();
        QString value2 = query.value(2).toString();
        int value3 = query.value(3).toInt();

        if(value0 == user_account)continue;
        qDebug() << value0 << value1 << value2 << value3;
        userwidget *user = new userwidget(user_port,value2,value3,value0);
        vertical_layout->addWidget(user);
    }

    //userwidget *user= new userwidget(user_port,"127.0.0.1",8001);
    //userwidget *user_1= new userwidget(user_port,"127.0.0.1",8002);
    //vertical_layout->addWidget(user);
    vertical_layout->addStretch(0);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug()<<offset;
    if(event->buttons() & Qt::LeftButton)
    {      // 这里必须使用buttons()
        QPoint temp;
        temp = event->globalPos() - offset;
        move(temp);// 使用鼠标指针当前的位置减去差值，就得到了窗口应该移动的位置
    }
}

void MainWindow::on_pushButton_quit_clicked()
{
    this->close();
    MainWindow *switch_accoumt = new MainWindow();
    /*
    this->close();
    LogonScreen *login_1 = new LogonScreen(this);//登录界面

    connect( login_1,SIGNAL(user_signal(QString)),this,SLOT(getUserValue(QString)) );

    if( login_1->exec() == QDialog::Accepted )
    {
        vertical_layout = new QVBoxLayout(ui->page_friend);
        matchUserFriend();
        this->show();
    }
    */
}

void MainWindow::on_pushButton_min_clicked()
{
    setWindowState(Qt::WindowMinimized);
}

void MainWindow::getUserValue(QString value)
{
    user_account = value;
    qDebug()<< QObject::tr("slot ：getUserValue(%1)").arg(value);
}
