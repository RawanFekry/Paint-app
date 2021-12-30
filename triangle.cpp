#include "triangle.h"

Triangle::Triangle(int x,int y,QColor color,int linewidth):
    Shape(x,y,color,linewidth)
{
    polygon << QPointF(x, y) << QPointF(parameter1, parameter2) << QPointF(x-(parameter1-x),parameter2);  //  paremeter1=x and parameter2=y
    line= new QGraphicsLineItem(x,y,1,1);
    line->setPen(pen);
}
Triangle:: ~Triangle(){

}

void Triangle::setParemeters(int parameter1, int parameter2){
    this->parameter1=parameter1;
    this->parameter2=parameter2;
    traingle->setPolygon(polygon);
}
float Triangle:: getperimeter(int parameter1,int parameter2){
    int lineLength;
    lineLength=pow((pow((x-parameter1),2)+pow((y-parameter2),2)),0.5);
    perimeter=3*lineLength;
    return perimeter;
}
