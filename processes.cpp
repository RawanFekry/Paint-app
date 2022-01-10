#include "processes.h"
Processes::Processes(QVector<Shape*>* shapesMemory)
{
    this->shapesMemory = shapesMemory;
}

// adding shapes drawn to a vector (shapesMemory vector)
void Processes::add(Shape* shape)
{
    shapesMemory->push_back(shape);
}

// Function to search any shape using its nae name and return its information.
Shape* Processes::search(QString shapeName)
{
   for (int i=0; i<shapesMemory->size();i++){
       if (shapesMemory->at(i)->getname()==shapeName)
       {
           return shapesMemory->at(i);}
       } return nullptr;


}


// function to sort shapes ascending drawn according to their perimeter
void Processes::  sort_Ascending ()
{

    std:: sort(shapesMemory->begin(), shapesMemory->end(), Check_Asc());
    isAscending = true;

}

// function to sort shapes descending drawn according to their perimeter
void Processes:: sort_Descending ()
{
    std::sort(shapesMemory->begin(), shapesMemory->end(),Check_Des() );
    isAscending = false;
}


QVector<Shape*>* Processes::getMemory()
{
    return shapesMemory;
}


