#include "Shape.h"

Shape::Shape(int x, int y, QColor color, int lineWidth){

    this->x = x;
    this->y = y;
    pen.setColor(color);
    pen.setWidth(lineWidth);

}
Shape::~Shape()
{


}
void Shape::setParameters(int width,int hieght){

}

