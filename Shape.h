#ifndef SHAPE_H
#define SHAPE_H
#include <QGraphicsItem>
#include <QPainter>



class Shape
{
public:
    Shape(int x, int y, QColor color, int lineWidth);
    ~Shape();

    virtual void setParameters(int width,int hieght)=0;

    QGraphicsRectItem* rect;
    QGraphicsEllipseItem* circle;
    QGraphicsPolygonItem* traingle;
    QGraphicsLineItem* line;

protected:

    int x, y, linewidth;
    QColor color;
    QPen pen;

};

#endif // SHAPE_H
