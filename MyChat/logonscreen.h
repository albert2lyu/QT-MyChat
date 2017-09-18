#ifndef LOGONSCREEN_H
#define LOGONSCREEN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QCompleter>

namespace Ui {
class LogonScreen;
}
class LogonScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LogonScreen(QWidget *parent = 0);
    ~LogonScreen();

private:
    Ui::LogonScreen *ui;
    bool createConnection();
    void createTable();
    void selectTable();
    bool verify(const QString &strAccount, const QString &strPwd);
    //static QString userID;//全局变量方法

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_login_clicked();

signals:
    void user_signal(QString value);
};

#endif // LOGONSCREEN_H
