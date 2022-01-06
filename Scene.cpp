#include "Scene.h"
#include <iostream>
#include <QtDebug>

newscene::newscene(QObject *parent, QUndoStack* undoStack):
    QGraphicsScene(parent),
    linecolor(Qt::blue),
    linewidth(2),
    brusher(linecolor,Qt::SolidPattern)

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
            shape = new Line(x1, y1,linecolor,brusher,linewidth,this);
            break;
        case 2:
            shape = new Rectangle(x1, y1,linecolor,brusher,linewidth,this);
            break;
        case 3:
            shape = new Circle(x1, y1,linecolor,brusher,linewidth,this);
            break;
        case 4:
            shape = new Triangle(x1, y1,linecolor,brusher,linewidth,this);
            break;
        }

        addItem = new addCommand(shape, Do);
        undoStack->push(addItem);
        shape->setname(shapeOrder++);
        qDebug() <<shape->getname()<<" ";
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
        //Do->add(shape);
//        std::cout<<"Before: ";
//        printshapesInfo();
 //       Do->sort_Ascending();
        Do->sort_Descending();
//        std::cout<<"After: ";
//        printshapesInfo();
    }
}


void newscene::selectShape(int shapeNum)
{
     selectedShape = shapeNum;
}

void newscene::printshapesInfo()
{
    for(auto shape: *shapesMemory)
    {
        std::cout<< shape->getperimeter()<<" ";
    }
    std::cout<<std::endl<<"====================="<<std::endl;
}

Processes* newscene::getProcesses()
{
    return Do;
}

void newscene:: setLineColor(QColor color){
     this->linecolor = color;
}

//void newscene:: setShapeColor(QColor color){
//    this->shapecolor = color;
//}

void newscene:: setStyleShape(QBrush brush){
    this->brusher = brush;
}

void newscene:: setLineWidth(int linewidth){
     this->linewidth = linewidth;
}




QColor newscene:: getLineColor(){
    return this->linecolor;
}

int newscene:: getLineWidth(){
    return this->linewidth;
}

QBrush newscene:: getStyleShape(){
    return this->brusher;
}

//QColor newscene:: getShapeColor(){
//    return this->shapecolor;
//}



