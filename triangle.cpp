#include "triangle.h"

Triangle::Triangle(int x1,int y1,QColor color,QBrush brush,int linewidth, QGraphicsScene* scene):
    Shape(x1,y1,color,brush,linewidth, scene)
{
    polygon << QPointF(x1, y1) << QPointF(x1, y1) << QPointF(x1, y1);
    triangle= new QGraphicsPolygonItem(polygon);
    triangle->setPen(pen);
    triangle->setBrush(brush);
    shapeType = "Triangle";
    name=QString("Triangle %1").arg(triangleOrder++);//  The Shapename of the Triangle after drawing the Triangle Shape.
    length = 0;
    setPerimeter();
}


Triangle:: ~Triangle(){

}


//override on SetParemeter function to determine the perimeter of the any Triangle drawn.
void Triangle::setParemeters(int x2, int y2){
    length=pow((pow((x1-x2),2)+pow((y1-y2),2)),0.5);
    polygon.clear();
    polygon << QPointF(x1, y1) << QPointF(x1+.5*length, y2) << QPointF(x1-.5*length, y2);
    triangle->setPolygon(polygon);
    setPerimeter();
}
void Triangle:: setPerimeter(){
    perimeter=3*abs(length);

}


void Triangle::addShape(){
scene->addItem(triangle);
scene->update();
}

void Triangle::deleteShape(){
    scene->removeItem(triangle);
    scene->update();
}
