
#include "DirectionAxis.h"



int DirectionAxis::get(int id){
    if(id < 0) {
        return negative_val;
        }
    if(id > 0){ 
        return positive_val;
        }

    return -1;
}

DirectionAxis::DirectionAxis(){
    negative_val = 0;
    positive_val = 0;
}
DirectionAxis::DirectionAxis(int negate, int posit){
    negative_val = negate;
    positive_val = posit;
}