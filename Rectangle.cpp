#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int x, int y, QColor color, int lineWidth):
    Shape(x, y, color, lineWidth)

{
    rect = new QGraphicsRectItem(x, y, 1, 1);
    rect->setPen(pen);


}

Rectangle::~Rectangle(){

}



void Rectangle::setParameters(int width,int hieght)
{
    this->width = width;
    this->hieght = hieght;
    rect->setRect(x, y, width, hieght);

}
