#include "circle.h"


Circle::Circle(int x1,int y1,QColor color,QBrush brush,int linewidth, QGraphicsScene* scene):
    Shape(x1 , y1, color,brush, linewidth, scene)
{
    circ= new QGraphicsEllipseItem(x1,y1,1,1);
    circ->setPen(pen);
    circ->setBrush(brush);
    shapeType = "Circle";
    name=QString("Circle %1").arg(circleOrder++);//  The Shapename of the circle after drawing the Circle Shape.
    diameter = 0;
    setPerimeter();
}


// override on SetParemeter function to determine the perimeter of the any circle drawn

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
    setPerimeter();
}

Circle::~Circle(){
}



void Circle::setPerimeter(){
  perimeter= M_PI*abs(diameter);


}

QGraphicsEllipseItem* Circle::getShape()
{
    return circ;
}

void Circle::addShape(){
scene->addItem(circ);
scene->update();

}

void Circle::deleteShape()
{
    scene->removeItem(circ);
    scene->update();

}
