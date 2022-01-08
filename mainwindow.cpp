#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1400,1400);
    this->setFixedSize(1400,1400);
//    ui->graphicsView->resize(500,500);
    //ui->graphicsView->setFixedSize(500,500);
    undoStack = new QUndoStack(this);
    scene = new newscene(nullptr, undoStack);
    scene->setInfoTable(ui->tblwdgShape);
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
    scene->UpdateTable();
}


void MainWindow::on_actRedo_triggered()
{
    undoStack->redo();
    scene->UpdateTable();
}


void MainWindow::on_actColor_Line_triggered()
{
    QColor color = QColorDialog::getColor(scene->getLineColor(), this, "Please, select the line color");
    scene->setLineColor(color);
}


void MainWindow::on_actShapecolor_triggered()
{
    QColor color = QColorDialog::getColor(scene->getShapeColor(), this, "Please, select the line color");
    scene->setShapeColor(color);
    QBrush brush(scene->getShapeColor(),Qt::NoBrush);
    scene->setStyleShape(brush);

}

void MainWindow::on_actLinestyle_No_Brush_triggered()
{
    QBrush brush(scene->getShapeColor(),Qt::NoBrush);
    scene->setStyleShape(brush);
}

void MainWindow::on_actLinestyle_Solid_triggered()
{
    QBrush brush(scene->getShapeColor(),Qt::SolidPattern);
    scene->setStyleShape(brush);
}

void MainWindow::on_actLinestyle_Dense_Level_1_triggered()
{
    QBrush brush(scene->getShapeColor(),Qt::Dense1Pattern);
    scene->setStyleShape(brush);
}


void MainWindow::on_actLinestyle_Dense_Level_2_triggered()
{
    QBrush brush(scene->getShapeColor(),Qt::Dense3Pattern);
    scene->setStyleShape(brush);
}


void MainWindow::on_actLinestyle_Dense_Level_3_triggered()
{
    QBrush brush(scene->getShapeColor(),Qt::Dense5Pattern);
    scene->setStyleShape(brush);
}






void MainWindow::on_btnSearch_clicked()
{
     Shape*  searchedShape = scene->getProcesses()->search(QString(ui->ipLineEdit_Search->text()));
     if (searchedShape != nullptr){
     ui->opLineEdit->setText(searchedShape->getname());
     }
}



void MainWindow::on_btnDelete_clicked()
{
    Shape*  deletedShape = scene->getProcesses()->search(QString(ui->ipLineEdit_Delete->text()));
    if(deletedShape!= nullptr){
    deleteCommand* deleteItem = new deleteCommand(deletedShape, scene->getProcesses());
    undoStack->push(deleteItem);
    scene->UpdateTable();
    }
}





void MainWindow::on_btnSortA_clicked()
{
    scene->getProcesses()->sort_Ascending();
    scene->UpdateTable();
}


void MainWindow::on_btnSortD_clicked()
{
    scene->getProcesses()->sort_Descending();
    scene->UpdateTable();
}

