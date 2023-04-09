#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static int currentImage = 1;
        currentImage = (currentImage % 3) + 1;
        QString imagePath = QString(":/images/image%1.png").arg(currentImage);
        QPixmap pixmap(imagePath);
        ui->label->setPixmap(pixmap);
}

