#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1400,900);
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
// edited
    brush = new QBrush();
    brush->setStyle(Qt::NoBrush);
    scene->setBrush(brush);
    brush->setColor(Qt::black);


}

MainWindow::~MainWindow()
{
    delete ui;

}








void MainWindow::on_linewidthSpn_valueChanged(int thickness)
{
    scene->setLineWidth(thickness);
}


// function to change the shape name in the table

void MainWindow::on_tblwdgShape_cellChanged(int row, int column)
{
    if(column!=0)
        return;
    QString newName = QString(ui->tblwdgShape->item(row, column)->data(Qt::DisplayRole).toString());
    scene->getProcesses()->getMemory()->at(row)->setname(newName);

}
//=========================================================================================

void MainWindow::on_actionUndo_triggered()
{
    undoStack->undo();
    scene->UpdateTable();
}


void MainWindow::on_actionRedo_triggered()
{
    undoStack->redo();
    scene->UpdateTable();
}


void MainWindow::on_actionLine_triggered()
{
   scene->selectShape(1);
}


void MainWindow::on_actionRectangle_triggered()
{
   scene->selectShape(2);
}


void MainWindow::on_actionCircle_triggered()
{
   scene->selectShape(3);
}


void MainWindow::on_actionTriangle_triggered()
{
   scene->selectShape(4);
}



void MainWindow::on_actionLine_color_triggered()
{
    QColor color = QColorDialog::getColor();
    scene->setLineColor(color);
}


// the following 5 functions to change line style
void MainWindow::on_actionLine_Style_1_triggered()
{
    brush->setStyle(Qt::Dense1Pattern);
}


void MainWindow::on_actionLine_Style_2_triggered()
{
    brush->setStyle(Qt::Dense3Pattern);
}


void MainWindow::on_actionLine_Style_3_triggered()
{
     brush->setStyle(Qt::Dense5Pattern);
}


void MainWindow::on_actionSolid_triggered()
{
    brush->setStyle(Qt::SolidPattern);
}


void MainWindow::on_actionNO_Brush_triggered()
{
   brush->setStyle(Qt::NoBrush);
}

// process to delete the shape
void MainWindow::on_actionDelete_triggered()
{
    Shape*  deletedShape = scene->getProcesses()->search(QString(ui->ipLineEdit_Delete->text()));
    if(deletedShape!= nullptr){
        deleteCommand* deleteItem = new deleteCommand(deletedShape, scene->getProcesses());
        undoStack->push(deleteItem);
        scene->UpdateTable();
        ui->deleErrorMesg->setText("");
    }
    else{

        ui->deleErrorMesg->setText("<font color='red'>There is no matching name.</font>");


    }
}

// process to search for the shape
void MainWindow::on_actionSearch_triggered()
{
    Shape*  searchedShape = scene->getProcesses()->search(QString(ui->ipLineEdit_Search->text()));
    if (searchedShape != nullptr){
        QString name = "Shape Name: " + searchedShape->getname()+"\n\n";
        QString shapeType = "Shape Type: " + searchedShape->getshapeType() + "\n\n";
        QString perimeter = "Perimter: " + QString::number(searchedShape->get_perimeter()) + "\n\n";
        QString lineWidth = "Line Width: " + QString::number(searchedShape->Shape::pen.width()) + "\n\n";
        QString color = "Color: " + searchedShape->Shape::pen.color().name() + "\n\n";
        QString text(name + shapeType + perimeter + lineWidth + color);
        ui->opLineEdit->setText("<font color='black'> </font");
        ui->opLineEdit->setText(text);
    }
    else{
        // error message if the shape is not exist
        ui->opLineEdit->setText("<font color='red'>There is no matching name.</font");
    }
}


void MainWindow::on_actionShape_color_triggered()
{
    QColor color = QColorDialog::getColor();

    brush->setColor(color);
}

// button to sort shapes ascending
void MainWindow::on_actionSorting_Ascending_triggered()
{
    scene->getProcesses()->sort_Ascending();
    scene->UpdateTable();
}

// button to sort shapes descending
void MainWindow::on_actionSorting_Descending_triggered()
{
    scene->getProcesses()->sort_Descending();
    scene->UpdateTable();
}


