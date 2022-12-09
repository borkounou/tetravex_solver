
#include "DirectionAxis.h"

DirectionAxis::DirectionAxis(){
    negative_val = 0;
    positive_val = 0;
}
DirectionAxis::DirectionAxis(int nv, int pv){
    negative_val = nv;
    positive_val = pv;
}

int DirectionAxis::get(int id){
    if(id < 0) {
        return negative_val;
        }
    if(id > 0){ 
        return positive_val;
        }

    return -1;
}