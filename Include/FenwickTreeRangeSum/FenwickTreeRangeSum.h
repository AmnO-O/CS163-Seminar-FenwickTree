#pragma once

#include <vector>
#include <cstddef>
#include <type_traits>
#include <iostream>

template <typename T>
class FenwickTreeRangeUpdate {
    static_assert(std::is_arithmetic_v<T>, "FenwickTreeRangeUpdate requires a numeric type");

private:
    std::vector<T> BIT1, BIT2; // Two Fenwick Trees for range updates
    int n;                     // Number of elements

    // Helper function to update BIT1
    void update_BIT1(int index, T value) {
        while (index <= n) {
            BIT1[index] += value;
            index += index & -index;
        }
    }

    // Helper function to update BIT2
    void update_BIT2(int index, T value) {
        while (index <= n) {
            BIT2[index] += value;
            index += index & -index;
        }
    }

    // Helper function to get prefix sum from BIT1 and BIT2
    T get_prefix_sum(int index) const {
        T sum = T{};
        int original_index = index;
        while (index > 0) {
            sum += BIT1[index] * original_index - BIT2[index];
            index -= index & -index;
        }
        return sum;
    }

public:
    // Default constructor: initializes an empty tree
    FenwickTreeRangeUpdate() : n{ 0 }, BIT1(1, T{}), BIT2(1, T{}) {}

    // Constructor with size: creates a tree of given size
    explicit FenwickTreeRangeUpdate(int n) : n{ n }, BIT1(n + 1, T{}), BIT2(n + 1, T{}) {
        if (n < 0) {
            throw std::invalid_argument("FenwickTreeRangeUpdate size cannot be negative.");
        }
    }

    // Constructor with vector: builds tree from input array
    explicit FenwickTreeRangeUpdate(const std::vector<T>& arr) : n{ arr.size() }, BIT1(arr.size() + 1, T{}), BIT2(arr.size() + 1, T{}) {
        build(arr);
    }

    // Build the tree from an array in O(n)
    void build(const std::vector<T>& arr) {
        n = arr.size();
        BIT1.assign(n + 1, T{});
        BIT2.assign(n + 1, T{});
        for (int i = 1; i <= n; ++i) {
            update(i, i, arr[i - 1]);
        }
    }

    // Update the range [l..r] by adding 'value'
    void update(int l, int r, T value) {
        if (l > r || l < 1 || r > n) {
            throw std::out_of_range("Invalid range for update");
        }
        update_BIT1(l, value);
        update_BIT1(r + 1, -value);
        update_BIT2(l, value * (l - 1));
        update_BIT2(r + 1, -value * r);
    }

    // Get the value at a specific index
    T get(int index) const {
        if (index < 1 || index > n) {
            throw std::out_of_range("Index out of bounds");
        }
        return range_query(index, index);
    }

    // Compute the range sum from l to r (1-based indices)
    T range_query(int l, int r) const {
        if (l > r || l < 1 || r > n) {
            throw std::out_of_range("Invalid range for query");
        }
        return get_prefix_sum(r) - (l > 1 ? get_prefix_sum(l - 1) : T{});
    }

    // Clear the tree, resetting to empty state
    void clear() {
        BIT1.assign(1, T{});
        BIT2.assign(1, T{});
        n = 0;
    }

    // Print the internal BIT arrays for debugging
    void print() const {
        std::cout << "FenwickTreeRangeUpdate BIT1: ";
        for (int i = 1; i <= n; ++i) {
            std::cout << BIT1[i] << " ";
        }
        std::cout << "\nFenwickTreeRangeUpdate BIT2: ";
        for (int i = 1; i <= n; ++i) {
            std::cout << BIT2[i] << " ";
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
        std::cout << "Memory usage: " << (sizeof(T) * 2 * (n + 1)) << " bytes" << std::endl;
    }

    // Print usage instructions
    void how_to_use() const {
        std::cout << "\nFenwickTreeRangeUpdate usage:\n";
        std::cout << "1. Create an instance: FenwickTreeRangeUpdate<int> ft;\n";
        std::cout << "2. Build from array: ft.build({1, 2, 3});\n";
        std::cout << "3. Update range: ft.update(2, 3, 5);\n";
        std::cout << "4. Query point: ft.get(3);\n";
        std::cout << "5. Query range sum: ft.range_query(1, 3);\n";
        std::cout << "6. Clear tree: ft.clear();\n";
        std::cout << "7. Print internal BIT: ft.print();\n";
        std::cout << "8. Get size: ft.size();\n";
        std::cout << "9. Get least significant bit: ft.lsb(4);\n";
        std::cout << "10. Print memory usage: ft.Memory();\n";
        std::cout << "11. Print usage instructions: ft.how_to_use();\n\n";
    }
};