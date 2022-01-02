#include "processes.h"
Processes::Processes()
{

}
void Processes::add(Shape& shape)
{
    shapes.push_back(shape);
}

Shape Processes::search(QString shapeName)
{
   for (int i=0; i<shapes.size();i++){
       if (shapes.at(i).getname()==shapeName)
       {
           return shapes.at(i);}
       } return Shape("",0.0);


}

QVector<Shape> Processes::  sort_Ascending (QVector <Shape> shapes)
{
      this->shapes=shapes;
    std:: sort(shapes.begin(), shapes.end(), Check_Asc());
            return shapes;
}

QVector<Shape> Processes:: sort_Descending (QVector <Shape> shapes)
{
    this->shapes=shapes;
    std::sort(shapes.begin(), shapes.end(),Check_Des() );
          return shapes;

}
