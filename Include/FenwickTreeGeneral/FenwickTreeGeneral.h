#pragma once

#include <vector>
#include <cstddef>
#include <type_traits>
#include <iostream>

/**
 * Fenwick Tree (Binary Indexed Tree) implementation.
 * Supports point updates and prefix sum queries in O(log n) time.
 * Template parameter T must be an arithmetic type.
 */

template <typename T>
class FenwickTreeGeneral{
    static_assert(std::is_arithmetic_v<T>,
        "FenwickTree requires a numeric type");

private:
    std::vector<T> BIT;    // Internal array storing tree values, 1-based index
    int n;         // Number of elements

public:
    // Constructors
    FenwickTreeGeneral();
    explicit FenwickTreeGeneral(int n = 0);
    explicit FenwickTreeGeneral(const std::vector<T>& arr);

    // Copy & Assignment
    FenwickTreeGeneral(const FenwickTreeGeneral& other) = default;
    FenwickTreeGeneral(FenwickTree&& other) = default;
    FenwickTreeGeneral& operator=(const FenwickTreeGeneral& other) = default;
    FenwickTreeGeneral& operator=(FenwickTreeGeneral&& other) = default;
    ~FenwickTreeGeneral() = default;

    // Build tree from array
    void build(const std::vector<T>& arr);

    // Point update: add value at index (1-based)
    void update(std::size_t index, T value);

    // Prefix sum query: sum of [1..index] (1-based)
    T get(std::size_t index) const;
    T range_query(std::size_t l, std::size_t r) const;
    T findKth(int k) const; // Find the k-th smallest element


    // Clear the tree
    void clear();
    void print() const;
    int size() const;
    int lsb(int index) const; // Least significant bit
    void Memory() const; // Print usage statistics
    void how_to_use() const; // Print usage instructions
};