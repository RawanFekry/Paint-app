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
QGraphicsRectItem* rect;
QGraphicsEllipseItem* circ;
QGraphicsPolygonItem* triangle;
QGraphicsLineItem* line;

    Shape(int x1,int y1,QColor color,int linewidth, QGraphicsScene* scene);
    ~Shape();

    virtual void setParemeters(int x2,int y2);
    virtual float getperimeter();
    virtual void addShape();
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
int x1,y1,linewidth;
QPen pen;
QGraphicsScene* scene;

};



#endif // SHAPE_H
