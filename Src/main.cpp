
#include "../Include/FenwickTreeGeneral/FenwickTreeGeneral.h"
#include "../Include/FenwickTree2D/FenwickTree2D.h"
#include "../Include/FenwickTreeRangeSum/FenwickTreeRangeSum.h"
#include "../Include/FenwickTreeMin/FenwickTreeMin.h"

using namespace std;

void processGeneral() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    FenwickTreeGeneral<int> ft(n);

    int choice;
    while (true) {
        cout << "\nFenwick Tree General Operations:" << endl;
        cout << "1. Update value" << endl;
        cout << "2. Query prefix sum" << endl;
        cout << "3. Query range sum" << endl;
        cout << "4. Print tree" << endl;
        cout << "5. Print all prefix sums" << endl;
        cout << "6. Initialize with array" << endl;
        cout << "7. Return to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 7) break;

        switch (choice) {
        case 1: {
            int idx, val;
            
            cout << "Enter index (1-indexed): ";
            cin >> idx;
            
			while (idx < 1 || idx > n) {
				cout << "Invalid index. Please enter a valid index (1-indexed): ";
				cin >> idx;
			}

            cout << "Enter value to add: ";
            cin >> val;
            ft.update(idx, val);
            cout << "Updated successfully!" << endl;
            break;
        }
        case 2: {
            int idx;
            cout << "Enter index (1-indexed): ";
            cin >> idx;

			while (idx < 1 || idx > n) {
				cout << "Invalid index. Please enter a valid index (1-indexed): ";
				cin >> idx;
			}

            cout << "Sum from 1 to " << idx << " is: " << ft.get(idx) << endl;
            break;
        }
        case 3: {
            int from, to;
            cout << "Enter start index (1-indexed): ";
            cin >> from;

			while (from < 1 || from > n) {
				cout << "Invalid index. Please enter a valid start index (1-indexed): ";
				cin >> from;
			}


            cout << "Enter end index (1-indexed): ";
            cin >> to;

			while (to < from || to > n) {
				cout << "Invalid index. Please enter a valid end index (1-indexed): ";
				cin >> to;
			}



            cout << "Sum from " << from << " to " << to << " is: " << ft.range_query(from, to) << endl;
            break;
        }
        case 4:
            ft.print();
            break;
        case 5:
            ft.printAllPrefix();
            break;
        case 6: {
            vector<int> arr(n);
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];

            ft = FenwickTreeGeneral<int>(arr);
            cout << "Tree initialized with array!" << endl;
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

void process2D() {
    cout << "Enter number of rows: ";
    int rows;
    cin >> rows;

    cout << "Enter number of columns: ";
    int cols;
    cin >> cols;

    FenwickTree2D<int> ft(rows, cols);

    int choice;
    while (true) {
        cout << "\nFenwick Tree 2D Operations:" << endl;
        cout << "1. Update value" << endl;
        cout << "2. Query rectangle sum" << endl;
        cout << "3. Print tree" << endl;
        cout << "4. Initialize with 2D matrix" << endl;
        cout << "5. Return to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) break;

        switch (choice) {
        case 1: {
            int row, col, val;
            cout << "Enter row (1-indexed): ";
            cin >> row;

			while (row < 1 || row > rows) {
				cout << "Invalid index. Please enter a valid row (1-indexed): ";
				cin >> row;
			}

            cout << "Enter column (1-indexed): ";
            cin >> col;

			while (col < 1 || col > cols) {
				cout << "Invalid index. Please enter a valid column (1-indexed): ";
				cin >> col;
			}

            cout << "Enter value to add: ";
            cin >> val;
            ft.update(row, col, val);
            cout << "Updated successfully!" << endl;
            cout << endl; 
            break;
        }
        case 2: {
            int r1, c1, r2, c2;
            cout << "Enter top-left row (1-indexed): ";
            cin >> r1;
			while (r1 < 1 || r1 > rows) {
				cout << "Invalid index. Please enter a valid top-left row (1-indexed): ";
				cin >> r1;
			}

            cout << "Enter top-left column (1-indexed): ";
            cin >> c1;
            
			while (c1 < 1 || c1 > cols) {
				cout << "Invalid index. Please enter a valid top-left column (1-indexed): ";
				cin >> c1;
			}
            
            cout << "Enter bottom-right row (1-indexed): ";
            cin >> r2;
            
			while (r2 < r1 || r2 > rows) {
				cout << "Invalid index. Please enter a valid bottom-right row (1-indexed): ";
				cin >> r2;
			}

            
            cout << "Enter bottom-right column (1-indexed): ";
            cin >> c2;
            
			while (c2 < c1 || c2 > cols) {
				cout << "Invalid index. Please enter a valid bottom-right column (1-indexed): ";
				cin >> c2;
			}
            
            cout << "Sum in rectangle is: " << ft.range_query(r1, c1, r2, c2) << endl;
            break;
        }
        case 3:
            if (rows <= 20 && cols <= 20) { // Only print small trees
                ft.print();
            }
            else {
                cout << "Tree is too large to print!" << endl;
            }
            break;
        case 4: {
            vector<vector<int>> matrix(rows, vector<int>(cols));
            cout << "Enter " << rows << "x" << cols << " matrix:" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cin >> matrix[i][j];
                }
            }
            ft.build(matrix);
            cout << "Tree initialized with matrix!" << endl;
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

void processRangeUpdate() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    FenwickTreeRangeUpdate<int> ft(n);

    int choice;
    while (true) {
        cout << "\nFenwick Tree Range Update Operations:" << endl;
        cout << "1. Update range" << endl;
        cout << "2. Query at index" << endl;
        cout << "3. Query range sum" << endl;
        cout << "4. Print trees" << endl;
        cout << "5. Initialize with array" << endl;
        cout << "6. Return to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) break;

        switch (choice) {
        case 1: {
            int from, to, val;
            cout << "Enter start index (1-indexed): ";
            cin >> from;
			while (from < 1 || from > n) {
				cout << "Invalid index. Please enter a valid start index (1-indexed): ";
				cin >> from;
			}

            cout << "Enter end index (1-indexed): ";
            cin >> to;
            
			while (to < from || to > n) {
				cout << "Invalid index. Please enter a valid end index (1-indexed): ";
				cin >> to;
			}
            
            cout << "Enter value to add to the range: ";
            cin >> val;
            ft.update(from, to, val);
            cout << "Range updated successfully!" << endl;
            break;
        }
        case 2: {
            int idx;
            cout << "Enter index (1-indexed): ";
            cin >> idx;
			while (idx < 1 || idx > n) {
				cout << "Invalid index. Please enter a valid index (1-indexed): ";
				cin >> idx;
			}

            cout << "Value at index " << idx << " is: " << ft.get(idx) << endl;
            break;
        }
        case 3: {
            int from, to;
            cout << "Enter start index (1-indexed): ";
            cin >> from;
			while (from < 1 || from > n) {
				cout << "Invalid index. Please enter a valid start index (1-indexed): ";
				cin >> from;
			}

            cout << "Enter end index (1-indexed): ";
            cin >> to;
			while (to < from || to > n) {
				cout << "Invalid index. Please enter a valid end index (1-indexed): ";
				cin >> to;
			}

            cout << "Sum from " << from << " to " << to << " is: " << ft.range_query(from, to) << endl;
            break;
        }
        case 4:
            ft.print();
            break;
        case 5: {
            vector<int> arr(n);
            cout << "Enter " << n << " elements:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            ft.build(arr);
            cout << "Tree initialized with array!" << endl;
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

void processMin() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    FenwickTreeMin<int> ft(n);

    int choice;
    while (true) {
        cout << "\nFenwick Tree Min Operations:" << endl;
        cout << "1. Update value" << endl;
        cout << "2. Query minimum" << endl;
        cout << "3. Print tree" << endl;
        cout << "4. Initialize with array" << endl;
        cout << "5. Return to main menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 7) break;

        switch (choice) {
        case 1: {
            int idx, val;
            cout << "Enter index (1-indexed): ";
            cin >> idx;
			while (idx < 1 || idx > n) {
				cout << "Invalid index. Please enter a valid index (1-indexed): ";
				cin >> idx;
			}

            cout << "Enter value: ";
            cin >> val;
            ft.update(idx, val);
            cout << "Updated successfully!" << endl;
            break;
        }
        case 2: {
            int idx;
            cout << "Enter index (1-indexed): ";
            cin >> idx;
            
            while (idx < 1 || idx > n) {
                cout << "Invalid index. Please enter a valid index (1-indexed): ";
                cin >> idx;
            }

            int result = ft.get(idx);


            if (result == numeric_limits<int>::max()) {
                cout << "Minimum from 1 to " << idx << " is: INF" << endl;
            }
            else {
                cout << "Minimum from 1 to " << idx << " is: " << result << endl;
            }
            break;
        }
        case 3:
            ft.print();
            break;
        case 4: {
            vector<int> arr(n);
            cout << "Enter " << n << " elements:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            ft = FenwickTreeMin<int>(arr);
            cout << "Tree initialized with array!" << endl;
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

int main() {
    int option;
    while (true) {
        cout << "\nChoose the Fenwick Tree implementation you want to test:" << endl;
        cout << "1. Fenwick Tree General" << endl;
        cout << "2. Fenwick Tree 2D" << endl;
        cout << "3. Fenwick Tree Range Update" << endl;
        cout << "4. Fenwick Tree Min" << endl;
        cout << "5. Clear screen" << endl;
        cout << "6. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 6) {
            cout << "Exiting..." << endl;
            return 0;
        }

        while (option < 1 || option > 6) {
            cout << "Invalid option. Please try again. Enter your choice: ";
            cin >> option;
        }

        cout << "You chose option: " << option << endl << endl;
        cout << "loading ----------------------------------------" << endl << endl;

        if (option == 5) {
            system("cls"); // For Windows
            // system("clear"); // Uncomment for Linux/Unix
            continue;
        }

        switch (option) {
        case 1: {
            cout << "Fenwick Tree General" << endl;
            processGeneral();
            break;
        }
        case 2: {
            cout << "Fenwick Tree 2D" << endl;
            process2D();
            break;
        }
        case 3: {
            cout << "Fenwick Tree Range Update" << endl;
            processRangeUpdate();
            break;
        }
        case 4: {
            cout << "Fenwick Tree Min" << endl;
            processMin();
            break;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }

        cout << endl;
        cout << "ending ----------------------------------------" << endl << endl;
    }

    return 0;
}