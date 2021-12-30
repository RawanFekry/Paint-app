#include "circle.h"


circle::circle(int x,int y,QColor color,int linewidth):
    Shape(x,y,color,linewidth)
{
    circ=new QGraphicsEllipseItem (x,y,1,1);
    circ->setPen(pen);
}

void circle::setParemeters(int parameter1, int parameter2){
    if(parameter1>parameter2){
        parameter2=parameter1;
     this->parameter1=parameter1;
    }else if(parameter1<parameter2){
         parameter1=parameter2;
     this->parameter2=parameter2;
    }else
    {
             this->parameter1=parameter1;
    }

    circ->setRect(x,y,parameter1,parameter2);
}

circle::~circle(){
}

float circle::getperimeter(int parameter1,int parameter2){
   parameter1=diameter;
   parameter2=diameter;
  perimeter= M_PI*diameter;

  return perimeter;
}

