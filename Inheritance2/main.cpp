#include <stdio.h>
#include <iostream>

using namespace std;


class Base {

private:
    int value;
public:
    Base(): value{0} {cout << "Base no-args contructor" << endl;}
    Base(int x): value{x} {cout << "Base (int) overloaded contructor" << endl;}
    Base(const Base &other) 
        : value{other.value} {
        cout << "Base copy constructor" << endl;
    }
    
    ~Base() {cout << "Base destructor"<< endl; }
    
    Base &operator=(const Base &rhs) {
        cout << "Base operator=" << endl;
        if (this == &rhs) 
            return *this;
        value = rhs.value;
        return *this;
    }
    
    std::ostream &operator<<(std::ostream &os) const {
        os << "Base(value: " << value << ")";
        return os;
    }
    
    void printValues() const {
        cout << "value: " << value << endl;
    }
};


class Derived : public Base {    

private:
    int double_value;
public:
    Derived(): Base{}, double_value{0} {
        cout << "Derived no-args constructor called" << endl;
    }
    Derived(int x): Base{x}, double_value {x * 2} {
        cout << "Derived constructor called" << endl;
    }
    Derived(const Derived &other) 
        : Base(other), double_value(other.double_value) {
            cout << "Derived copy constructor" << endl;
    }
    
    ~Derived() {
        cout << "Derived contructor" << endl;
    }
    
    Derived &operator=(const Derived &rhs) {
        cout << "Derived operator=" << endl;
        if (this == &rhs)
            return *this;
        Base::operator=(rhs); // slicing
        double_value = rhs.double_value;
        
        return *this;
    }
    
    void printValues() const {
        Base::printValues();
        cout << "double_value : " << double_value << endl;
    }

};






int main(int argc, char **argv)
{
    Base b {500};
	Derived d {1000};
    Derived dd {d};
    dd = d;
    
    d.printValues();
    return 0;
}
