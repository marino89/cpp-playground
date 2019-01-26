#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>


class Base {
public:
    virtual void sayHello() const {
        std::cout << "Hello, I am a Base class object" << std::endl;
    }
    
    virtual ~Base() { 
        std::cout << "Base destructor called" << std::endl;
    }
    
    virtual void sayBye() const {
        std::cout << "Bye from Base class!" <<  std::endl;
    }
    
};

class Derived: public Base {
public:
    virtual void sayHello() const {
        std::cout << "Hello, I am a Derived class object" << std::endl;
    }
    
    virtual ~Derived() { 
        std::cout << "Derived destructor called" << std::endl;
    }
    
    virtual void sayBye() const override {
        std::cout << "Bye from Derived class!" <<  std::endl;
    }

};


void greetings(const Base &obj) {
    std::cout << "Greetings: ";
    obj.sayHello();
}


int main(int argc, char **argv)
{
//    Base b;
//    b.sayHello();
//    
//    Derived d;
//    d.sayHello();
//    
//    greetings(b);
//    greetings(d);
//    
//    // raw pointer
//    Base *ptr = new Derived();
//    ptr->sayHello();
//    
//    // smart pointers
//    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
//    ptr1->sayHello();
    
    // vectors
    Base *ptr2 = new Base();
    Base *ptr3 = new Derived();
    
    std::vector<Base *> vec = {ptr2, ptr3};
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i]->sayHello();
        vec[i]->sayBye();
        greetings(*vec[i]);
        std::cout << std::endl;
    }
    
    for (auto &v: vec)
        delete v;
    
//    delete ptr;
    
    std::cout << std::endl;
	return 0;
}
