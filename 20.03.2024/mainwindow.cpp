#include "mainwindow.h"
#include "product.h"
#include "ui_mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Product bread(ui->lvl_bread,
                  ui->bread_price,
                  ui->create_speed_bread,
                  ui->upgrade_bread_speed,
                  ui->upgrade_bread_price,
                  ui);

    ui->setupUi(this);
    connect(ui->create_bread, SIGNAL(clicked()),this,SLOT(createProduct(bread)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

