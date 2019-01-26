#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

class B;  // forward declaration

class A {
private:
    std::shared_ptr<B> b_ptr;
public:
    void setB(std::shared_ptr<B> &b) {
        b_ptr = b;
    }
    A() {cout << "A constructor" << endl;}
    ~A() {cout << "A destructor" << endl;}
};

class B {
private:
    std::weak_ptr<A> a_ptr;  // make weak to break the circular reference
public:
    void setA(std::shared_ptr<A> &a) {
        a_ptr = a;
    }
    B() {cout << "B constructor" << endl;}
    ~B() {cout << "B destructor" << endl;}
};




int main(int argc, char **argv)
{
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->setB(b);
    b->setA(a);
    


	return 0;
}
