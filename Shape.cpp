#include <Shape.h>

Shape::Shape(int x1,int y1,QColor color,int linewidth, QGraphicsScene* scene){
    this->x1 = x1;
    this->y1 = y1;
    this->scene = scene;
  pen.setColor(color);
  pen.setWidth(linewidth);

}

Shape::~Shape(){

}


void Shape::setParemeters(int x2, int y2){}
float Shape::getperimeter(){}


void Shape::setname(QString name){
   this->name=name;
}

QString Shape::getname(){
    return name;
}

QColor Shape:: getcolor(){
    return this->color;
}

QString Shape:: getshapeType(){
    return this->shapeType;
}

int Shape:: getlinewidth(){
    return this->linewidth;
}

void Shape::addShape()
{

}

void Shape::deleteShape()
{

}
