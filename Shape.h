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
QPen pen;



    Shape(int x1,int y1,QColor color,QBrush brush,int linewidth, QGraphicsScene* scene);

    ~Shape();

    virtual void setParemeters(int x2,int y2);
    virtual void setPerimeter();
    virtual void addShape();
    virtual void deleteShape();



    virtual QString getname();
    virtual QString getshapeType();
    void setname(QString name);
    float get_perimeter() const;
    void updateInfoTable();



protected:

QString name;   //  The Shape name.
float perimeter;    //  The perimiter of the Shape.
QString shapeType;  //  The type of the Shape.
int x1,y1;  //  The points which we make our drawing with.
QGraphicsScene* scene;  //  The scene pointer which make all the attributes of the Shape Class accessible to the MainWindow.
};



#endif // SHAPE_H
