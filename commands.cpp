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

}

void addCommand::redo()
{
    shape->addShape();
}
