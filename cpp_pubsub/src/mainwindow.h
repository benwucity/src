#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QtWidgets/QMainWindow"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
class MinimalSubscriber;
             }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_toolButton_clicked(bool checked);
private:
    Ui::MainWindow *ui;
};

class MinimalSubscriber: public rclcpp::Node{
public:
    MinimalSubscriber();
private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg);
};
#endif // MAINWINDOW_H
