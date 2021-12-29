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
#include <Rectangle.h>



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

    int x, y, width,hieght;
    bool pressing = false;
    QPointF intial, final;
    QPolygonF polygon;
    QGraphicsPolygonItem* p;
    Shape* shape;

};




#endif // NEWSCENE_H
