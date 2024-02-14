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
    
    cout << "Please pick an operation: " << endl;
    cout << " 1 : Print the array\n 2 : Find the index of an item within the array" << endl;
    cout << " 2 : Replace the value at an index with another value\n 3 : Add an index and value to the end of the array" << endl;
    cout << " 4 : Remove a value from the array\n Q : Quit the program\n> ";

    
    string userIn;
    while (true) {
        cin >> userIn;
        cout << "\n";
        if (userIn == "q" || userIn == "Q") {
            break;
        }
        else if (userIn == "1")
            printArray(arr, size(arr));
        else if (userIn == "2") {
            findIndxLoop:
                cout << "\nEnter an integer to search for:\n> ";
                cin >> userIn;
                try {
                    int usIn = stoi(userIn);
                }
                catch (...) {
                    cout << "\nPlease enter a valid option." << endl;
                    goto findIndxLoop;
                }
        }
    }
    return 0;
}