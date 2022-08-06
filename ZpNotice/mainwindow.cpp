#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZpNotification/ZpNotificationManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton * button = new QPushButton("弹窗", this);
        ZpNotificationManager *manager = new ZpNotificationManager(this);

        connect(button, &QPushButton::clicked, manager, [manager]{
            manager->notify("新消息", "新消息新消息新消息新消息", "://img/message.png", "http://www.github.com");
        });

}

MainWindow::~MainWindow()
{
    delete ui;
}

