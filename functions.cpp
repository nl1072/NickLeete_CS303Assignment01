#include "functions.h"

using namespace std;

//	prints the array
void printArray(int arr[], int length) {
	cout << "[ ";
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}

//	finds the index of a number in the array
int findIdxInArr(int arr[], int num)
{
	if (sizeof(arr) == 0)
		return -1;

	for (int i = 0; i < sizeof(arr); i++) {
		if (arr[i] == num)
			return i;
	}
	cout << "Error: Value not found within array." << endl;
	return -2;
}

//	replaces an index in the array with a specified integer
int replaceAtIdx(int arr[], int idx, int newNum)
{
	if (sizeof(arr) == 0)
		return -1;

	int oldNum = arr[idx];
	arr[idx] = newNum;
	cout << "Replacing value " << oldNum << " at index " << idx << " with value " << newNum << endl;

	return 0;
}

//	As stated in main(), could not get working without some kind of memory heap error.
/*
* int resize(int arr[], int newNum)
* {
* 	if (sizeof(arr) == 0)
* 		return -1;
* 	size_t oldSize = sizeof(arr) / sizeof(arr[0]);
* 	cout << oldSize << endl;
* 	size_t newSize = oldSize + 1;
* 	int* newArr = new int[newSize];
*
* 	memcpy(newArr, arr, sizeof(oldSize));
* 	//for (int i = 0; i < oldSize; i++)
* 	//	newArr[i] = arr[i];
* 	//cout << newNum;
*
* 	newArr[newSize - 1] = newNum;
* 	cout << newArr[newSize - 1] << endl;
* 	//delete[] arr;
* 	arr = newArr;
* 	delete[] newArr;
* 	return 0;
* }
*
* int replaceWithZero(int arr[], int idx)
* {
* 	if (sizeof(arr) == 0)
* 		return -1;
* 	arr[idx] = 0;
* 	return 0;
* }
*
* int deleteidx(int arr[], int idx)
* {
* 	return 0;
* }
*/