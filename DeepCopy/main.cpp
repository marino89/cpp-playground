#include <stdio.h>
#include <iostream>

using namespace std;

class Deep {
private:
    int *data;
public:
    void setDataValue(int d) {*data = d;}
    int getDataValue() const {return *data;}
    // constructor
    Deep(int d);
    // copy constructor
    Deep(const Deep &source);
    // destructor
    ~Deep();
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

Deep::Deep(const Deep &source) 
    : Deep(*source.data) {
        cout << "Copy constructor - deep copy" << endl;
}

Deep::~Deep() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void displayShallow(Deep s) {
    cout << s.getDataValue() << endl;
}


int main(int argc, char **argv)
{
    Deep obj1(100);
    displayShallow(obj1);
    
    Deep obj2(obj1);
    obj2.setDataValue(1000);
    
	return 0;
}
