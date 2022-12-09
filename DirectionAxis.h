using namespace std;
// Representer les deux valeurs opposées dans un pion ou piece
class DirectionAxis{
private:
    int negative_val;
    int positive_val;
public:
    DirectionAxis();
    DirectionAxis(int negative_val, int positive_val);
    int get(int id);
};

