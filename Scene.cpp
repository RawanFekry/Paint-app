#include "Scene.h"
#include <iostream>
#include <QtDebug>


int Line::lineOrder = 1;
int Circle::circleOrder = 1;
int Rectangle::rectOrder = 1;
int Triangle::triangleOrder = 1;

newscene::newscene(QObject *parent, QUndoStack* undoStack):
    QGraphicsScene(parent),
  linecolor(Qt::black),
  linewidth(1)


{
    shapesMemory = new QVector<Shape*>();
    Do = new Processes(shapesMemory);
    this->undoStack = undoStack;
    selectedShape = 1;
    shapeOrder = 0;

};


void newscene::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if (event->button() == Qt::LeftButton){
        x1 = event->scenePos().rx();
        y1 = event->scenePos().ry();
        switch(selectedShape){
        case 1:
            shape = new Line(x1, y1,linecolor,*brusher,linewidth,this);
            break;
        case 2:
            shape = new Rectangle(x1, y1,linecolor,*brusher,linewidth,this);
            break;
        case 3:
            shape = new Circle(x1, y1,linecolor,*brusher,linewidth,this);
            break;
        case 4:
            shape = new Triangle(x1, y1,linecolor,*brusher,linewidth,this);
            break;
        }

        addItem = new addCommand(shape, Do);
        undoStack->push(addItem);
        pressing = true;
        this->update();
    }
}


void newscene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if  ((event->buttons() & Qt::LeftButton) && pressing){
        x2 = event->scenePos().rx();
        y2 = event->scenePos().ry();
        shape->setParemeters(x2, y2);
        this->update();
        }
}


void newscene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && pressing) {
        pressing = false;
        this->update();
        UpdateTable();
    }
}


void newscene::selectShape(int shapeNum)
{
     selectedShape = shapeNum;
}



Processes* newscene::getProcesses()
{
    return Do;
}

void newscene:: setLineColor(QColor color){
     this->linecolor = color;
}


void newscene:: setLineWidth(int linewidth){
     this->linewidth = linewidth;
}

void newscene::setBrush(QBrush* brush)
{
    brusher = brush;
}




QColor newscene:: getLineColor(){
    return this->linecolor;
}

int newscene:: getLineWidth(){
    return this->linewidth;
}


void newscene::UpdateTable()
{
    QStringList TableLabel;
    TableLabel<<"Name"<<"Type"<<"Perimter"<<"LineWeight"<<"Color";

    table->setColumnCount(5);
    table->setHorizontalHeaderLabels(TableLabel);
    while (table->rowCount() > 0)
    {
        table->removeRow(0);
    }

    for(auto* item:*shapesMemory){
        // Initializing the Figure Values
        QString name= item->Shape::getname();
        QString Type= item->Shape::getshapeType();
        QString Perimeter = QString::number(item->Shape::get_perimeter());
        QString linewidth = QString::number(item->Shape::pen.width());
        QString linecolor = (item->Shape::pen.color()).name();


        // Insert New row in the table
        table->insertRow(table->rowCount());

        // Setting the row values
        table->setItem(table->rowCount()-1, 0, new QTableWidgetItem(name));
        table->setItem(table->rowCount()-1, 1, new QTableWidgetItem(Type));
        table->setItem(table->rowCount()-1, 2, new QTableWidgetItem(Perimeter));
        table->setItem(table->rowCount()-1, 3, new QTableWidgetItem(linewidth));
        table->setItem(table->rowCount()-1, 4, new QTableWidgetItem(linecolor));



        table->setStyleSheet(
                    "QTableWidget{"
                    "background-color: #C0C0C0;"
                    "alternate-background-color: #606060;"
                    "selection-background-color: #282828;"
                    "}");
        table->setAlternatingRowColors(true);

        //Cell Items Properties
        table->setSelectionMode(QAbstractItemView::SingleSelection);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setTextElideMode(Qt::ElideRight);

        //Table Properties
        table->setShowGrid(true);
        table->setGridStyle(Qt::DotLine);
        table->setSortingEnabled(true);
        table->setCornerButtonEnabled(true);

        //Header Properties
        table->horizontalHeader()->setVisible(true);
        table->horizontalHeader()->setDefaultSectionSize(150);
        table->horizontalHeader()->setStretchLastSection(true);


    }

}

void newscene::setInfoTable(QTableWidget *table)
{
    this->table= table;
}




