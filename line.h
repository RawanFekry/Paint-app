#ifndef LINE_H
#define LINE_H
#include<Shape.h>
#include<QGraphicsScene>
#include<QtMath>

class Line : public Shape{

public:
    Line(int x1,int y1,QColor color,QBrush brush,int linewidth, QGraphicsScene* scene);

    ~Line();

    void setParemeters(int x2,int y2)override;
    void setPerimeter()override;
    void addShape() override;
    void deleteShape() override;

    static int lineOrder;
private:

    int length;


};

#endif // LINE_H
