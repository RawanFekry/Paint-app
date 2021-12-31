#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<Shape.h>
#include<QGraphicsScene>

class Rectangle:public Shape{

private:
int width, hieght;

public:
    Rectangle(int x1,int y1,QColor color,int linewidth, QGraphicsScene* scene);
    ~Rectangle();

    void setParemeters(int x2,int y2)override;
    float getperimeter()override;
    void addShape() override;

};


#endif // RECTANGLE_H

