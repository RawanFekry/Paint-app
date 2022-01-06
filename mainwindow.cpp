#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,600);
    this->setFixedSize(600,600);
//    ui->graphicsView->resize(500,500);
    ui->graphicsView->setFixedSize(500,500);
    undoStack = new QUndoStack(this);
    scene = new newscene(nullptr, undoStack);
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







void MainWindow::on_lineBtn_clicked()
{
//    scene->selectShape(1);
}


void MainWindow::on_rectBtn_clicked()
{
//    scene->selectShape(2);
}


void MainWindow::on_circleBtn_clicked()
{
//    scene->selectShape(3);
}



void MainWindow::on_triangBtn_clicked()
{
//    scene->selectShape(4);
}


void MainWindow::on_undoBtn_clicked()
{
//    undoStack->undo();
}


void MainWindow::on_redoBtn_clicked()
{
//    undoStack->redo();
}


void MainWindow::on_shapecolorBtn_clicked()
{
//    QColor color = QColorDialog::getColor(scene->getLineColor(), this, "Please, select the line color");
//    scene->setLineColor(color);
}


void MainWindow::on_fillshapeBtn_clicked()
{
//    QBrush brush(scene->getLineColor(),Qt::Dense5Pattern);
//    scene->setStyleShape(brush);
}


void MainWindow::on_linewidthSpn_valueChanged(int thickness)
{
    scene->setLineWidth(thickness);
}





void MainWindow::on_actShapes_Line_triggered()
{
    scene->selectShape(1);
}


void MainWindow::on_actShapes_Rectangle_triggered()
{
    scene->selectShape(2);
}



void MainWindow::on_actShapes_Circle_triggered()
{
    scene->selectShape(3);
}



void MainWindow::on_actShapes_Triangle_triggered()
{
    scene->selectShape(4);
}


void MainWindow::on_actUndo_triggered()
{
    undoStack->undo();
}


void MainWindow::on_actRedo_triggered()
{
    undoStack->redo();
}


void MainWindow::on_actColor_Line_triggered()
{
    QColor color = QColorDialog::getColor(scene->getLineColor(), this, "Please, select the line color");
    scene->setLineColor(color);
    QBrush brush(scene->getLineColor(),Qt::SolidPattern);
    scene->setStyleShape(brush);
}


void MainWindow::on_actLinestyle_Dense_Level_1_triggered()
{
    QBrush brush(scene->getLineColor(),Qt::Dense1Pattern);
    scene->setStyleShape(brush);
}


void MainWindow::on_actLinestyle_Dense_Level_2_triggered()
{
    QBrush brush(scene->getLineColor(),Qt::Dense3Pattern);
    scene->setStyleShape(brush);
}


void MainWindow::on_actLinestyle_Dense_Level_3_triggered()
{
    QBrush brush(scene->getLineColor(),Qt::Dense5Pattern);
    scene->setStyleShape(brush);
}


void MainWindow::on_actLinestyle_Solid_triggered()
{
    QBrush brush(scene->getLineColor(),Qt::SolidPattern);
    scene->setStyleShape(brush);
}


void MainWindow::on_actDelete_triggered()
{
    Shape*  deletedShape = scene->getProcesses()->search(QString("Shape 2"));
    if(deletedShape!= nullptr){
    deleteCommand* deleteItem = new deleteCommand(deletedShape, scene->getProcesses());
    undoStack->push(deleteItem);
    }
}

