#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_Start_Stop->setStyleSheet("color : green");
    ui->pushButton_circle->setEnabled(false);
    watch = new Startwatch(this);
    ui->lineEdit_time->setText(watch->look_time().toString("hh:mm:ss.z"));
    connect(watch, &Startwatch::time_signal_start, this, &MainWindow::slotTimerAlarm);
    connect(watch, &Startwatch::time_signal, this, &MainWindow::slotTimerWatch);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Start_Stop_clicked()
{
    if(start_stop == 0) {
        ui->pushButton_Start_Stop->setText("Стоп");
        ui->pushButton_Start_Stop->setStyleSheet("color : red");
        ui->pushButton_circle->setEnabled(true);
        watch->start();
        start_stop = 1;
    } else {
        ui->pushButton_Start_Stop->setText("Старт");
        ui->pushButton_Start_Stop->setStyleSheet("color : green");
        ui->pushButton_circle->setEnabled(false);
        watch->stop();
        start_stop = 0;
    }
}

void MainWindow::slotTimerAlarm()
{
    watch->slotTimerAlarm();
}

void MainWindow::slotTimerWatch()
{
    ui->lineEdit_time->setText(watch->look_time().toString("hh:mm:ss.z"));
}


void MainWindow::on_pushButton_clear_clicked()
{
    watch->clear();
    ui->lineEdit_time->setText(watch->look_time().toString("hh:mm:ss.z"));
    ui->textBrowser_circle->clear();
    cir_n = 1;
}


void MainWindow::on_pushButton_circle_clicked()
{
    ui->textBrowser_circle->append("№"+QString::number(cir_n)+". Время круга: " + watch->diff().toString("hh:mm:ss.z"));
    cir_n++;
}
