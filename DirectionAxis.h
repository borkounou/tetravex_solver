#ifndef _DIRECTIONAXIS_H
#define _DIRECTIONAXIS_H

using namespace std;
// Representer les deux valeurs opposées dans un pion ou piece
class DirectionAxis{
public:
    DirectionAxis();
    DirectionAxis(int negative_val, int positive_val);
    int get(int id);


int negative_val;
int positive_val;
};

#endif
