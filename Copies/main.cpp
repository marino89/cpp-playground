#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

class Node {

friend std::ostream &operator<<(std::ostream &os, const Node &node) {
    os << "Node(" << node.m_name << ", " << *node.m_data << ")" << std::endl;
    return os;
}
    
private:
    std::string m_name;
    int *m_data;

public:
    Node(std::string name, int data): m_name{name} {
        m_data = new int;
        *m_data = data;
    };
    Node(int data): Node("", data) {};
    // copy constructor (deep copy)
    // This will create a new int pointer which will store the value of the source pointer
    Node(const Node &source): Node(source.m_name, *source.m_data) {
        std::cout << "Calling copy constructor -- Deep copy" << std::endl;
    }
    
    // Move constructor
    Node(Node &&source): m_name{source.m_name}, m_data{source.m_data} {
        std::cout << "Calling move constructor" << std::endl;
        source.m_data = nullptr;  // null the source data pointer out
    }
    
    ~Node() {
        std::cout << "Calling destructor" << std::endl;
        delete m_data;
    }
    
    int getData() const {
        return *m_data;
    }
    
    void setData(int data) {
        *m_data = data;
    }
    
    bool operator<(const Node& rhs) {
        return (this->m_data < rhs.m_data);
    }
    
    bool operator=(const Node& rhs) {
        return (this->m_data == rhs.m_data);
    }

};

template <typename T>
void display(const std::vector<T>& vec){
    std::cout << std::endl;
    for (const auto &v: vec)
        std::cout << v << " ";
    std::cout << std::endl;
}



int main(int argc, char **argv)
{
	Node empty_node{13};
    Node node{"first", 15};
    
    std::cout << node << std::endl;
    std::cout << "Comparison: " << (empty_node < node) << std::endl;
    
    std::cout << "Creating vector of Nodes" << std::endl;
    std::vector<Node> vec;
    for (size_t i = 0; i < 10; ++i) {
        vec.push_back(Node("node" + std::to_string(i) , i));
        vec.emplace_back("node" + std::to_string(i) , i * 10);
    }
    
    display(vec);
    
    return 0;
}
