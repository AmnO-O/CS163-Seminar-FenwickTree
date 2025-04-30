#pragma once

#include <vector>
#include <cstddef>
#include <type_traits>
#include <iostream>

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
