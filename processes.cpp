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
{
   for (int i=0; i<shapesMemory->size();i++){
       if (shapesMemory->at(i)->getname()==shapeName)
       {
           return shapesMemory->at(i);}
       } return nullptr;


}



void Processes::  sort_Ascending ()
{

    std:: sort(shapesMemory->begin(), shapesMemory->end(), Check_Asc());
    isAscending = true;

}

void Processes:: sort_Descending ()
{

    std::sort(shapesMemory->begin(), shapesMemory->end(),Check_Des() );
    isAscending = false;

}

QVector<Shape*>* Processes::getMemory()
{
    return shapesMemory;
}
