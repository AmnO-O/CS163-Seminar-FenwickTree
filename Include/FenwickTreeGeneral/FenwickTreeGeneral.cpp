#include "FenwickTreeGeneral.h"


// Default constructor
template <typename T>
FenwickTreeGeneral<T>::FenwickTreeGeneral()
	: BIT{}, n{ 0 } {
}

// Constructor with size
template <typename T>
FenwickTreeGeneral<T>::FenwickTreeGeneral(int n)
	: BIT(n + 1, T{}), n{ n } {
}

// Constructor from array
template <typename T>
FenwickTreeGeneral<T>::FenwickTreeGeneral(const std::vector<T>& arr)
	: BIT(arr.size() + 1, T{}), n{ arr.size() } {
	build(arr);
}

// Build tree from array
template <typename T>
void FenwickTreeGeneral<T>::build(const std::vector<T>& arr) {
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
void FenwickTreeGeneral<T>::update(std::size_t index, T value) {
	while (index <= n) {
		BIT[index] += value;
		index += index & -index;
	}
}

// Prefix sum query [1..index]
template <typename T>
T FenwickTreeGeneral<T>::get(std::size_t index) const {
	T sum = T{};
	while (index > 0) {
		sum += BIT[index];
		index -= index & -index;
	}
	return sum;
}

// Range sum query [l..r]
template <typename T>
T FenwickTreeGeneral<T>::range_query(std::size_t l, std::size_t r) const {
	if (l == 0 || l > r) return T{};
	return get(r) - (l > 1 ? get(l - 1) : T{});
}

// Find the k-th smallest element
template <typename T>
T FenwickTreeGeneral<T>::findKth(int k) const {
	T sum = T{};
	int index = 0;
	for (int i = 31 - __builtin_clz(n); i >= 0; --i) {
		int next_index = index + (1 << i);
		if (next_index <= n && sum + BIT[next_index] < k) {
			sum += BIT[next_index];
			index = next_index;
		}
	}
	return index + 1; // Convert to 1-based index
}

// Clear the tree
template <typename T>
void FenwickTreeGeneral<T>::clear() {
	BIT.clear();
	n = 0;
}

// Print internal BIT array
template <typename T>

void FenwickTreeGeneral<T>::print() const {
	std::cout << "Fenwick Tree (BIT): ";
	for (int i = 1; i <= n; ++i) {
		std::cout << BIT[i] << " ";
	}
	std::cout << std::endl;
}

// Get the size of the tree
template <typename T>
int FenwickTreeGeneral<T>::size() const {
	return n;
}

// Least significant bit
template <typename T>
int FenwickTreeGeneral<T>::lsb(int index) const {
	return index & -index;
}

// Print memory usage statistics
template <typename T>
void FenwickTreeGeneral<T>::Memory() const {
	std::cout << "Memory usage: " << sizeof(T) * (n + 1) << " bytes" << std::endl;
}

// Print usage instructions
template <typename T>
void FenwickTreeGeneral<T>::how_to_use() const {
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



