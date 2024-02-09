#include "functions.h"

using namespace std;

void printArray(int arr[]) {
	cout << "[ ";
	for (int i = 0; i < sizeof(arr); i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}

int findIdxInArr(int arr[], int num)
{
	if (sizeof(arr) == 0)
		return -1;

	for (int i = 0; i < sizeof(arr); i++) {
		if (arr[i] == num)
			return i;
	}
	return -2;
}

int replaceAtIdx(int arr[], int idx, int newNum)
{
	if (sizeof(arr) == 0)
		return -1;

	int oldNum = arr[idx];
	arr[idx] = newNum;
	cout << "Replacing value " << oldNum << " at index " << idx << " with value " << newNum << endl;

	return 0;
}

int resize(int arr[])
{
	
	return 0;
}

int resizeAndAddToEnd(int arr[], int newNum)
{
	return 0;
}

int replaceWithZero(int arr[], int idx)
{
	if (sizeof(arr) == 0)
		return -1;
	arr[idx] = 0;
	return 0;
}

int deleteidx(int arr[], int idx)
{
	return 0;
}
