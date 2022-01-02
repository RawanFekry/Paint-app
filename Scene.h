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
protected:
     
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void printshapesInfo();



private:

    int x1, y1, x2, y2;
    bool pressing = false;
    Shape* shape;
    int selectedShape;
    QUndoStack *undoStack;
    addCommand* addItem;
    Processes* Do;

};




#endif // NEWSCENE_H
