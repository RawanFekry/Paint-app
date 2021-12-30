#include <Shape.h>

Shape::Shape(int x,int y,QColor color,int linewidth){
    this->x=x;
    this->y=y;
  pen.setColor(color);
  pen.setWidth(linewidth);

}

Shape::~Shape(){

}


void Shape::setParemeters(int parameter1, int parameter2){}
float Shape::getperimeter(int parameter1, int parameter2){}


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
