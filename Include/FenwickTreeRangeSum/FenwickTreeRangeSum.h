#pragma once

#include <vector>
#include <cstddef>
#include <type_traits>
#include <iostream>


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
