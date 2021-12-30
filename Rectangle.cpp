
#include<Rectangle.h>





Rectangle::Rectangle(int x,int y,QColor color,int linewidth ):
    Shape(x,y,color,linewidth){

rect=new QGraphicsRectItem(x,y,1,1);
rect->setPen(pen);
}

Rectangle::~Rectangle(){
}

void Rectangle::setParemeters(int parameter1, int parameter2){
    this->parameter1=parameter1;
    this->parameter2=parameter2;
    rect->setRect(x,y,parameter1,parameter2);
}

float Rectangle::getperimeter(int parameter1,int parameter2){
    perimeter=2*(parameter1+parameter2);
  return perimeter;
}

