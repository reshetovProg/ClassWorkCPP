#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    operation="";
    ui->setupUi(this);
    connect(ui->btn_1, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn_2, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn_3, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn_4, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn_5, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn_6, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn_7, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn_8, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn_9, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn_0, SIGNAL(clicked()),this,SLOT(getDigit()));
    connect(ui->btn_plus, SIGNAL(clicked()),this,SLOT(setOper()));
    connect(ui->btn_result, SIGNAL(clicked()),this,SLOT(getResult()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getDigit()
{
    QPushButton* btn = (QPushButton*)sender();
    QString str = btn->text();
    QString currentText = ui->text->text();
    if (currentText=="0") currentText="";
    ui->text->setText(currentText+str);
}

void MainWindow::setOper()
{
    QPushButton* btn = (QPushButton*)sender();
    operation=btn->text();
    prevNumber=ui->text->text();
    ui->text->setText("0");
}

void MainWindow::getResult()
{
    float num1 = prevNumber.toFloat();
    float num2 = ui->text->text().toFloat();
    if(operation=="+"){
        float num3 = num1+num2;
        ui->text->setText(QString::number(num3));
    }

}



