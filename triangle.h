#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<Shape.h>
#include<QGraphicsScene>
#include<QtMath>
#include<QPolygonF>
class Triangle :public Shape
{
public:

     QPolygonF polygon;
    Triangle(int x,int y,QColor color,int linewidth);
    ~Triangle();
     int parameter1,parameter2;
    void setParemeters(int parameter1,int parameter2)override;
    float getperimeter(int parameter1,int parameter2)override;
};

#endif // TRIANGLE_H
