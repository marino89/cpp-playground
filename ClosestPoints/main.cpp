#include <stdio.h>
#include <vector>
#include <iostream>
#include <random>
#include <climits>

double maxSubArraySum(std::vector<double> arr, unsigned int &start, unsigned int &end) {
    double cumsum = arr[0]; 
    double max_sum = arr[0];
    double min_cumsum = std::min(0.0, cumsum);
    
    for (unsigned int i = 1; i < arr.size(); ++i) {
        // update cumsum
        cumsum += arr[i];
        // update max_sum
        if (cumsum - min_cumsum > max_sum) {
            max_sum = cumsum - min_cumsum;
            end = i;
        }
        // update min_cumsum
        if (cumsum < min_cumsum) {
            min_cumsum = cumsum;
            start = i + 1;
        } 
    }
    return max_sum;
}


int maxSubarraySum(int arr[], int n) {
    // recursion base case
    if (n == 1)
        return arr[0];  
        
    // size of the left subarray
    int m = n / 2; 
    // Recursive call for left subarray
    int left_mss = maxSubarraySum(arr, m);
    // Recursive call for right subarray
    int right_mss = maxSubarraySum(arr, n - m);
    
    int ans = std::max(left_mss, right_mss);
    
    // initialize 
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;
    
    // find max sum on the right side
    for (int i = m; i < n; ++i) {
        sum += arr[i];
        right_sum = std::max(right_sum, sum);
    }

    // find max sum on the right side
    sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += arr[i];
        left_sum = std::max(left_sum, sum);
    }
    
    return std::max(ans, left_sum + right_sum);
}


int kadaneAlgo(int arr[], int n) {
    int ans = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sum + arr[i] > 0)
            sum += arr[i];
        else
            sum = 0;
        ans = std::max(ans, sum);
    }
    return ans;
}


double l2Norm(double x, double y) {
    return x * x + y * y;
}


double estimatePi(unsigned int n_simulations) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> uni(0.0, 1.0);
    
    unsigned int count = 0;
    for (size_t i = 0; i < n_simulations; ++i) {
        double x = uni(gen);
        double y = uni(gen);
        if (l2Norm(x, y) <= 1)
            count += 1;
    }
    
    double proportion =  double(count) / double(n_simulations);
    
    return 4.0 * proportion;
}


void testMaxSubArraySum() {
    std::vector<double> A = {1.0, 2.0, -5.0, 4.0, -3.0, 2.0, 6.0, -5.0, -1.0};
    unsigned int i = 0;
    unsigned int j = 0;
    double result = maxSubArraySum(A, i, j);
    std::cout << "Max sum: " <<  result << std::endl;
    std::cout << "start: " << i << ", end: " << j << std::endl;
}


void testMaxSubarray() {
    size_t n = 7;
    int arr[n] = {3, 4, 5, -3, -2, 8, 9};     
    int ans = maxSubarraySum(arr, n);
    std::cout << "MSS = " << ans << std::endl;
}


void testEstimatePi() {
    unsigned int n_simulations = 10000;
    double pi_esimtate = estimatePi(n_simulations);
    std::cout << "#simulations: " << n_simulations << ", pi estimate: " << pi_esimtate << std::endl;

    int n = 7;
    bool is_power_of_2 = (n & (n - 1)) == 0;
    std::cout << "Is " << n << " a power of 2? " << is_power_of_2 << std::endl;
}


std::vector<std::vector<int>> getAllSubsets(const std::vector<int>& set) {
    
    std::vector<std::vector<int>> subset;
    std::vector<int> empty;
    subset.push_back(empty);  // { {} }
    
    for (auto &s: set) {
        // create a copy of current subset and add current element
        std::vector<std::vector<int>> subset_temp = subset;
        for (auto &v: subset_temp)
            v.push_back(s);
        
        // take the union of previous and new subsets
        for (auto &v: subset_temp)
            subset.push_back(v);
    }
    return subset;
}


template <typename T>
void printSubsets(const std::vector<T>& vec) {
    unsigned int count = 0;
    
    std::cout << std::endl;
    for (const auto &v: vec) {
        
        std::cout << "{";
        for (const auto &i: v) {
            std::cout  << i << ", ";
        }
        std::cout << "}" << std::endl;
        count += 1;
    }
    
    std::cout << "Total number of subsets: " << count << std::endl;
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    std::vector<int> vec = {1, 2, 3};
    auto subsets = getAllSubsets(vec);
    printSubsets(subsets);
    
    return 0;

}
