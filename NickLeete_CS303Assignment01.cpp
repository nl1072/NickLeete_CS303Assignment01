// NickLeete_CS303Assignment01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("A1input.txt");
    if (!inFile.is_open()) {
        cout << "Could not open \"A1input.txt\"" << endl;
        return 1;
    }

    int arr[100];
    int arrIndx = 0;
    string temp;
    while (!inFile.eof()) {
        inFile >> temp;
        arr[arrIndx] = stoi(temp);
        arrIndx += 1;
    }

    for (int i = 0; i < sizeof(arr); i++)
        cout << arr[i] << " ";

    inFile.close();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
