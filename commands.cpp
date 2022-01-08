#include "commands.h"
#include <iostream>

addCommand::addCommand(Shape* shape, Processes* Do)
{
    this->shape = shape;
    this->Do = Do;

}

addCommand::~addCommand()
{

}

void addCommand::undo()
{
    shape->deleteShape();
    Do->shapesMemory->erase(std::find(Do->shapesMemory->begin(),Do->shapesMemory->end(),shape));
}

void addCommand::redo()
{
    shape->addShape();
    Do->add(shape);
    if(Do->isAscending){
    Do->sort_Ascending();
    }
    else{
        Do->sort_Descending();
    }

}

deleteCommand::deleteCommand(Shape* shape, Processes* Do)
{
    this->shape = shape;
    this->Do = Do;

}

deleteCommand::~deleteCommand(){}


void deleteCommand::undo()
{
    shape->addShape();
    Do->add(shape);
    if(Do->isAscending){
    Do->sort_Ascending();
    }
    else{
        Do->sort_Descending();
    }
}

void deleteCommand::redo()
{
    shape->deleteShape();
    Do->getMemory()->erase(std::find(Do->getMemory()->begin(),Do->getMemory()->end(),shape));

}
