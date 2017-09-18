#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QString>
#include <QDebug>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QString user_account;
    int user_port;

    QPoint offset;
    QVBoxLayout *vertical_layout;

    bool createConnection();
    void matchUserFriend();

protected:
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_pushButton_quit_clicked();
    void on_pushButton_min_clicked();
    void getUserValue(QString value);
};

#endif // MAINWINDOW_H
