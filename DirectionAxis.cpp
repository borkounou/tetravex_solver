
#include "DirectionAxis.h"
#define Ie -1
#define NULLVAL 0
// 
int DirectionAxis::get(int id){
    if(id < NULLVAL) {
        return negative_val;
        }
    if(id > NULLVAL){ 
        return positive_val;
        }

    return Ie;
}

DirectionAxis::DirectionAxis(){
    negative_val = NULLVAL;
    positive_val = NULLVAL;
}
DirectionAxis::DirectionAxis(int negate, int posit){
    negative_val = negate;
    positive_val = posit;
}