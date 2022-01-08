#ifndef CIRCLE_H
#define CIRCLE_H
#include<Shape.h>
#include<QGraphicsScene>
#include<QtMath>
class Circle: public Shape{


private:
int diameter;
public:
    Circle(int x1,int y1,QColor color,QBrush brush,int linewidth, QGraphicsScene* scene);

    ~Circle();

    static int circleOrder;
    protected:
    void setParemeters(int x2,int y2 )override;
    void setPerimeter()override;
    void addShape() override;
    void deleteShape() override;
    QGraphicsEllipseItem* getShape();


};

#endif // CIRCLE_H
