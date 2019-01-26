#include <stdio.h>
#include <iostream>
#include <vector>


class Shape {
private:    
public:
    virtual void draw() = 0;  // pure virtual method
    virtual void rotate() = 0; // pure virtual method
    virtual ~Shape() {}
};

class OpenShape: public Shape {
public:
    virtual ~OpenShape() {}
};

class ClosedShape: public Shape {
public:
    virtual ~ClosedShape() {}
};

class Line: public OpenShape {
public:
    virtual void draw() override {
        std::cout << "Drawing a line " << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
};


class Square: public ClosedShape {
public:
    virtual void draw() override {
        std::cout << "Drawing a square " << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
};


class Circle: public ClosedShape {
public:
    virtual void draw() override {
        std::cout << "Drawing a circle " << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
};


void screenRefresh(const std::vector<Shape *>& shapes) {
    std::cout << "Refreshing" << std::endl;
    for (const auto p: shapes)
        p->draw();
};



class IPrintable {
  friend std::ostream &operator<<(std::ostream &os, const IPrintable &obj){
      obj.print(os); // call pure virtual method print
      return os;
  }
public:
  virtual void print(std::ostream &os) const = 0;

};

class Dog: public IPrintable {
public:
    virtual void print(std::ostream &os) const override {
        os << "Woof woof";
    }
};

void print(const IPrintable &obj) {
    std::cout << obj << std::endl;
}


int main(int argc, char **argv)
{
    Line l;
    l.draw();
    l.rotate();
	
    Shape *ptr1 = new Square();
    Shape *ptr2 = new Line();
    Shape *ptr3 = new Circle();
    
    std::vector<Shape *> shapes {ptr1, ptr2, ptr3};    
    screenRefresh(shapes);
    
    delete ptr1;
    delete ptr2;
    delete ptr3;
    
    
    Dog *dog = new Dog();
    std::cout << *dog << std::endl;
    print(*dog);
    
    return 0;
}
