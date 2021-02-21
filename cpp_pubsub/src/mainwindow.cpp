#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <QApplication>
#include <qtimer.h>
using std::placeholders::_1;
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
std::string aa="";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::on_toolButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


MinimalSubscriber::MinimalSubscriber(): Node("minimal_subscriber")
  {

    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }


void MinimalSubscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg)
  {

    QEventLoop loop;
    aa=msg->data.c_str();
    //RCLCPP_INFO(this->get_logger(), "joe heard: '%s'", msg->data.c_str());
    //https://blog.csdn.net/weixin_44741023/article/details/92151279
    QTimer::singleShot(10*1, &loop, SLOT(quit()));
    loop.exec();
  }

void MainWindow::on_toolButton_clicked(bool)
{
 //ui->pushButton->setText("clicked");
   ui->listWidget->addItem(aa.c_str());

}



