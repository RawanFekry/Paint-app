#ifndef NEWSCENE_H
#define NEWSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "Shape.h"
#include <QPainter>
#include <QPen>
#include <QColor>
#include "Rectangle.h"
#include "circle.h"
#include "line.h"
#include "triangle.h"
#include <iostream>



class newscene : public QGraphicsScene
{
    Q_OBJECT

  public:
     newscene(QObject *parent = 0);


protected:
     
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:

    int x1, y1, x2, y2;
    bool pressing = false;
    Shape* shape;
    int selectedShape;

};




#endif // NEWSCENE_H
