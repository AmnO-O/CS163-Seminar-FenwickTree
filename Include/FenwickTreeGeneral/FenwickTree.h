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
class FenwickTree {
    static_assert(std::is_arithmetic_v<T>,
        "FenwickTree requires a numeric type");

private:
    std::vector<T> BIT;    // Internal array storing tree values, 1-based index
    int n;         // Number of elements

public:
    // Constructors
    FenwickTree();
    explicit FenwickTree(int n = 0);
    explicit FenwickTree(const std::vector<T>& arr);

    // Copy & Assignment
    FenwickTree(const FenwickTree& other) = default;
    FenwickTree(FenwickTree&& other) = default;
    FenwickTree& operator=(const FenwickTree& other) = default;
	FenwickTree& operator=(FenwickTree&& other) = default;
	~FenwickTree() = default;

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

/*
* vector <int> a = {1, 2, 3}; 
* FenwickTree<int> ft(a);
*/

// Fenwick Tree for minimum queries
template <typename T>
class FenwickTreeMin {
    static_assert(std::is_arithmetic_v<T>,
        "FenwickTreeMin requires a numeric type");
private:
	std::vector<T> BIT;
	int n;     
public:
    T MAX = 1e9;

	FenwickTreeMin();
	~FenwickTreeMin() = default;
	FenwickTreeMin(const FenwickTreeMin& other) = default;
	FenwickTreeMin(FenwickTreeMin&& other) = default;
	FenwickTreeMin& operator=(const FenwickTreeMin& other) = default;
	FenwickTreeMin& operator=(FenwickTreeMin&& other) = default;
	
	explicit FenwickTreeMin(int n = 0);
	explicit FenwickTreeMin(const std::vector<T>& arr);
	void build(const std::vector<T>& arr);
	void update(std::size_t index, T value);

	T get(std::size_t index) const;

    void clear();
	void print() const;
	int size() const;
	int lsb(int index) const; // Least significant bit
	void Memory() const; // Print usage statistics
	void how_to_use() const; // Print usage instructions
};


template <typename T>
class FenwickTree2D {
	static_assert(std::is_arithmetic_v<T>,
		"FenwickTree2D requires a numeric type");
private:
	std::vector<std::vector<T>> BIT;
	int n, m; 
public:
	FenwickTree2D();
	~FenwickTree2D() = default;
	FenwickTree2D(const FenwickTree2D& other) = default;
	FenwickTree2D(FenwickTree2D&& other) = default;
	FenwickTree2D& operator=(const FenwickTree2D& other) = default;
	FenwickTree2D& operator=(FenwickTree2D&& other) = default;


	explicit FenwickTree2D(int n = 0, int m = 0);
	explicit FenwickTree2D(const std::vector<std::vector<T>>& arr);

	void build(const std::vector<std::vector<T>>& arr);
	void update(int x, int y, T value);
	T get(int x, int y) const;
	T range_query(int x1, int y1, int x2, int y2) const;
	void clear();
	void print() const;
	int size() const;
	int lsb(int index) const; // Least significant bit
	void Memory() const; // Print usage statistics
	void how_to_use() const; // Print usage instructions
};


template <typename T>
class FenwickTreeRangeUpdate {
	static_assert(std::is_arithmetic_v<T>,
		"FenwickTreeRangeUpdate requires a numeric type");
private:
	std::vector<T> BIT1, BIT2;
	int n;
public:
	FenwickTreeRangeUpdate();
	~FenwickTreeRangeUpdate() = default;
	FenwickTreeRangeUpdate(const FenwickTreeRangeUpdate& other) = default;
	FenwickTreeRangeUpdate(FenwickTreeRangeUpdate&& other) = default;
	FenwickTreeRangeUpdate& operator=(const FenwickTreeRangeUpdate& other) = default;
	FenwickTreeRangeUpdate& operator=(FenwickTreeRangeUpdate&& other) = default;
	explicit FenwickTreeRangeUpdate(int n = 0);
	explicit FenwickTreeRangeUpdate(const std::vector<T>& arr);
	void build(const std::vector<T>& arr);
	void update(int l, int r, T value);
	T get(int index) const;
	T range_query(int l, int r) const;
	void clear();
	void print() const;
	int size() const;
	int lsb(int index) const; // Least significant bit
	void Memory() const; // Print usage statistics
	void how_to_use() const; // Print usage instructions
};
