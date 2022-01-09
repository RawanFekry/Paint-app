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
    QColor color = QColorDialog::getColor();
    scene->setLineColor(color);

}


void MainWindow::on_actShapecolor_triggered()
{
    QColor color = QColorDialog::getColor();

    brush->setColor(color);


}

void MainWindow::on_actLinestyle_No_Brush_triggered()
{
    brush->setStyle(Qt::NoBrush);

}

void MainWindow::on_actLinestyle_Solid_triggered()
{

    brush->setStyle(Qt::SolidPattern);
}

void MainWindow::on_actLinestyle_Dense_Level_1_triggered()
{
    brush->setStyle(Qt::Dense1Pattern);
}


void MainWindow::on_actLinestyle_Dense_Level_2_triggered()
{
    brush->setStyle(Qt::Dense3Pattern);
}


void MainWindow::on_actLinestyle_Dense_Level_3_triggered()
{
    brush->setStyle(Qt::Dense5Pattern);
}






void MainWindow::on_btnSearch_clicked()
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
         ui->opLineEdit->setText("<font color='red'>There is no matching name.</font");
     }
}



void MainWindow::on_btnDelete_clicked()
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


void MainWindow::on_tblwdgShape_cellChanged(int row, int column)
{
    if(column!=0)
        return;
    QString newName = QString(ui->tblwdgShape->item(row, column)->data(Qt::DisplayRole).toString());
    scene->getProcesses()->getMemory()->at(row)->setname(newName);

}

