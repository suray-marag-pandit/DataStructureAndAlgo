#include <iostream>
using namespace std;

// Helper function to print array in range [start, end]
void printSubArray(int arr[], int start, int end) {
    cout << "[ ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << "]";
}

// Merge function with visualization
void merge(int arr[], int left, int mid, int right, int depth) {
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    auto *leftArr = new int[sizeLeft];
    auto *rightArr = new int[sizeRight];

    for (int i = 0; i < sizeLeft; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < sizeRight; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Indentation for visualization
    string indent(depth * 4, ' ');

    cout << indent << "Merging (start=" << left
         << ", mid=" << mid
         << ", end=" << right << "):" << endl;

    cout << indent << "  Left : ";
    printSubArray(leftArr, 0, sizeLeft - 1);
    cout << endl;

    cout << indent << "  Right: ";
    printSubArray(rightArr, 0, sizeRight - 1);
    cout << endl;

    int leftIndex = 0, rightIndex = 0;
    int mergedIndex = left;

    // Merge two sorted halves
    while (leftIndex < sizeLeft && rightIndex < sizeRight) {
        if (leftArr[leftIndex] <= rightArr[rightIndex]) {
            arr[mergedIndex++] = leftArr[leftIndex++];
        } else {
            arr[mergedIndex++] = rightArr[rightIndex++];
        }
    }

    // Copy remaining elements
    while (leftIndex < sizeLeft)
        arr[mergedIndex++] = leftArr[leftIndex++];
    while (rightIndex < sizeRight)
        arr[mergedIndex++] = rightArr[rightIndex++];

    cout << indent << "  Result after merge: ";
    printSubArray(arr, left, right);
    cout << endl;

    delete[] leftArr;
    delete[] rightArr;
}

// Merge sort with visualization
void mergeSort(int arr[], int begin, int end, int depth = 0) {
    // Indentation for visualization
    string indent(depth * 4, ' ');

    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;

    cout << indent << "mergeSort called on ";
    printSubArray(arr, begin, end);
    cout << " (start=" << begin << ", mid=" << mid << ", end=" << end << ")" << endl;

    // Recursively sort first half
    mergeSort(arr, begin, mid, depth + 1);

    // Recursively sort second half
    mergeSort(arr, mid + 1, end, depth + 1);

    // Merge the sorted halves
    merge(arr, begin, mid, end, depth);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is\n";
    printArray(arr, arrSize);

    cout << "\n--- Visualization of Merge Sort ---\n\n";
    mergeSort(arr, 0, arrSize - 1);

    cout << "\nSorted array is\n";
    printArray(arr, arrSize);

    return 0;
}