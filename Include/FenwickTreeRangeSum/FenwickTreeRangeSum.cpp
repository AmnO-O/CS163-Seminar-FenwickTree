//#include "FenwickTreeRangeSum.h"
//
//// Fenwick Tree for range updates
//template <typename T>
//FenwickTreeRangeUpdate<T>::FenwickTreeRangeUpdate()
//	: BIT1{}, BIT2{}, n{ 0 } {
//}
//
//// Constructor with size
//template <typename T>
//FenwickTreeRangeUpdate<T>::FenwickTreeRangeUpdate(int n)
//	: BIT1(n + 1, T{}), BIT2(n + 1, T{}), n{ n } {
//}
//
//// Constructor from array
//template <typename T>
//FenwickTreeRangeUpdate<T>::FenwickTreeRangeUpdate(const std::vector<T>& arr)
//	: BIT1(arr.size() + 1, T{}), BIT2(arr.size() + 1, T{}), n{ arr.size() } {
//	build(arr);
//}
//
//// Build tree from array
//template <typename T>
//void FenwickTreeRangeUpdate<T>::build(const std::vector<T>& arr) {
//	n = arr.size();
//	BIT1.assign(n + 1, T{});
//	BIT2.assign(n + 1, T{});
//	for (int i = 1; i <= n; ++i) {
//		int par = i + (i & -i);
//		BIT1[i] += arr[i - 1]; // arr is 0-based index
//		if (par <= n)
//			BIT1[par] += BIT1[i];
//	}
//}
//
//// Range update [l..r] += value
//template <typename T>
//void FenwickTreeRangeUpdate<T>::update(int l, int r, T value) {
//	BIT1[l] += value;
//	BIT1[r + 1] -= value;
//	BIT2[l] += value * (l - 1);
//	BIT2[r + 1] -= value * r;
//}
//
//// Point query [1..index]
//template <typename T>
//T FenwickTreeRangeUpdate<T>::get(int index) const {
//	T sum = T{};
//	while (index > 0) {
//		sum += BIT1[index] * index - BIT2[index];
//		index -= index & -index;
//	}
//	return sum;
//}
//
//// Range query [l..r]
//template <typename T>
//T FenwickTreeRangeUpdate<T>::range_query(int l, int r) const {
//	if (l == 0 || l > r) return T{};
//	return get(r) - (l > 1 ? get(l - 1) : T{});
//}
//
//// Clear the tree
//template <typename T>
//void FenwickTreeRangeUpdate<T>::clear() {
//	BIT1.clear();
//	BIT2.clear();
//	n = 0;
//}
//
//// Print internal BIT arrays
//template <typename T>
//void FenwickTreeRangeUpdate<T>::print() const {
//	std::cout << "FenwickTreeRangeUpdate internal BIT1: ";
//	for (std::size_t i = 1; i <= n; ++i) {
//		std::cout << BIT1[i] << ' ';
//	}
//	std::cout << std::endl;
//	std::cout << "FenwickTreeRangeUpdate internal BIT2: ";
//	for (std::size_t i = 1; i <= n; ++i) {
//		std::cout << BIT2[i] << ' ';
//	}
//	std::cout << std::endl;
//}
//
//
//// Get number of elements
//template <typename T>
//int FenwickTreeRangeUpdate<T>::size() const {
//	return n;
//}
//
//// Least significant bit
//template <typename T>
//int FenwickTreeRangeUpdate<T>::lsb(int index) const {
//	return index & -index;
//}
//
//// Print Memory statistics
//template <typename T>
//void FenwickTreeRangeUpdate<T>::Memory() const {
//	std::cout << "FenwickTreeRangeUpdate Memory: " << sizeof(T) * (n + 1) / 1024.0 << " KB" << std::endl;
//}
//
//// Print usage instructions
//template <typename T>
//void FenwickTreeRangeUpdate<T>::how_to_use() const {
//	std::cout << std::endl;
//	std::cout << "FenwickTreeRangeUpdate usage: " << std::endl;
//	std::cout << "1. Create an instance: FenwickTreeRangeUpdate<int> ft;" << std::endl;
//	std::cout << "2. Build from array: ft.build({1, 2, 3});" << std::endl;
//	std::cout << "3. Update range: ft.update(2, 5, 5);" << std::endl;
//	std::cout << "4. Query prefix sum: ft.get(3);" << std::endl;
//	std::cout << "5. Query range sum: ft.range_query(1, 3);" << std::endl;
//	std::cout << "6. Clear tree: ft.clear();" << std::endl;
//	std::cout << "7. Print internal BIT: ft.print();" << std::endl;
//	std::cout << "8. Get size: ft.size();" << std::endl;
//	std::cout << "9. Get least significant bit: ft.lsb(4);" << std::endl;
//	std::cout << "10. Print memory usage: ft.Memory();" << std::endl;
//	std::cout << "11. Print usage instructions: ft.how_to_use();" << std::endl;
//	std::cout << std::endl;
//}