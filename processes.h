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

    QVector<Shape*>* shapesMemory;
    bool isAscending;


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

};


#endif // PROCESSES_H
