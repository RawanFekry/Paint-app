#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<Shape.h>
#include<QGraphicsScene>

class Rectangle:public Shape{

private:
int parameter1,parameter2;    //parameter1=width        parameter2 =hieght

public:
    Rectangle(int x,int y,QColor color,int linewidth);
    ~Rectangle();
    void setParemeters(int parameter1,int parameter2)override;
    float getperimeter(int parameter1,int parameter2)override;

};


#endif // RECTANGLE_H

