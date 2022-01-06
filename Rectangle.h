#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<Shape.h>
#include<QGraphicsScene>

class Rectangle:public Shape{

private:
int width, hieght;

public:
    Rectangle(int x1,int y1,QColor color,QBrush brush,int linewidth, QGraphicsScene* scene);
    Rectangle(QString name,float perimeter);
    ~Rectangle();

    void setParemeters(int x2,int y2)override;
    float getperimeter()override;
    void addShape() override;
    void deleteShape() override;

};


#endif // RECTANGLE_H

