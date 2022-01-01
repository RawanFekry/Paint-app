#include "commands.h"
#include <iostream>

addCommand::addCommand(Shape* shape)
{
    this->shape = shape;
    
}

addCommand::~addCommand()
{

}

void addCommand::undo()
{
    shape->deleteShape();
    std::cout<<"undo";
}

void addCommand::redo()
{
    shape->addShape();
}
