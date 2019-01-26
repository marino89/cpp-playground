#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class Move {
private:
    int *data;
public:
    void setDataValue(int d) {*data = d;}
    int getDataValue () const {return *data;}
    // constructor
    Move(int d);
    // copy constructor
    Move(const Move &source);
    // move constructor
    Move(Move &&source);
    // destructor
    ~Move();
};


Move::Move(int d) {
    data =  new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

Move::Move(const Move &source)
    :Move{*source.data} {
        cout << "Copy constructor - deep copy for:" << endl;
}

Move::Move(Move &&source) 
    :data{source.data} {
        source.data = nullptr;
        cout << "Move constructor - moving resource: " << *data << endl;
}

Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor freeing data for: " << *data << endl;
    }
    else {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
    cout << endl;
}


int main(int argc, char **argv)
{
    vector<Move> vec;
    
    for(size_t i = 0; i < 8 ; ++i)
        vec.push_back(Move{i * 10}); // temporary object == r-value
    
	return 0;
}
