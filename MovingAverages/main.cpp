#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>
#include <array>

static const size_t N = 100000;

class EWMA {

private:
    double m_halflife;
    double m_alpha;
    double m_span;

    static double halflifeToDecay(double hl) {
        if (hl <= 0)
            throw("hl must be > 0!");
        return 1.0 - std::exp(std::log(0.5) / hl);
    }

public:
    EWMA(double halflife, double alpha, double span)
        : m_halflife(halflife), m_alpha(alpha), m_span(span) {}
    EWMA(double halflife)
        : m_halflife(halflife), m_alpha(halflifeToDecay(halflife)), m_span(0.0) {}

    double getAlpha() const {return m_alpha;}
    
    template <typename T> std::vector<T> calculate(const std::vector<T> &data) const {
        size_t n = data.size();
        if (n < 2)
            throw("Not enough data!");
        
        std::vector<T> ma_values {data.at(0)};
        
        for (size_t i = 1; i < n; ++i) {
            ma_values.push_back(
                (1.0 - m_alpha) * data.at(i - 1) + m_alpha * data.at(i));
        }

        return ma_values;
    }
    
};

template <typename T>
std::vector<T> exponentialMovingAverage(const std::vector<T> &data, double &alpha) {
    size_t n = data.size();
    if (n < 2)
        throw("Not enough data!");
    
    std::vector<T> ma_values {data.at(0)};
    
    for (size_t i = 1; i < n; ++i) {
        ma_values.push_back((1.0 - alpha) * data.at(i - 1) + alpha * data.at(i));
    }

    return ma_values;
}

template <typename T>
void print(const std::vector<T> &values) {
    for (const auto &v : values)
        std::cout << v << " ";
    std::cout << std::endl;
}


template <typename T>
std::array<T, N> exponentialMovingAverage2(const std::vector<T> &data, double &alpha) {
    size_t n = data.size();
    if (n < 2)
        throw("Not enough data!");
    
    std::array<T, N> ma_values {data.at(0)};
    
    for (size_t i = 1; i < n; ++i) {
        ma_values[i] = (1.0 - alpha) * data.at(i - 1) + alpha * data.at(i);
    }

    return ma_values;
}


int main(int argc, char **argv)
{
    // A lot of data
    std::vector<double> data(N, 1.0);
    double ma_decay = 0.6;
    
    // arrays
    auto start = std::chrono::steady_clock::now();
    
    std::array<double, N> result1 = exponentialMovingAverage2(data, ma_decay);
    
    auto end = std::chrono::steady_clock::now();
    auto diff_sec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "array: " << diff_sec.count() << " ms" << std::endl;
    
    // vectors
    auto start2 = std::chrono::steady_clock::now();
    
    std::vector<double> result2 = exponentialMovingAverage(data, ma_decay);
    
    auto end2 = std::chrono::steady_clock::now();
    auto diff_sec2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << "vector: " << diff_sec2.count() << " ms" << std::endl;
    
    
	return 0;
}

