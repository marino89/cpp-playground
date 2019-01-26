#include <iostream>

using namespace std;


void print(const int* const array, size_t size) {
    cout << '[';
    for (size_t i = 0; i < size ; ++i)
        cout << array[i] << " ";  // *(array + i)
    cout << "]" ;
    cout << endl;
}

int* apply_all(const int* const array1, size_t size1, const int* const array2, size_t size2) {
    size_t new_array_size = size1 + size2;
    int* new_array = new int[new_array_size];
    
    int k = 0;
    for (size_t i = 0; i < size1; ++i) {
        for (size_t j = 0; j < size2; ++j) {
            new_array[k] = array1[i] * array2[j]; 
            ++k;
        }
    }
    return new_array;
}


int main() {
    
 int array1[] {1, 2, 3, 4, 5};
 int array2[] {10, 20, 30};
 
 cout << "Array1: ";
 print(array1, 5);
 cout << "Array2: ";
 print(array1, 3);
 
 int* results = apply_all(array1, 5, array2, 3);
 cout << "Result: ";
 print(results, 3*5);
 delete[] results;
 
}