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
    QVector<Shape*>* getMemory();
    void sort_Ascending();
    void sort_Descending();

    QVector<Shape*>* shapesMemory;
    bool isAscending;


    // here perimeter of  shape is compared with the previous  shape in the vector and if the its perimeter is bigger replace  the 2 shapes
    struct  Check_Asc
    {
         bool operator()( const Shape* s1, const Shape* s2 ) const {
            return s1->get_perimeter() < s2->get_perimeter();
        }
    };

    // here perimeter of  shape is compared with the previous  shape in the vector and if the its perimeter is smaller replace  the 2 shapes
    struct  Check_Des
    {
         bool operator()( const Shape* s1, const Shape* s2 ) const {
            return s1->get_perimeter() > s2->get_perimeter();
        }
    };

};


#endif // PROCESSES_H
