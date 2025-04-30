#include "FenwickTree2D.h"


// Fenwick Tree for 2D range queries
template <typename T>
FenwickTree2D<T>::FenwickTree2D()
	: BIT{}, n{ 0 }, m{ 0 } {
}
// Constructor with size
template <typename T>
FenwickTree2D<T>::FenwickTree2D(int n, int m)
	: BIT(n + 1, std::vector<T>(m + 1, T{})), n{ n }, m{ m } {
}

// Constructor from 2D array
template <typename T>
FenwickTree2D<T>::FenwickTree2D(const std::vector<std::vector<T>>& arr)
	: BIT(arr.size() + 1, std::vector<T>(arr[0].size() + 1, T{})), n{ arr.size() }, m{ arr[0].size() } {
	build(arr);
}

// Build tree from 2D array

template <typename T>
void FenwickTree2D<T>::build(const std::vector<std::vector<T>>& arr) {
	n = arr.size();
	m = arr[0].size();
	BIT.assign(n + 1, std::vector<T>(m + 1, T{}));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int par_x = i + (i & -i);
			int par_y = j + (j & -j);
			BIT[i][j] += arr[i - 1][j - 1]; // arr is 0-based index
			if (par_x <= n && par_y <= m)
				BIT[par_x][par_y] += BIT[i][j];
		}
	}
}

// Point update
template <typename T>
void FenwickTree2D<T>::update(int x, int y, T value) {
	while (x <= n) {
		int j = y;
		while (j <= m) {
			BIT[x][j] += value;
			j += j & -j;
		}
		x += x & -x;
	}
}

// Prefix sum query [1..x][1..y]
template <typename T>
T FenwickTree2D<T>::get(int x, int y) const {
	T sum = T{};
	while (x > 0) {
		int j = y;
		while (j > 0) {
			sum += BIT[x][j];
			j -= j & -j;
		}
		x -= x & -x;
	}
	return sum;
}

// Range sum query [x1..x2][y1..y2]
template <typename T>
T FenwickTree2D<T>::range_query(int x1, int y1, int x2, int y2) const {
	if (x1 > x2 || y1 > y2) return T{};
	return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
}

// Clear the tree
template <typename T>
void FenwickTree2D<T>::clear() {
	BIT.clear();
	n = 0;
	m = 0;
}

// Print internal BIT array
template <typename T>
void FenwickTree2D<T>::print() const {
	std::cout << "FenwickTree2D internal BIT: " << std::endl;
	for (std::size_t i = 1; i <= n; ++i) {
		for (std::size_t j = 1; j <= m; ++j) {
			std::cout << BIT[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

// Get number of elements
template <typename T>
int FenwickTree2D<T>::size() const {
	return n * m;
}

// Least significant bit
template <typename T>
int FenwickTree2D<T>::lsb(int index) const {
	return index & -index;
}

// Print Memory statistics
template <typename T>
void FenwickTree2D<T>::Memory() const {
	std::cout << "FenwickTree2D Memory: " << sizeof(T) * (n + 1) * (m + 1) / 1024.0 << " KB" << std::endl;
}

// Print usage instructions
template <typename T>
void FenwickTree2D<T>::how_to_use() const {
	std::cout << std::endl;
	std::cout << "FenwickTree2D usage: " << std::endl;
	std::cout << "1. Create an instance: FenwickTree2D<int> ft;" << std::endl;
	std::cout << "2. Build from 2D array: ft.build({{1, 2}, {3, 4}});" << std::endl;
	std::cout << "3. Update value: ft.update(2, 2, 5);" << std::endl;
	std::cout << "4. Query prefix sum: ft.get(2, 2);" << std::endl;
	std::cout << "5. Query range sum: ft.range_query(1, 1, 2, 2);" << std::endl;
	std::cout << "6. Clear tree: ft.clear();" << std::endl;
	std::cout << "7. Print internal BIT: ft.print();" << std::endl;
	std::cout << "8. Get size: ft.size();" << std::endl;
	std::cout << "9. Get least significant bit: ft.lsb(4);" << std::endl;
	std::cout << "10. Print memory usage: ft.Memory();" << std::endl;
	std::cout << "11. Print usage instructions: ft.how_to_use();" << std::endl;
	std::cout << std::endl;
}