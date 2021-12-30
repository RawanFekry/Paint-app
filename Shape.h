#ifndef SHAPE_H
#define SHAPE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QString>
#include <QColor>
#include <QPair>

class Shape
{

public:
QGraphicsRectItem*rect;
QGraphicsEllipseItem*circ;
QGraphicsPolygonItem*traingle;
QGraphicsLineItem*line;

    Shape(int x,int y,QColor color,int linewidth);
    ~Shape();

    virtual void setParemeters(int parameter1,int parameter2)=0;
    virtual float getperimeter(int parameter1,int parameter2);
    void setname(QString name);
    QString getname();
    QColor getcolor();
    QString getshapeType();
    int getlinewidth();


protected:

 QString name;
float perimeter;
QColor color;
QString shapeType;
int x,y,linewidth;
QPen pen;

};



#endif // SHAPE_H
