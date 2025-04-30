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