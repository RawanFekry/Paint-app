#ifndef COMMANDS_H
#define COMMANDS_H
#include <QUndoCommand>
//#include "Shape.h"
//#include "Scene.h"
#include "processes.h"



class addCommand: public QUndoCommand{
    
public:
    addCommand(Shape* shape, Processes* Do);
    ~addCommand();
    
    void undo() override;
    void redo() override;
    
private:
    
    Shape* shape;
    Processes* Do;
    
};

class deleteCommand : public QUndoCommand{

public:
    deleteCommand(Shape* shape, Processes* Do);
    ~deleteCommand();

    void undo() override;
    void redo() override;

private:

    Shape* shape;
    Processes* Do;
};

#endif // COMMANDS_H
