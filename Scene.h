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
#include <QTableWidget>
#include <QHeaderView>


class newscene : public QGraphicsScene
{
    Q_OBJECT

public:
    newscene(QObject *parent = nullptr , QUndoStack* undoStack = nullptr);

    void selectShape(int shapeNum);
    QVector<Shape*>* shapesMemory; //  The vector which we store all the drawn shapes within.
    Processes* getProcesses();

    void UpdateTable();

    QColor getLineColor();
    void setLineColor(QColor color);



    int getLineWidth();
    void setLineWidth(int linewidth);



    void setInfoTable(QTableWidget *table);

    void setBrush(QBrush* brush);


protected:
     
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;


private:

    int x1, y1, x2, y2;
    bool pressing = false;
    Shape* shape;
    int selectedShape;
    QUndoStack *undoStack;
    addCommand* addItem;
    QColor linecolor;
    int linewidth;
    QBrush* brusher;
    QColor shapecolor;
    Processes* Do;
    int shapeOrder;
    QTableWidget* table;


};




#endif // NEWSCENE_H
