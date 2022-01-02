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
     Shape(QString name, float perimeter);
    ~Shape();

    virtual void setParemeters(int x2,int y2);
    virtual float getperimeter();
    virtual void addShape();
    virtual void deleteShape();
    void setname(QString name) ;

    QString getname() const;
    QColor getcolor();
    QString getshapeType();
    int getlinewidth();
     float get_perimeter() const;

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
