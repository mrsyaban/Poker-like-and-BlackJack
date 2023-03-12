/* 
    __ should this be generic or no ? __

    Abstract class for Combo and Card 
    Has a pure virtual function for value

    Combo : return double;
    Card  : return int;

*/
#ifndef _OBJECTWITHVALUE_HPP_
#define _OBJECTWITHVALUE_HPP_

template <class T>
class ObjectWithValue {
    public:
        virtual T value() = 0;
};

#endif