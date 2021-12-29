#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include <QGraphicsScene>



class Rectangle : public Shape
{
public:

    Rectangle(int x, int y, QColor color, int lineWidth);
    ~Rectangle();

     void setParameters(int width,int hieght)override;


private:
     int width;
     int hieght;






};

#endif // RECTANGLE_H
