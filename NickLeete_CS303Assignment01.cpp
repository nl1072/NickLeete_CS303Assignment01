// NickLeete_CS303Assignment01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;

int main()
{
    //  get filename from user
    string fileName;
    cout << "Please enter the name of the input file.\n> ";
    cin >> fileName;

    //  read input file
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open()) {
        cout << "Could not open " << fileName << endl;
        return 1;
    }

    //  create array and populate from input file
    int arr[100]{};
    int arrIndx = 0;
    string temp;
    while (!inFile.eof()) {
        inFile >> temp;
        arr[arrIndx] = stoi(temp);
        arrIndx += 1;
    }
    inFile.close();
   
    cout << "\nArray:" << endl;
    printArray(arr, size(arr));
    
    

    //  Loop to handle control of program from console
    string userIn;
    while (true) {
        cout << "Please pick an operation: " << endl;
        cout << " 1 : Print the array\n 2 : Find the index of an item within the array" << endl;
        cout << " 3 : Replace the value at an index with another value" << endl;
        //cout << " 4 : Add an index and value to the end of the array" << endl;
        //cout << " 5 : Remove a value from the array" << endl;
        cout << " Q: Quit the program\n > ";
        
        cin >> userIn;
        cout << "\n" << endl;
        if (userIn == "q" || userIn == "Q") {
            break;
        }
        else if (userIn == "1")
            printArray(arr, size(arr));
        else if (userIn == "2") {
            findIndxLoop:
                cout << "\nEnter an integer to search for, or enter Q to return:\n> ";
                cin >> userIn;
                cout << "\n" << endl;
                if (userIn == "q" || userIn == "Q") {
                    continue;
                }
                try {
                    int usIn = stoi(userIn);
                    int idx = findIdxInArr(arr, usIn);
                    if (idx == -1) {
                        cout << "Error: The array is empty." << endl;
                        continue;
                    }
                    else if (idx == -2) {
                        continue;
                    }
                    cout << "The index of " << usIn << " is " << idx << "." << endl;
                }
                catch (...) {
                    cout << "Please enter a valid integer." << endl;
                    goto findIndxLoop;
                }
        }
        else if (userIn == "3") {
            int replIdx = 0;
            int replVal = 0;
            while (true) {
                cout << "\nEnter an index to replace, or enter Q to return:\n> ";
                cin >> userIn;
                cout << "\n" << endl;
                if (userIn == "q" || userIn == "Q") {
                    break;
                }
                try {
                    replIdx = stoi(userIn);
                    break;
                }
                catch (...) {
                    cout << "Please enter a valid integer." << endl;
                    continue;
                }
            }
            if (userIn == "q" || userIn == "Q") {
                break;
            }
            while (true) {
                cout << "Enter an integer to replace it with:\n> ";
                cin >> userIn;
                cout << "\n" << endl;
                try {
                    replVal = stoi(userIn);
                    break;
                }
                catch (...) {
                    cout << "Please enter a valid integer." << endl;
                    continue;
                }
            }
            int test = replaceAtIdx(arr, replIdx, replVal);
            if (test == -1) {
                cout << "Error: The array is empty." << endl;
            }
        }
        
        //  Could not get working without some kind of memory heap error. Internet was no help.
        //  Dynamic arrays gave me the same issue, as well.
        /*
        else if (userIn == "4") {
            int addVal = 0;
            while (true) {
                cout << "\nEnter an integer to add to the array, or enter Q to return:\n> ";
                cin >> userIn;
                cout << "\n" << endl;
                if (userIn == "q" || userIn == "Q") {
                    break;
                }
                try {
                    addVal = stoi(userIn);
                    break;
                }
                catch (...) {
                    cout << "Please enter a valid integer." << endl;
                    continue;
                }
            }
            size_t newSize = size(arr) + 1;
            int* newArr = new int[newSize] {};
            copy(&arr[0], &arr[newSize - 1], newArr);
            newArr[newSize - 1] = addVal;
            delete[] arr;
            *arr = *newArr;
        }
        else if (userIn == "5") {
            int removeIdx = 0;

            if (size(arr) == 0) {
                cout << "Error: The array is empty." << endl;
            }
            while (true) {
                cout << "\nEnter an index to remove, or enter Q to return:\n> ";
                cin >> userIn;
                cout << "\n" << endl;
                if (userIn == "q" || userIn == "Q") {
                    break;
                }
                try {
                    removeIdx = stoi(userIn);
                    break;
                }
                catch (...) {
                    cout << "Please enter a valid index." << endl;
                    continue;
                }
                if (removeIdx >= size(arr)) {
                    cout << "Error: Invalid index. Please enter a valid index." << endl;
                    continue;
                }
            }
            size_t newSize = size(arr) - 1;
            if (newSize == 0) {
                cout << "Error: New array size cannot be 0." << endl;
                break;
            }
            int* newArr = new int[newSize] {};
            if (removeIdx == size(arr) - 1) {
                copy(&arr[0], &arr[size(arr) - 1], newArr);
            }
            else {
                bool skip = false;
                int temp = 0;
                for (int i = 0; i > newSize; i++) {
                    if (i == removeIdx) {
                        skip == true;
                        temp = i + 1;
                        break;
                    }
                    newArr[i] = arr[i];
                }
                if (skip) {
                    for (int i = temp; i > newSize; i++) {
                        newArr[i - 1] = arr[i];
                    }
                }
            }
            delete[] arr;
            *arr = *newArr;
        }
        */
    }
    return 0;
}