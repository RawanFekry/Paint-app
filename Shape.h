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

    Shape(int x1,int y1,QColor color,QBrush brush,int linewidth, QGraphicsScene* scene);
    Shape(QString name, float perimeter);
    ~Shape();

    virtual void setParemeters(int x2,int y2);
    virtual float getperimeter();
    virtual void addShape();
    virtual void deleteShape();
    void setname(int shapeOrder) ;


    virtual QString getname();
    virtual QString getshapeType();
    void setname(QString name);

    float get_perimeter() const;


protected:

QString name;
float perimeter;
QString shapeType;
int x1,y1;
QPen pen;
QGraphicsScene* scene;

};



#endif // SHAPE_H
