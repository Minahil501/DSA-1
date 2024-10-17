#include <iostream>
#include <string>
using namespace std;
template <typename t>
void selectionSort(t arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int smallSub = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[smallSub]) {
				smallSub = j;
			}
		}
		swap(arr[i], arr[smallSub]);
	}
}
template <typename u>
void printArray(u arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	// Test with an integer array of size 5
	int intArray[5] = { 64, 25, 12, 22, 11 };
	cout << "Original integer array: ";
	printArray(intArray, 5);
	selectionSort(intArray, 5);
	cout << "Sorted integer array: ";
	printArray(intArray, 5);

	// Test with a string array of size 4
	string stringArray[4] = { "apple", "orange", "banana", "grape" };
	cout << "\nOriginal string array: ";
	printArray(stringArray, 4);
	selectionSort(stringArray, 4);
	cout << "Sorted string array: ";
	printArray(stringArray, 4);

	return 0;
}
