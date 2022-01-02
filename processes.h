#ifndef PROCESSES_H
#define PROCESSES_H
#include"Shape.h"
#include<QString>
#include<QVector>
#include<QtAlgorithms>


class Processes
{
public:
    Processes(QVector<Shape*>* shapesMemory);

    Shape* search(QString shapeName );
    void add(Shape* shape);
    struct  Check_Asc
    {
         bool operator()( const Shape* s1, const Shape* s2 ) const {
            return s1->get_perimeter() < s2->get_perimeter();
        }
    };
    struct  Check_Des
    {
         bool operator()( const Shape* s1, const Shape* s2 ) const {
            return s1->get_perimeter() > s2->get_perimeter();
        }
    };
    void sort_Ascending ();
     void sort_Descending ();

private:
     QVector<Shape*>* shapesMemory;
};


#endif // PROCESSES_H
