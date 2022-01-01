#ifndef COMMANDS_H
#define COMMANDS_H
#include <QUndoCommand>
#include "Shape.h"



class addCommand: public QUndoCommand{
    
public:
    addCommand(Shape* shape);
    ~addCommand();
    
    void undo() override;
    void redo() override;
    
private:
    
    Shape* shape;
    
};

#endif // COMMANDS_H
