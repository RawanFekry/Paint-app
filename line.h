#ifndef LINE_H
#define LINE_H
#include<Shape.h>
#include<QGraphicsScene>
#include<QtMath>

class Line : public Shape{

public:
    Line(int x1,int y1,QColor color,int linewidth, QGraphicsScene* scene);
    ~Line();
    int length;
    void setParemeters(int x2,int y2)override;
    float getperimeter()override;
    void addShape() override;
    QGraphicsLineItem* getShape();
};

#endif // LINE_H
