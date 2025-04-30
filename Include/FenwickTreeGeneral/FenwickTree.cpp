#include "FenwickTree.h"

// Default constructor
template <typename T>
FenwickTree<T>::FenwickTree()
    : BIT{}, n{ 0 } {
}

// Constructor with size
template <typename T>
FenwickTree<T>::FenwickTree(int n)
    : BIT(n + 1, T{}), n{ n } {
}

// Constructor from array
template <typename T>
FenwickTree<T>::FenwickTree(const std::vector<T>& arr)
    : BIT(arr.size() + 1, T{}), n{ arr.size() } {
    build(arr);
}

// Build tree from array
template <typename T>
void FenwickTree<T>::build(const std::vector<T>& arr) {
    n = arr.size();
    BIT.assign(n + 1, T{});

    for (int i = 1; i <= n; ++i) {
		int par = i + (i & -i);
		BIT[i] += arr[i - 1]; // arr is 0-based index

		if (par <= n) 
            BIT[par] += BIT[i]; 
    }
}

// Point update
template <typename T>
void FenwickTree<T>::update(std::size_t index, T value) {
    while (index <= n) {
        BIT[index] += value;
        index += index & -index;
    }
}

// Prefix sum query [1..index]
template <typename T>
T FenwickTree<T>::get(std::size_t index) const {
    T sum = T{};
    while (index > 0) {
        sum += BIT[index];
        index -= index & -index;
    }
    return sum;
}

// Range sum query [l..r]
template <typename T>
T FenwickTree<T>::range_query(std::size_t l, std::size_t r) const {
    if (l == 0 || l > r) return T{};
    return get(r) - (l > 1 ? get(l - 1) : T{});
}

template <typename T>
T FenwickTree<T>::findKth(int k) const {
	if (k < 1 || k > n) return T{};
    int pos = 0; 
    int LOG = 1; 
	while ((1 << LOG) <= n) LOG++;
	for (int i = LOG; i >= 0; --i) {
		int next_pos = pos + (1 << i);
		if (next_pos <= n && BIT[next_pos] < k) {
			k -= BIT[next_pos];
			pos = next_pos;
		}
	}
	return pos + 1; // Convert to 1-based index
}

// Clear the tree
template <typename T>
void FenwickTree<T>::clear() {
    BIT.clear();
    n = 0;
}

// Print internal BIT array
template <typename T>
void FenwickTree<T>::print() const {
    std::cout << "FenwickTree internal BIT: ";
    for (std::size_t i = 1; i <= n; ++i) {
        std::cout << BIT[i] << ' ';
    }
    std::cout << std::endl;
}

// Get number of elements
template <typename T>
int FenwickTree<T>::size() const {
    return n;
}

// Least significant bit
template <typename T>
int FenwickTree<T>::lsb(int index) const {
	return index & -index;
}
  
// Print Memory statistics
template <typename T>
void FenwickTree<T>::Memory() const {
	std::cout << "FenwickTree Memory: " << sizeof(T) * (n + 1) / 1024.0 << " KB" << std::endl;
}

// Print usage instructions
template <typename T>
void FenwickTree<T>::how_to_use() const {
	std::cout << std::endl; 

	std::cout << "FenwickTree usage: " << std::endl;
	std::cout << "1. Create an instance: FenwickTree<int> ft;" << std::endl;
	std::cout << "2. Build from array: ft.build({1, 2, 3});" << std::endl;
	std::cout << "3. Update value: ft.update(2, 5);" << std::endl;
	std::cout << "4. Query prefix sum: ft.get(3);" << std::endl;
	std::cout << "5. Query range sum: ft.range_query(1, 3);" << std::endl;
	std::cout << "6. Find k-th smallest element: ft.findKth(2);" << std::endl;
	std::cout << "7. Clear tree: ft.clear();" << std::endl;
	std::cout << "8. Print internal BIT: ft.print();" << std::endl;
	std::cout << "9. Get size: ft.size();" << std::endl;
	std::cout << "10. Get least significant bit: ft.lsb(4);" << std::endl;
	std::cout << "11. Print memory usage: ft.Memory();" << std::endl;
	std::cout << "12. Print usage instructions: ft.how_to_use();" << std::endl;
	std::cout << "13. Copy constructor: FenwickTree<int> ft2 = ft;" << std::endl;
	std::cout << "14. Move constructor: FenwickTree<int> ft3 = std::move(ft);" << std::endl;
	std::cout << "15. Copy assignment: ft2 = ft;" << std::endl;
	std::cout << "16. Move assignment: ft3 = std::move(ft2);" << std::endl;
	std::cout << "17. Destructor: ft.~FenwickTree();" << std::endl;

	std::cout << std::endl;
}


// Fenwick Tree for minimum queries
template <typename T>
FenwickTreeMin<T>::FenwickTreeMin()
	: BIT{}, n{ 0 } {
}

// Constructor with size
template <typename T>
FenwickTreeMin<T>::FenwickTreeMin(int n)
	: BIT(n + 1, MAX), n{ n } {
}

// Constructor from array
template <typename T>
FenwickTreeMin<T>::FenwickTreeMin(const std::vector<T>& arr)
	: BIT(arr.size() + 1, MAX), n{ arr.size() } {
	build(arr);
}

// Build tree from array
template <typename T>
void FenwickTreeMin<T>::build(const std::vector<T>& arr) {
	n = arr.size();
	BIT.assign(n + 1, T{});

	for (int i = 1; i <= n; ++i) {
		int par = i + (i & -i);
		BIT[i] = arr[i - 1]; // arr is 0-based index
		if (par <= n)
			BIT[par] = std::min(BIT[par], BIT[i]);
	}
}

template <typename T>
void FenwickTreeMin<T>::update(std::size_t index, T value) {
	while (index <= n) {
		BIT[index] = std::min(BIT[index], value);
		index += index & -index;
	}
}

// Prefix min query [1..index]
template <typename T>
T FenwickTreeMin<T>::get(std::size_t index) const {
	T min_val = MAX;
	while (index > 0) {
		min_val = std::min(min_val, BIT[index]);
		index -= index & -index;
	}
	return min_val;
}

// Clear the tree
template <typename T>
void FenwickTreeMin<T>::clear() {
	BIT.clear();
	n = 0;
}

// Print internal BIT array
template <typename T>
void FenwickTreeMin<T>::print() const {
	std::cout << "FenwickTreeMin internal BIT: ";
	for (std::size_t i = 1; i <= n; ++i) {
		std::cout << BIT[i] << ' ';
	}
	std::cout << std::endl;
}

// Get number of elements
template <typename T>
int FenwickTreeMin<T>::size() const {
	return n;
}
// Least significant bit
template <typename T>
int FenwickTreeMin<T>::lsb(int index) const {
	return index & -index;
}
// Print Memory statistics
template <typename T>
void FenwickTreeMin<T>::Memory() const {
	std::cout << "FenwickTreeMin Memory: " << sizeof(T) * (n + 1) / 1024.0 << " KB" << std::endl;
}
// Print usage instructions
template <typename T>

void FenwickTreeMin<T>::how_to_use() const {
	std::cout << std::endl;
	std::cout << "FenwickTreeMin usage: " << std::endl;
	std::cout << "1. Create an instance: FenwickTreeMin<int> ft;" << std::endl;
	std::cout << "2. Build from array: ft.build({1, 2, 3});" << std::endl;
	std::cout << "3. Update value: ft.update(2, 5);" << std::endl;
	std::cout << "4. Query prefix min: ft.get(3);" << std::endl;
	std::cout << "5. Clear tree: ft.clear();" << std::endl;
	std::cout << "6. Print internal BIT: ft.print();" << std::endl;
	std::cout << "7. Get size: ft.size();" << std::endl;
	std::cout << "8. Get least significant bit: ft.lsb(4);" << std::endl;
	std::cout << "9. Print memory usage: ft.Memory();" << std::endl;
	std::cout << "10. Print usage instructions: ft.how_to_use();" << std::endl;
	std::cout << std::endl;
}


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


// Fenwick Tree for range updates
template <typename T>
FenwickTreeRangeUpdate<T>::FenwickTreeRangeUpdate()
	: BIT1{}, BIT2{}, n{ 0 } {
}

// Constructor with size
template <typename T>
FenwickTreeRangeUpdate<T>::FenwickTreeRangeUpdate(int n)
	: BIT1(n + 1, T{}), BIT2(n + 1, T{}), n{ n } {
}

// Constructor from array
template <typename T>
FenwickTreeRangeUpdate<T>::FenwickTreeRangeUpdate(const std::vector<T>& arr)
	: BIT1(arr.size() + 1, T{}), BIT2(arr.size() + 1, T{}), n{ arr.size() } {
	build(arr);
}

// Build tree from array
template <typename T>
void FenwickTreeRangeUpdate<T>::build(const std::vector<T>& arr) {
	n = arr.size();
	BIT1.assign(n + 1, T{});
	BIT2.assign(n + 1, T{});
	for (int i = 1; i <= n; ++i) {
		int par = i + (i & -i);
		BIT1[i] += arr[i - 1]; // arr is 0-based index
		if (par <= n)
			BIT1[par] += BIT1[i];
	}
}

// Range update [l..r] += value
template <typename T>
void FenwickTreeRangeUpdate<T>::update(int l, int r, T value) {
	BIT1[l] += value;
	BIT1[r + 1] -= value;
	BIT2[l] += value * (l - 1);
	BIT2[r + 1] -= value * r;
}

// Point query [1..index]
template <typename T>
T FenwickTreeRangeUpdate<T>::get(int index) const {
	T sum = T{};
	while (index > 0) {
		sum += BIT1[index] * index - BIT2[index];
		index -= index & -index;
	}
	return sum;
}

// Range query [l..r]
template <typename T>
T FenwickTreeRangeUpdate<T>::range_query(int l, int r) const {
	if (l == 0 || l > r) return T{};
	return get(r) - (l > 1 ? get(l - 1) : T{});
}

// Clear the tree
template <typename T>
void FenwickTreeRangeUpdate<T>::clear() {
	BIT1.clear();
	BIT2.clear();
	n = 0;
}

// Print internal BIT arrays
template <typename T>
void FenwickTreeRangeUpdate<T>::print() const {
	std::cout << "FenwickTreeRangeUpdate internal BIT1: ";
	for (std::size_t i = 1; i <= n; ++i) {
		std::cout << BIT1[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "FenwickTreeRangeUpdate internal BIT2: ";
	for (std::size_t i = 1; i <= n; ++i) {
		std::cout << BIT2[i] << ' ';
	}
	std::cout << std::endl;
}


// Get number of elements
template <typename T>
int FenwickTreeRangeUpdate<T>::size() const {
	return n;
}

// Least significant bit
template <typename T>
int FenwickTreeRangeUpdate<T>::lsb(int index) const {
	return index & -index;
}

// Print Memory statistics
template <typename T>
void FenwickTreeRangeUpdate<T>::Memory() const {
	std::cout << "FenwickTreeRangeUpdate Memory: " << sizeof(T) * (n + 1) / 1024.0 << " KB" << std::endl;
}

// Print usage instructions
template <typename T>
void FenwickTreeRangeUpdate<T>::how_to_use() const {
	std::cout << std::endl;
	std::cout << "FenwickTreeRangeUpdate usage: " << std::endl;
	std::cout << "1. Create an instance: FenwickTreeRangeUpdate<int> ft;" << std::endl;
	std::cout << "2. Build from array: ft.build({1, 2, 3});" << std::endl;
	std::cout << "3. Update range: ft.update(2, 5, 5);" << std::endl;
	std::cout << "4. Query prefix sum: ft.get(3);" << std::endl;
	std::cout << "5. Query range sum: ft.range_query(1, 3);" << std::endl;
	std::cout << "6. Clear tree: ft.clear();" << std::endl;
	std::cout << "7. Print internal BIT: ft.print();" << std::endl;
	std::cout << "8. Get size: ft.size();" << std::endl;
	std::cout << "9. Get least significant bit: ft.lsb(4);" << std::endl;
	std::cout << "10. Print memory usage: ft.Memory();" << std::endl;
	std::cout << "11. Print usage instructions: ft.how_to_use();" << std::endl;
	std::cout << std::endl;
}




