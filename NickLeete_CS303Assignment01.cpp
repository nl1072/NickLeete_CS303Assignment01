// NickLeete_CS303Assignment01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "functions.h"

int main()
{
    ifstream inFile;
    inFile.open("A1input.txt");
    if (!inFile.is_open()) {
        cout << "Could not open \"A1input.txt\"" << endl;
        return 1;
    }

    int arr[100]{};
    int arrIndx = 0;
    string temp;
    while (!inFile.eof()) {
        inFile >> temp;
        arr[arrIndx] = stoi(temp);
        arrIndx += 1;
    }

    for (int i = 0; i < size(arr); i++)
        cout << arr[i] << " ";

    replaceAtIdx(arr, 4, 101);

    for (int i = 0; i < size(arr); i++)
        cout << arr[i] << " ";

    inFile.close();
    return 0;
}