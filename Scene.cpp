#include "Scene.h"
#include <iostream>


newscene::newscene(QObject *parent):
    QGraphicsScene(parent)
{
//    polygon  << QPointF(0, 0) << QPointF(0, 30) << QPointF(30, 30)
//             ;
//    p = this->addPolygon(polygon,QPen(QColor(Qt::red)));
//   // this->addItem(p);


};

void newscene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        x = event->scenePos().rx();
        y = event->scenePos().ry();
        shape = new Rectangle(x, y,QColor(Qt::red),2);
        this->addItem(shape->rect);
        pressing = true;
        this->update();
    }
}

void newscene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if  ((event->buttons() & Qt::LeftButton) && pressing){
        width = event->scenePos().rx()- x;
        hieght = event->scenePos().ry() - y;
        shape->setParemeters(width,hieght);
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
// rectangle=1 circle=2 selectedshape=1
