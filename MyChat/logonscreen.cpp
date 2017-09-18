#include "logonscreen.h"
#include "ui_logonscreen.h"

//QString LogonScreen::userID;//全局变量方法

LogonScreen::LogonScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogonScreen)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("登录界面"));
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    //连接数据库
    if(createConnection())
    {
        qDebug()<<QObject::tr("-- 登录界面：数据库连接成功");
    }
    createTable();
    selectTable();
}

LogonScreen::~LogonScreen()
{
    delete ui;
}

bool LogonScreen::createConnection()
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

void LogonScreen::createTable()
{
    QSqlQuery query;
    //新建user表，account设置为主键，还有一个password项
    query.exec("create table user (account varchar(8) primary key,password varchar(8),ip varchar(16),port int)");
    //向表中插入记录
    query.exec("insert into user values('admin','admin','127.0.0.1',8000)");
    query.exec("insert into user values('1001','1001','127.0.0.1',8001)");
    query.exec("insert into user values('1002','1002','127.0.0.1',8002)");
}

void LogonScreen::selectTable()
{
    QStringList accountList;
    QSqlQuery query;
    //删除user表
    //query.exec("drop table user");
    //查找user表中的记录的account项和password项的值
    query.exec("select account,password,ip,port from user");
    //query.next()指向查找到的第一条记录，然后每次后移一条记录
    qDebug() << "account" << "password" << "ip" << "port";
    while(query.next())
    {
        QString value0 = query.value(0).toString();
        QString value1 = query.value(1).toString();
        QString value2 = query.value(2).toString();
        int value3 = query.value(3).toInt();

        accountList << value0;
        //显示查找记录
        qDebug() << value0 << value1 << value2 << value3;
    }
    QCompleter *completer = new QCompleter(accountList,this);
    completer->setCaseSensitivity(Qt::CaseSensitive);
    ui->lineEdit_account->setCompleter(completer);
}

bool LogonScreen::verify(const QString &strAccount, const QString &strPwd)
{
    QSqlQuery query;
    query.exec(QString("select * from user where account = '%1' and password = '%2'").arg(strAccount, strPwd));
    return query.next();
}

void LogonScreen::on_pushButton_close_clicked()
{
    close();
}

void LogonScreen::on_pushButton_login_clicked()
{
    QString account = ui->lineEdit_account->text();
    QString password = ui->lineEdit_password->text();
    qDebug()<<QObject::tr("-- 键入内容");
    qDebug()<<QObject::tr("用户名：%1").arg(account);
    qDebug()<<QObject::tr("密码：%1").arg(password);

    if(verify(account,password))
    {
        accept();
        emit user_signal(account);
        qDebug()<<QObject::tr("signal : emit user_signal(%1)").arg(account);
        //LogonScreen::userID = account;//全局变量方法
        //qDebug()<<QObject::tr("input userID : %1").arg(userID);
    }
    else{
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle(QObject::tr("提示"));
        dialog->resize(250,50);
        dialog->setModal(true);
        QLabel *label = new QLabel(dialog);
        label->setText(QObject::tr("   用户名或密码错误\n"));
        dialog->show();
        ui->lineEdit_account->clear();
        ui->lineEdit_password->clear();
    }
}
