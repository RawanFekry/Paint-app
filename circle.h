#ifndef CIRCLE_H
#define CIRCLE_H
#include<Shape.h>
#include<QGraphicsScene>
#include<QtMath>
class circle: public Shape{


private:
int  parameter1,parameter2;
int diameter;
public:
    circle(int x,int y,QColor color,int linewidth);
    ~circle();
    protected:
    void setParemeters(int parameter1,int parameter2 )override;
    float getperimeter(int parameter1,int parameter2)override;
};

#endif // CIRCLE_H
