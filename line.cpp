#include "line.h"

Line::Line(int x,int y,QColor color,int linewidth):
    Shape(x,y,color,linewidth)
{
line= new QGraphicsLineItem(x,y,1,1);
line->setPen(pen);
}

void Line:: setParemeters(int parameter1,int parameter2){

     this->parameter1=parameter1;
    this->parameter2=parameter2;

    line->setLine(x,y,parameter1,parameter2);

}
 Line:: ~Line(){

}

float Line:: getperimeter(int parameter1,int parameter2){
  perimeter=pow((pow((x-parameter1),2)+pow((y-parameter2),2)),0.5);
  return perimeter;
}
