#pragma once

#include <vector>
#include <cstddef>
#include <type_traits>
#include <iostream>

template <typename T>
class FenwickTree2D {
    static_assert(std::is_arithmetic_v<T>, "FenwickTree2D requires a numeric type");

private:
    std::vector<std::vector<T>> BIT;
    int n, m;

public:
    // Default constructor: initializes an empty tree
    FenwickTree2D() : n{ 0 }, m{ 0 }, BIT(1, std::vector<T>(1, T{})) {}

    // Constructor with size: creates a tree of given size
    explicit FenwickTree2D(int n, int m) : n{ n }, m{ m }, BIT(n + 1, std::vector<T>(m + 1, T{})) {
        if (n < 0 || m < 0) {
            throw std::invalid_argument("Dimensions cannot be negative");
        }
    }

    // Constructor with vector: builds tree from input 2D array
    explicit FenwickTree2D(const std::vector<std::vector<T>>& arr) : n{ arr.size() }, m{ arr[0].size() }, BIT(arr.size() + 1, std::vector<T>(arr[0].size() + 1, T{})) {
        build(arr);
    }

    // Build tree from 2D array
    void build(const std::vector<std::vector<T>>& arr) {
        n = arr.size();
        m = arr[0].size();
        BIT.assign(n + 1, std::vector<T>(m + 1, T{}));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                update(i, j, arr[i - 1][j - 1]);
            }
        }
    }

    // Update the value at (x, y) by adding 'value'
    void update(int x, int y, T value) {
        if (x < 1 || x > n || y < 1 || y > m) {
            throw std::out_of_range("Index out of bounds");
        }
        int i = x;
        while (i <= n) {
            int j = y;
            while (j <= m) {
                BIT[i][j] += value;
                j += j & -j;
            }
            i += i & -i;
        }
    }

    // Get the prefix sum up to (x, y)
    T get(int x, int y) const {
        if (x < 1 || x > n || y < 1 || y > m) {
            throw std::out_of_range("Index out of bounds");
        }
        T sum = T{};
        int i = x;
        while (i > 0) {
            int j = y;
            while (j > 0) {
                sum += BIT[i][j];
                j -= j & -j;
            }
            i -= i & -i;
        }
        return sum;
    }

    // Compute the range sum from (x1, y1) to (x2, y2)
    T range_query(int x1, int y1, int x2, int y2) const {
        if (x1 > x2 || y1 > y2 || x1 < 1 || x2 > n || y1 < 1 || y2 > m) {
            return T{};
        }
        return get(x2, y2) - (x1 > 1 ? get(x1 - 1, y2) : T{}) - (y1 > 1 ? get(x2, y1 - 1) : T{}) + (x1 > 1 && y1 > 1 ? get(x1 - 1, y1 - 1) : T{});
    }

    // Clear the tree, resetting to empty state
    void clear() {
        BIT.assign(1, std::vector<T>(1, T{}));
        n = 0;
        m = 0;
    }

    // Print the internal BIT array for debugging
    void print() const {
        std::cout << "FenwickTree2D BIT:\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cout << BIT[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Return the total number of elements
    int size() const {
        return n * m;
    }

    // Compute the least significant bit of an index
    int lsb(int index) const {
        return index & -index;
    }

    // Print memory usage in bytes
    void Memory() const {
        std::cout << "Memory usage: " << (sizeof(T) * (n + 1) * (m + 1)) << " bytes" << std::endl;
    }

    // Print usage instructions
    void how_to_use() const {
        std::cout << "\nFenwickTree2D usage:\n";
        std::cout << "1. Create an instance: FenwickTree2D<int> ft;\n";
        std::cout << "2. Build from 2D array: FenwickTree2D<int> ft(arr);\n";
        std::cout << "3. Update value: ft.update(2, 2, 5);\n";
        std::cout << "4. Query prefix sum: ft.get(2, 2);\n";
        std::cout << "5. Query range sum: ft.range_query(1, 1, 2, 2);\n";
        std::cout << "6. Clear tree: ft.clear();\n";
        std::cout << "7. Print internal BIT: ft.print();\n";
        std::cout << "8. Get size: ft.size();\n";
        std::cout << "9. Get least significant bit: ft.lsb(4);\n";
        std::cout << "10. Print memory usage: ft.Memory();\n";
        std::cout << "11. Print usage instructions: ft.how_to_use();\n\n";
    }
};