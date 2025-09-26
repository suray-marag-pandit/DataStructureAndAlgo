#include <iostream>
#include <vector>
using namespace std;









// ----------------------------------------------------
// Function to check if array is sorted (ascending order)
// You need to implement this like a LeetCode problem.
// ----------------------------------------------------
bool isSorted(const vector<int>& arr) {
    // TODO: Write your logic here
    // Return true if sorted, false otherwise



















    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false; // Found a descending pair
        }
    }
    return true;
}

// ----------------------------------------------------
// Utility to print array
// ----------------------------------------------------
void printArray(const vector<int>& arr) {
    cout << "[ ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "]";
}

// ----------------------------------------------------
// Main function for testing
// ----------------------------------------------------
int main() {
    // Sample test arrays
    vector<int> test1 = {1, 2, 3, 4, 5};      // Sorted
    vector<int> test2 = {5, 4, 3, 2, 1};      // Not sorted
    vector<int> test3 = {1, 2, 2, 3, 4, 5};   // Sorted with duplicates
    vector<int> test4 = {1};                   // Single element

    // Vector of test cases
    vector<vector<int>> testCases = {test1, test2, test3, test4};

    // Testing
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ": ";
        printArray(testCases[i]);
        cout << " -> ";

        bool result = isSorted(testCases[i]);
        cout << (result ? "Sorted ✅" : "Not Sorted ❌") << endl;
    }

    return 0;
}
