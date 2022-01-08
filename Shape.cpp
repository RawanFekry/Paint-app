#include <Shape.h>

Shape::Shape(int x1,int y1,QColor color,QBrush brush,int linewidth, QGraphicsScene* scene)
{
    this->x1 = x1;
    this->y1 = y1;
    this->scene = scene;
    pen.setColor(color);
    pen.setWidth(linewidth);

}



Shape::~Shape(){

}


void Shape::setParemeters(int x2, int y2){}


void Shape::setPerimeter()
{
}

void Shape::setname(QString name)
{
    this->name = name;
}


QString Shape::getname(){
    return name;
}



QString Shape:: getshapeType(){
    return this->shapeType;
}



void Shape::addShape()
{

}

void Shape::deleteShape()
{

}

float Shape:: get_perimeter()const
{
    return perimeter;
}

