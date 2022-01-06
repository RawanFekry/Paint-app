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
#include <QAction>
#include <QUndoStack>
#include <commands.h>
#include <processes.h>


class newscene : public QGraphicsScene
{
    Q_OBJECT

public:
    newscene(QObject *parent = nullptr , QUndoStack* undoStack = nullptr);

    void selectShape(int shapeNum);
    QVector<Shape*>* shapesMemory;
    Processes* getProcesses();

protected:
     
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void printshapesInfo();

public:
     virtual QColor getLineColor();
     void setLineColor(QColor color);

     virtual QBrush getStyleShape();
     void setStyleShape(QBrush brush);

     virtual int getLineWidth();
     void setLineWidth(int linewidth);

//     virtual QColor getShapeColor();
//     void setShapeColor(QColor color);


private:

    int x1, y1, x2, y2;
    bool pressing = false;
    Shape* shape;
    int selectedShape;
    QUndoStack *undoStack;
    addCommand* addItem;
    QColor linecolor;
    int linewidth;
    QBrush brusher;
//    QColor shapecolor;
    Processes* Do;
    int shapeOrder;


};




#endif // NEWSCENE_H
