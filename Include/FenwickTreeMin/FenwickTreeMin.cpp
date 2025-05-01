//#include "FenwickTreeMin.h"
//
//
//// Fenwick Tree for minimum queries
//template <typename T>
//FenwickTreeMin<T>::FenwickTreeMin()
//	: BIT{}, n{ 0 } {
//}
//
//// Constructor with size
//template <typename T>
//FenwickTreeMin<T>::FenwickTreeMin(int n)
//	: BIT(n + 1, MAX), n{ n } {
//}
//
//// Constructor from array
//template <typename T>
//FenwickTreeMin<T>::FenwickTreeMin(const std::vector<T>& arr)
//	: BIT(arr.size() + 1, MAX), n{ arr.size() } {
//	build(arr);
//}
//
//// Build tree from array
//template <typename T>
//void FenwickTreeMin<T>::build(const std::vector<T>& arr) {
//	n = arr.size();
//	BIT.assign(n + 1, T{});
//
//	for (int i = 1; i <= n; ++i) {
//		int par = i + (i & -i);
//		BIT[i] = arr[i - 1]; // arr is 0-based index
//		if (par <= n)
//			BIT[par] = std::min(BIT[par], BIT[i]);
//	}
//}
//
//template <typename T>
//void FenwickTreeMin<T>::update(std::size_t index, T value) {
//	while (index <= n) {
//		BIT[index] = std::min(BIT[index], value);
//		index += index & -index;
//	}
//}
//
//// Prefix min query [1..index]
//template <typename T>
//T FenwickTreeMin<T>::get(std::size_t index) const {
//	T min_val = MAX;
//	while (index > 0) {
//		min_val = std::min(min_val, BIT[index]);
//		index -= index & -index;
//	}
//	return min_val;
//}
//
//// Clear the tree
//template <typename T>
//void FenwickTreeMin<T>::clear() {
//	BIT.clear();
//	n = 0;
//}
//
//// Print internal BIT array
//template <typename T>
//void FenwickTreeMin<T>::print() const {
//	std::cout << "FenwickTreeMin internal BIT: ";
//	for (std::size_t i = 1; i <= n; ++i) {
//		std::cout << BIT[i] << ' ';
//	}
//	std::cout << std::endl;
//}
//
//// Get number of elements
//template <typename T>
//int FenwickTreeMin<T>::size() const {
//	return n;
//}
//// Least significant bit
//template <typename T>
//int FenwickTreeMin<T>::lsb(int index) const {
//	return index & -index;
//}
//// Print Memory statistics
//template <typename T>
//void FenwickTreeMin<T>::Memory() const {
//	std::cout << "FenwickTreeMin Memory: " << sizeof(T) * (n + 1) / 1024.0 << " KB" << std::endl;
//}
//// Print usage instructions
//template <typename T>
//
//void FenwickTreeMin<T>::how_to_use() const {
//	std::cout << std::endl;
//	std::cout << "FenwickTreeMin usage: " << std::endl;
//	std::cout << "1. Create an instance: FenwickTreeMin<int> ft;" << std::endl;
//	std::cout << "2. Build from array: ft.build({1, 2, 3});" << std::endl;
//	std::cout << "3. Update value: ft.update(2, 5);" << std::endl;
//	std::cout << "4. Query prefix min: ft.get(3);" << std::endl;
//	std::cout << "5. Clear tree: ft.clear();" << std::endl;
//	std::cout << "6. Print internal BIT: ft.print();" << std::endl;
//	std::cout << "7. Get size: ft.size();" << std::endl;
//	std::cout << "8. Get least significant bit: ft.lsb(4);" << std::endl;
//	std::cout << "9. Print memory usage: ft.Memory();" << std::endl;
//	std::cout << "10. Print usage instructions: ft.how_to_use();" << std::endl;
//	std::cout << std::endl;
//}
