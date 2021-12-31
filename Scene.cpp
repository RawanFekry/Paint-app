#include "Scene.h"
#include <iostream>


newscene::newscene(QObject *parent):
    QGraphicsScene(parent)
{

selectedShape = 3;

};

void newscene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        x1 = event->scenePos().rx();
        y1 = event->scenePos().ry();
        switch(selectedShape){
        case 1:
            shape = new Line(x1, y1,QColor(Qt::red),2,this);
            break;
        case 2:
            shape = new Rectangle(x1, y1,QColor(Qt::red),2,this);
            break;
        case 3:
            shape = new Circle(x1, y1,QColor(Qt::red),2,this);
            break;
        case 4:
            shape = new Triangle(x1, y1,QColor(Qt::red),2,this);
            break;
        }


        shape->addShape();
        pressing = true;
        this->update();
    }
}

void newscene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

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
}
}

