#pragma once

#include <vector>
#include <cstddef>
#include <type_traits>
#include <iostream>
#include <algorithm>

/**
 * Fenwick Tree (Binary Indexed Tree) implementation for minimum queries.
 * Supports point updates and prefix minimum queries in O(log n) time.
 * Template parameter T must be an arithmetic type.
 * MAX is set to 1e9 by default; ensure it is larger than any value in your data.
 */
template <typename T>
class FenwickTreeMin {
    static_assert(std::is_arithmetic_v<T>, "FenwickTreeMin requires a numeric type");

private:
    std::vector<T> BIT;
    int n;
    T MAX = std::numeric_limits<T>::max(); // Large value for initialization
    T inf;

public:
    /** Default constructor: empty tree */
    
    FenwickTreeMin() : n(0), inf(std::numeric_limits<T>::max()) {}

    /** Constructor with size n */
    explicit FenwickTreeMin(int n) : n{ n }, BIT(n + 1, MAX) {
        if (n < 0) {
            throw std::invalid_argument("Size cannot be negative");
        }
    }

    /** Constructor from array: builds tree from vector */
    explicit FenwickTreeMin(const std::vector<T>& arr) : n{ static_cast<int>(arr.size()) }, BIT(arr.size() + 1, MAX) {
        for (size_t i = 0; i < arr.size(); ++i) {
            update(i + 1, arr[i]);
        }
    }

    /** Update value at index with new value, propagates minimum up the tree */
    void update(int index, T value) {
        if (index < 1 || index > n) {
            throw std::out_of_range("Index out of bounds");
        }
        while (index <= n) {
            BIT[index] = std::min(BIT[index], value);
            index += index & -index;
        }
    }

    /** Get minimum value over prefix [1, index] */
    T get(int index) const {
        if (index < 1 || index > n) {
            throw std::out_of_range("Index out of bounds");
        }
        T min_val = MAX;
        while (index > 0) {
            min_val = std::min(min_val, BIT[index]);
            index -= index & -index;
        }
        return min_val;
    }

    /** Clear the tree, resetting to initial state */
    void clear() {
        BIT.assign(1, MAX);
        n = 0;
    }

    /** Print internal BIT array */
    void print() const {
        std::cout << "FenwickTreeMin BIT: ";
        for (int i = 1; i <= n; ++i) {
            std::cout << BIT[i] << " ";
        }
        std::cout << std::endl;
    }

    /** Return number of elements */
    int size() const {
        return n;
    }

    /** Compute least significant bit of index */
    int lsb(int index) const {
        return index & -index;
    }

    /** Print approximate memory usage in bytes */
    void Memory() const {
        std::cout << "Memory usage: " << sizeof(T) * (n + 1) << " bytes" << std::endl;
    }

    /** Print usage instructions */
    void how_to_use() const {
        std::cout << "\nFenwickTreeMin usage:\n";
        std::cout << "1. Create an instance: FenwickTreeMin<int> ft;\n";
        std::cout << "2. Build from array: FenwickTreeMin<int> ft(arr);\n";
        std::cout << "3. Update value: ft.update(2, 5);\n";
        std::cout << "4. Query prefix min: ft.get(3);\n";
        std::cout << "5. Clear tree: ft.clear();\n";
        std::cout << "6. Print internal BIT: ft.print();\n";
        std::cout << "7. Get size: ft.size();\n";
        std::cout << "8. Get least significant bit: ft.lsb(4);\n";
        std::cout << "9. Print memory usage: ft.Memory();\n";
        std::cout << "10. Print usage instructions: ft.how_to_use();\n\n";
    }
};