#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}


Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui -> lcdNumber -> display(money);
    checkButtonStatus();
}

void Widget::checkButtonStatus()
{
    if(money < 100) {
        ui->pb_coffee->setEnabled(false);
        ui->pb_tea->setEnabled(false);
        ui->pb_milk->setEnabled(false);
    } else if(money < 150) {
        ui->pb_coffee->setEnabled(true);
        ui->pb_tea->setEnabled(false);
        ui->pb_milk->setEnabled(false);
    } else if(money < 200) {
        ui->pb_coffee->setEnabled(true);
        ui->pb_tea->setEnabled(true);
        ui->pb_milk->setEnabled(false);
    } else {
        ui->pb_coffee->setEnabled(true);
        ui->pb_tea->setEnabled(true);
        ui->pb_milk->setEnabled(true);
    }
}

void Widget::on_pb_10_clicked()
{
    changeMoney(10);

}


void Widget::on_push_50_clicked()
{

    changeMoney(50);

}


void Widget::on_push_100_clicked()
{
    changeMoney(100);

}


void Widget::on_push_500_clicked()
{
    changeMoney(500);

}

void Widget::on_pb_coffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pb_tea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pb_milk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{

    while(money>=10){

        if(money / 500 > 0){
            h5 = money / 500;
            money = money % 500;
            continue;
        }
        else if(money / 100 > 0){
            h1 = money / 100;
            money = money % 100;
            continue;

        }
        else if(money / 50 > 0){
            t5 = money / 50;
            money = money % 50;
            continue;
        }
        else if(money / 10 > 0){
            t1 = money / 10;
            money = money % 10;
            continue;
        }
    }
    QString message = QString("10: %1\n50: %2\n100: %3\n500: %4").arg(t1).arg(t5).arg(h1).arg(h5);
    QMessageBox::information(nullptr, "Coins", message);
    money=0;
    t1=0;
    t5=0;
    h1=0;
    h5=0;
}


