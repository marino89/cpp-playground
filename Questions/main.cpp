#include <stdio.h>
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> extractUniqueElements(const std::vector<T> &vec) {
    std::vector<T> result {vec[0]};
    T previous = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] != previous)
            result.push_back(vec[i]);
        previous = vec[i];
    }
    return result;
}

template <typename T>
void display(const std::vector<T> &vec) {
    std::cout << "[ ";
    for (const auto &v: vec)
        std::cout << v << " ";
    std::cout << "]" << std::endl;
}


template <typename T>
double getAverage(const T* const arr, size_t size) {
    T sum {0};
    for (size_t i = 0; i < size; ++i)
        sum += arr[i];
    double result =  double(sum) / size;
    return result;
} 


int main(int argc, char **argv)
{
	std::vector<int> vec {1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9};
    std::vector<int> result = extractUniqueElements(vec);
    display(result);
    
    double balance[5] = {1000.0, 34.2, 6.75, 34.5, 50.0};
    double avg = getAverage(balance, 5);
    std::cout << "Average = " << avg << std::endl;
    
    return 0;
}
