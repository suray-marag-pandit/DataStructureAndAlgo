#include <iostream>
using namespace std;

void merge(int arr[], int const left, int const mid, int const right)
{
	int const sizeLeft = mid - left + 1;
	int const sizeRight = right - mid;

	auto *leftArr = new int[sizeLeft];
    auto *rightArr = new int[sizeRight];

	for (auto i = 0; i < sizeLeft; i++)
		leftArr[i] = arr[left + i];
	for (auto j = 0; j < sizeRight; j++)
		rightArr[j] = arr[mid + 1 + j];

	auto leftIndex = 0, rightIndex = 0;
	int mergedIndex = left;

	while (leftIndex < sizeLeft && rightIndex < sizeRight) {
		if (leftArr[leftIndex] <= rightArr[rightIndex]) {
			arr[mergedIndex] = leftArr[leftIndex];
			leftIndex++;
		} else {
			arr[mergedIndex] = rightArr[rightIndex];
			rightIndex++;
		}
		mergedIndex++;
	}

	while (leftIndex < sizeLeft) {
		arr[mergedIndex] = leftArr[leftIndex];
		leftIndex++;
		mergedIndex++;
	}

	while (rightIndex < sizeRight) {
		arr[mergedIndex] = rightArr[rightIndex];
		rightIndex++;
		mergedIndex++;
	}
	delete[] leftArr;
	delete[] rightArr;
}

void mergeSort(int arr[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arrSize);

	mergeSort(arr, 0, arrSize - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arrSize);
	return 0;
}