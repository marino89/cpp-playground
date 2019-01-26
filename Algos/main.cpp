#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <list>

template <typename T>
void printSquares(T &x) {
    std::cout << x * x << " ";
}

void usingForEach() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    // with a function
    std::for_each(vec.begin(), vec.end(), printSquares<int>);
    // with lambdas
    std::cout << "\nUsing lambdas" << std::endl;
    std::for_each(vec.begin(), vec.end(),
                  [] (int x) {std::cout << x * x * x << " "; });
}


class Person {
private:
    std::string m_name;
    int m_age;
public:
    Person() = default;
    Person(std::string name, int age)
        : m_name(name), m_age(age) {}
    ~Person() {}
    
    bool operator<(const Person &rhs) const {
        return this->m_age < rhs.m_age;
    }
    bool operator==(const Person &rhs) const {
        return (this->m_age == rhs.m_age && this->m_name == rhs.m_name);
    }
};

bool isAnagram(std::string &word1, std::string &word2) { 
    
    
}



int main(int argc, char **argv)
{
    std::list<Person> players {
        Person("Joe", 25),
        Person("Carl", 27),
        Person("Amanda", 23)
    };
    Person target {"Carl", 27};
    auto loc = std::find(std::cbegin(players), std::cend(players), target);
    if (loc != players.end())
        std::cout << "Found!" << std::endl;
    else
        std::cout << "Could not find that player" << std::endl;

    // count
    std::string word {"Mississipi"};
    int occurences = std::count(word.begin(), word.end(), 's');
    std::cout << "s: " << occurences  << std::endl;
            
    // cout if
    std::vector<int> numbers { 1, 1, 2, 3, 5, 7, 36, 3, 2};
    int odd_cout = std::count_if(numbers.begin(), numbers.end(),
                                 [] (int i) { return i % 2 != 0; });
    std::cout << odd_cout  << " odd numbers" << std::endl;
    int large_numbers = std::count_if(numbers.begin(), numbers.end(),
                                      [] (int &i){ return i >= 10; });
    std::cout << large_numbers << " large numbers" << std::endl;
    
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    std::cout << "After transform: " << word << std::endl;
	return 0;
}
