#include <stdio.h>
#include <iostream>

using namespace std;

class Shallow {
private:
    int *data;
public:
    void setDataValue(int d) {*data = d;}
    int getDataValue() const {return *data;}
    // constructor
    Shallow(int d);
    // copy constructor
    Shallow(const Shallow &source);
    // destructor
    ~Shallow();
};

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source) 
    : data(source.data) {
        cout << "Copy constructor - shallow copy" << endl;
}

Shallow::~Shallow() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void displayShallow(Shallow s) {
    cout << s.getDataValue() << endl;
}


int main(int argc, char **argv)
{
    Shallow obj1(100);
    displayShallow(obj1);
    
    Shallow obj2(obj1);
    obj2.setDataValue(1000);
    
	return 0;
}
