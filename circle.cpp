#include "circle.h"


Circle::Circle(int x1,int y1,QColor color,int linewidth, QGraphicsScene* scene):
    Shape(x1 , y1, color, linewidth, scene)
{
    circ= new QGraphicsEllipseItem(x1,y1,1,1);
    circ->setPen(pen);
}

void Circle::setParemeters(int x2,int y2){
    int width = x2 - x1;
    int hieght = y2 - y1;
    if(abs(width)>abs(hieght)){diameter = abs(width);}
    else{diameter = abs(hieght);}
    int width_dirc = diameter;
    int hieght_dirc = diameter;
    if(width < 0){width_dirc = -1 * width_dirc;}
    if(hieght < 0){hieght_dirc = -1 * hieght_dirc;}


    circ->setRect(x1,y1,width_dirc,hieght_dirc);
}

Circle::~Circle(){
}



float Circle::getperimeter(){
  perimeter= M_PI*abs(diameter);

  return perimeter;
}

QGraphicsEllipseItem* Circle::getShape()
{
    return circ;
}

void Circle::addShape(){
scene->addItem(circ);
}
