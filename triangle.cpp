#include "triangle.h"

Triangle::Triangle(int x1,int y1,QColor color,int linewidth, QGraphicsScene* scene):
    Shape(x1,y1,color,linewidth, scene)
{
    polygon << QPointF(x1, y1) << QPointF(x1, y1) << QPointF(x1, y1);
    triangle= new QGraphicsPolygonItem(polygon);
    triangle->setPen(pen);
}
Triangle::Triangle(QString name,float perimeter):
    Shape( name, perimeter){
    this->name=name;
    this->perimeter=perimeter;

}
Triangle:: ~Triangle(){

}

void Triangle::setParemeters(int x2, int y2){
    length=pow((pow((x1-x2),2)+pow((y1-y2),2)),0.5);
    polygon.clear();
    polygon << QPointF(x1, y1) << QPointF(x1+.5*length, y2) << QPointF(x1-.5*length, y2);
    triangle->setPolygon(polygon);
}
float Triangle:: getperimeter(){


    perimeter=3*abs(length);
    return perimeter;
}


void Triangle::addShape(){
scene->addItem(triangle);
scene->update();
}

void Triangle::deleteShape()
{
    scene->removeItem(triangle);
    scene->update();

}
