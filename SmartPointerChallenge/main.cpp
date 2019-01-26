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
    void run() const { 
        std::cout << "\t\tTest running with data [" << data << "]" << std::endl; 
    }
    
};

auto make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    for (int i= 0; i < num; ++i)
        vec.push_back(std::make_shared<Test>(i));
}

void display(const std::vector<std::shared_ptr<Test>> & vec) {
    for (const auto &v: vec) {
        std::cout << "\tTest(data: " << v->getData() << ")" << std::endl;
        v->run();
    }
}


int main(int argc, char **argv)
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    
	printf("hello world\n");
	return 0;
}
