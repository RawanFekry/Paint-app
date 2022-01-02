#ifndef PROCESSES_H
#define PROCESSES_H
#include"Shape.h"
#include<QString>
#include<QVector>
#include<QtAlgorithms>
class Processes
{
public:
    Processes();
    QVector<Shape>shapes;
    Shape search(QString shapeName );
    void add(Shape& shape);
    struct  Check_Asc
    {
         bool operator()( const Shape & s1, const Shape& s2 ) const {
            return s1.get_perimeter() < s2.get_perimeter();
        }
    };
    struct  Check_Des
    {
         bool operator()( const Shape & s1, const Shape& s2 ) const {
            return s1.get_perimeter() > s2.get_perimeter();
        }
    };
    QVector<Shape> sort_Ascending (QVector <Shape> shapes);
     QVector<Shape> sort_Descending (QVector <Shape> shapes);


};


#endif // PROCESSES_H
