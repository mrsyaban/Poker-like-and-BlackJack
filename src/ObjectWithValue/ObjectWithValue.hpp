/* 
    Abstract class for Combo and Card 
    Has a pure virtual function for value

    Combo : return double;
    Card  : return int;

*/
/*  */

template <class T>
class ObjectWithValue {
    public:
        virtual T value() = 0;
};