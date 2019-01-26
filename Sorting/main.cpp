#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class MergeSort {
    // Merge sort algorithm implementation
    // time complexity: O(nlogn)
    // space complexity O(n)

private:
    vector<int> &arr;


    void merge(vector<int> &arr, vector<int> &temp_array,
               int lower_index, int middle_index, int upper_index);
    
    void mergeSrt(vector<int> &arr, vector<int> &temp_array, int lower_index, int upper_index);
    
public:
    MergeSort(vector<int> &data): arr{data} {};
    virtual void sort(); // public method to be called
};


void MergeSort::sort() {
    int size = arr.size();
    std::vector<int> temp_array(size);
    mergeSrt(arr, temp_array, 0, size - 1);
}


void MergeSort::mergeSrt(vector<int> &arr, vector<int> &temp_array, int lower_index, int upper_index) {
    if (lower_index >= upper_index)
        return;
        
    int middle_index = (lower_index + upper_index) / 2;
    // sort left part
    mergeSrt(arr, temp_array, lower_index, middle_index);
    // sort right part
    mergeSrt(arr, temp_array, middle_index + 1, upper_index);
    // merge
    merge(arr, temp_array, lower_index, middle_index, upper_index);
}


void MergeSort::merge(vector<int> &arr, vector<int> &temp_array,
    int lower_index, int middle_index, int upper_index) {
    
    // left half boundaries
    int lower_start = lower_index;
    int lower_stop = middle_index;
    
    // right half boundaries
    int upper_start = middle_index + 1;
    int upper_stop = upper_index;
    
    // temp array position
    int index = lower_index;
    
    // Sort elements coming from both halves
    while (lower_start <= lower_stop && upper_start <= upper_stop) {
        
        if (arr[lower_start] < arr[upper_start]) {
            temp_array[index] = arr[lower_start];
            ++lower_start;
        }
        else {
            temp_array[index] = arr[upper_start];
            ++upper_start;
        }
        ++index;
    }
    
    // sort left half remaining elements
    while (lower_start <= lower_stop) {
        temp_array[index] = arr[lower_start];
        ++lower_start;
        ++index;
    }
    
    // sort right half remaining elements
    while (upper_start <= upper_stop) {
        temp_array[index] = arr[upper_start];
        ++upper_start;
        ++index;
    }
    
    // copy temp array to arr
    for (int i = lower_index ; i <= upper_index; ++i)
        arr[i] = temp_array[i];
}


template <typename T>
void display(const std::vector<T> &vec) {
    std::cout << "[ ";
    for (const auto &v: vec)
        std::cout << v << " ";
    std::cout << "]" << std::endl;
}


int main(int argc, char **argv)
{
    vector<int> arr {7, 4, 3, 8, 2, 10};
    display(arr);
    MergeSort sorter(arr);
    sorter.sort();
    display(arr);

	return 0;
}
