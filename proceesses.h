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




};


#endif // PROCESSES_H
