#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<Shape.h>
#include<QGraphicsScene>
#include<QtMath>
#include<QPolygonF>
class Triangle :public Shape
{
public:


    Triangle(int x1,int y1,QColor color,int linewidth, QGraphicsScene* scene);
    ~Triangle();

    void setParemeters(int x2,int y2)override;
    float getperimeter()override;
    void addShape() override;

private:
    QPolygonF polygon;
    int length;
};

#endif // TRIANGLE_H
