#ifndef LINE_H
#define LINE_H
#include<Shape.h>
#include<QGraphicsScene>
#include<QtMath>

class Line : public Shape{

public:
    Line(int x,int y,QColor color,int linewidth);
    ~Line();
    int parameter1,parameter2;
    void setParemeters(int parameter1,int parameter2)override;
    float getperimeter(int parameter1,int parameter2)override;

};

#endif // LINE_H
