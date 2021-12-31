
#include<Rectangle.h>

Rectangle::Rectangle(int x1,int y1,QColor color,int linewidth, QGraphicsScene* scene ):
    Shape(x1 ,y1 , color, linewidth, scene){

rect=new QGraphicsRectItem(x1,y1,1,1);
rect->setPen(pen);
}

Rectangle::~Rectangle(){
}

void Rectangle::setParemeters(int x2, int y2){
    width = x2 - x1;
    hieght = y2 - y1;
    rect->setRect(x1, y1, width, hieght);
}

float Rectangle::getperimeter(){
    perimeter=2*(abs(width)+abs(hieght));
  return perimeter;
}


void Rectangle::addShape(){
scene->addItem(rect);
}
