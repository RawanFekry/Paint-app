
#include<Rectangle.h>

Rectangle::Rectangle(int x1,int y1,QColor color,QBrush brush,int linewidth, QGraphicsScene* scene ):
    Shape(x1 ,y1 , color,brush, linewidth, scene){

    rect=new QGraphicsRectItem(x1,y1,1,1);
    rect->setPen(pen);
    rect->setBrush(brush);
    shapeType = "Rectangle";
    name=QString("Rectangle %1").arg(rectOrder++);//  The Shapename of the Rectangle after drawing the Rectangle Shape.
    width = 0;
    hieght = 0;
    setPerimeter();
}


Rectangle::~Rectangle(){
}

//override on SetParemeter function to determine the perimeter of the any Rectangle drawn.
void Rectangle::setParemeters(int x2, int y2){
    width = x2 - x1;
    hieght = y2 - y1;
    rect->setRect(x1, y1, width, hieght);
    setPerimeter();
}

void Rectangle::setPerimeter(){
    perimeter=int(2*(abs(width)+abs(hieght)));

}


void Rectangle::addShape(){
scene->addItem(rect);
scene->update();

}

void Rectangle::deleteShape()
{
    scene->removeItem(rect);
    scene->update();
}
