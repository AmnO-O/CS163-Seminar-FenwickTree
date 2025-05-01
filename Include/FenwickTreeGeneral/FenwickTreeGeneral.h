#pragma once

#include <vector>
#include <cstddef>
#include <type_traits>
#include <iostream>

template <typename T>
class FenwickTreeGeneral {
    static_assert(std::is_arithmetic_v<T>, "FenwickTree requires a numeric type");

private:
    std::vector<T> BIT;    // Internal array storing tree values, 1-based index
    int n;                 // Number of elements

public:
    // Default constructor: initializes an empty tree
    FenwickTreeGeneral() : n{ 0 }, BIT(1, T{}) {}

    // Constructor with size: creates a tree of given size
    FenwickTreeGeneral(int sz) : n{ sz }, BIT(sz > 0 ? sz + 1 : 1, T{}) {
        if (sz < 0) {
            throw std::invalid_argument("FenwickTree size cannot be negative.");
        }
    }

    // Constructor with vector: builds tree from input array
    FenwickTreeGeneral(const std::vector<T>& arr) : BIT(arr.size() + 1, T{}), n{ (int)arr.size() } {
        build(arr);
    }

    // Build the tree from an array in O(n)
    void build(const std::vector<T>& arr) {
        n = arr.size();
        BIT.assign(n + 1, T{});
        for (int i = 1; i <= n; ++i) {
            BIT[i] += arr[i - 1];
            int par = i + (i & -i);
            if (par <= n) {
                BIT[par] += BIT[i];
            }
        }
    }

    // Update the value at index by adding 'value'
    void update(int index, T value) {
        while (index <= n) {
            BIT[index] += value;
            index += index & -index;
        }
    }

    // Get the prefix sum up to index
    T get(int index) const {
        T sum = T{};
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }

    // Compute the range sum from l to r (1-based indices)
    T range_query(std::size_t l, std::size_t r) const {
        if (l == 0 || l > r) return T{};
        return get(r) - (l > 1 ? get(l - 1) : T{});
    }

    // Find the smallest index where prefix sum is at least k
    T findKth(int k) const {
        T sum = T{};
        int index = 0;
        int LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        for (int i = LOG - 1; i >= 0; --i) {
            int nextIndex = index + (1 << i);
            if (nextIndex <= n && sum + BIT[nextIndex] < k) {
                sum += BIT[nextIndex];
                index = nextIndex;
            }
        }
        if (index == n) return T{};
        return index + 1;
    }

    // Clear the tree, resetting to empty state
    void clear() {
        BIT.assign(1, T{});
        n = 0;
    }

    // Print the internal BIT array for debugging
    void print() const {
        std::cout << "Fenwick Tree (BIT): ";
        for (int i = 1; i <= n; ++i) {
            std::cout << BIT[i] << " ";
        }
        std::cout << std::endl;
    }

    // Return the number of elements
    int size() const {
        return n;
    }

    // Compute the least significant bit of an index
    int lsb(int index) const {
        return index & -index;
    }

    // Print memory usage in bytes
    void Memory() const {
        std::cout << "Memory usage: " << sizeof(T) * (n + 1) << " bytes" << std::endl;
    }

    // Print usage instructions
    void how_to_use() const {
        std::cout << "\nFenwickTree usage:\n";
        std::cout << "1. Create an instance: FenwickTreeGeneral<int> ft;\n";
        std::cout << "2. Build from array: ft.build({1, 2, 3});\n";
        std::cout << "3. Update value: ft.update(2, 5);\n";
        std::cout << "4. Query prefix sum: ft.get(3);\n";
        std::cout << "5. Query range sum: ft.range_query(1, 3);\n";
        std::cout << "6. Find k-th smallest index: ft.findKth(2);\n";
        std::cout << "7. Clear tree: ft.clear();\n";
        std::cout << "8. Print internal BIT: ft.print();\n";
        std::cout << "9. Get size: ft.size();\n";
        std::cout << "10. Get least significant bit: ft.lsb(4);\n";
        std::cout << "11. Print memory usage: ft.Memory();\n";
        std::cout << "12. Print usage instructions: ft.how_to_use();\n\n";
    }

    void printAllPrefix() const {
        std::cout << "Prefix sums: ";
        for (int i = 1; i <= n; i++) {
            std::cout << get(i) << " ";
        }
        std::cout << std::endl;
    }
};