#include "processes.h"
Processes::Processes(QVector<Shape*>* shapesMemory)
{
    this->shapesMemory = shapesMemory;
}

void Processes::add(Shape* shape)
{
    shapesMemory->push_back(shape);
}

Shape* Processes::search(QString shapeName)
{     Shape* shape = new Shape(" ",0.0);
   for (int i=0; i<shapesMemory->size();i++){
       if (shapesMemory->at(i)->getname()==shapeName)
       {
           return shapesMemory->at(i);}
       } return shape;


}



void Processes::  sort_Ascending ()
{

    std:: sort(shapesMemory->begin(), shapesMemory->end(), Check_Asc());

}

void Processes:: sort_Descending ()
{

    std::sort(shapesMemory->begin(), shapesMemory->end(),Check_Des() );

}

