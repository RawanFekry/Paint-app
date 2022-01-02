#include "processes.h"

Processes::Processes()
{

}
Shape Processes::search(QString shapeName) {
   for (int i=0; i<shapes.size();i++){
       if (shapes.at(i).getname()==shapeName){
           return shapes.at(i);}
       } return Shape("",0.0);


}
void Processes::add(Shape& shape) {
    shapes.push_back(shape);
}

