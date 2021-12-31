#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,600);
    this->setFixedSize(600,600);
//    ui->graphicsView->resize(500,500);
    ui->graphicsView->setFixedSize(500,500);

//    setCentralWidget(ui->graphicsView);
    scene = new newscene();
//    QGraphicsRectItem *rect = new QGraphicsRectItem(500, 500, 100, 100);
//    scene->addItem(rect);
//    rect->setRect(500, 500, -50, -500);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,100,100);
    ui->graphicsView->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

MainWindow::~MainWindow()
{
    delete ui;

}

