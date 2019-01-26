#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>

class Test {
    
private:
    int data;

public:
    Test(): data{0} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }
    Test(int data): data{data} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }
    int getData() const {return data;}
    ~Test() {
        std::cout << "\tTest destructor (" << data << ")" << std::endl;
    }
};


void myDeleter(Test *ptr){
    std::cout << "\tUsing my custom function deleter" << std::endl;
    delete ptr;
}

int main(int argc, char **argv)
{
//	Test *t1 = new Test{1000};
//    delete t1;
    
    // unique pointer
    std::unique_ptr<Test> t1 {new Test{100}};
    std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
    
    std::unique_ptr<Test> t3;
    t3 = std::move(t1);
    if (!t1)
        std::cout << "t1 is nullptr" << std::endl;
    
    std::vector<std::unique_ptr<Test>> tests;
    tests.push_back(std::make_unique<Test>(100));
    tests.push_back(std::make_unique<Test>(200));
    tests.push_back(std::make_unique<Test>(300));
    tests.push_back(std::make_unique<Test>(400));
    
    for (const auto &t: tests)
        std::cout << t->getData() << std::endl;

    // shared pointers
    std::shared_ptr<Test> shared_test = std::make_shared<Test>(1000);
    std::cout << "Use count: " << shared_test.use_count() << std::endl;
    
    std::shared_ptr<Test> my_test = shared_test;
    std::cout << "Use count: " << my_test.use_count() << std::endl;
    shared_test.reset();
    
    std::cout << "Use count: " << my_test.use_count() << std::endl;
    
    
    std::shared_ptr<Test> first_test = std::make_shared<Test>(1);
    std::shared_ptr<Test> second_test = std::make_shared<Test>(2);
    std::shared_ptr<Test> third_test = std::make_shared<Test>(3);
    
    std::vector<std::shared_ptr<Test>> test_suite;
    test_suite.push_back(first_test);
    test_suite.push_back(second_test);
    test_suite.push_back(third_test);
    
    for (const auto &t: test_suite) {
        std::cout << "Test #" << t->getData() << "-\t";
        std::cout << "Use count: " << t.use_count() << std::endl;
    }

    // using custom deleter
    {
        std::shared_ptr<Test> special_ptr{new Test(100), myDeleter};
    }   
    
    {
        std::shared_ptr<Test> special_ptr2(
            new Test(1000),
            [] (Test *ptr) {
                std::cout << "\tUsing my custom lambda deleter" << std::endl;
                delete ptr;
            }
        );
    }
    
    return 0;
}
