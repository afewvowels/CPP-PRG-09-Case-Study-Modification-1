//
//  main.cpp
//  CPP-PRG-09-Case-Study-Modification-1
//
//  Created by Keith Smith on 10/30/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Modify Program 9-19 (the United Cause case study program) so it can be used with
//  any set of donations. The program should dynamically allocate the donations array
//  and ask the user to input its values.

#include <iostream>

using namespace std;

int *getArraySize();
int *fillArray(int *);
void copyArrays(int *, int *, int *);
int *arrSelectSort(int *, int *);
void showArray(const int [], int *);
void showArrPtr(int *, int *);

int main()
{
//    const int NUM_DONATIONS = 15;
//
//    int donations[NUM_DONATIONS] = { 5, 100, 5, 25, 10,
//                                     5, 25, 5, 5, 100,
//                                     10, 15, 10, 5, 10 };
//
//    int *arrPtr[NUM_DONATIONS] = { nullptr, nullptr, nullptr, nullptr, nullptr,
//                                   nullptr, nullptr, nullptr, nullptr, nullptr,
//                                   nullptr, nullptr, nullptr, nullptr, nullptr };
    int *NUM_DONATIONS = nullptr;
    
    int *donations = nullptr;
    int *arrPtr = nullptr;
    
    NUM_DONATIONS = getArraySize();
    
    donations = fillArray(NUM_DONATIONS);
    arrPtr = new int[*NUM_DONATIONS];
    
    copyArrays(arrPtr, donations, NUM_DONATIONS);
    
    arrPtr = arrSelectSort(arrPtr, NUM_DONATIONS);
    
    cout << "The donations, sorted in ascending order, are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);
    
    cout << "The donations, in their original order, are: \n";
    showArray(donations, NUM_DONATIONS);
    
    return 0;
}

int *getArraySize()
{
    int *intNumDonations = nullptr;
    
    intNumDonations = new int;
    
    cout << "Please enter how many donations were made: ";
    cin >> *intNumDonations;
    while(!cin || *intNumDonations <= 1 || *intNumDonations >= 100)
    {
        cout << "Enter an array size between 2 and 100: ";
        cin.clear();
        cin.ignore();
        cin >> *intNumDonations;
    }
    
    return intNumDonations;
}

int *fillArray(int *size)
{
    int *intArr = nullptr;
    
    intArr = new int[*size];
    
    for(int i = 0 ; i < *size ; i++)
    {
        cout << "Please enter donation number " << (i + 1) << ": $";
        cin >> *(intArr + i);
        while(!cin || *(intArr + i) <= 0 || *(intArr + i) >= 1000)
        {
            cout << "Please enter a value between $0 and $1,000: $";
            cin.clear();
            cin.ignore();
            cin >> *(intArr + i);
        }
    }
    
    return intArr;
}

void copyArrays(int *arr01, int *arr02, int *size)
{
    for (int i = 0 ; i < *size ; i++)
    {
        arr01[i] = arr02[i];
    }
}

int *arrSelectSort(int *arr, int *size)
{
    int startScan, minIndex;
    int *minElem = nullptr;
    
    for (startScan = 0 ; startScan < (*size - 1) ; startScan++)
    {
        minIndex = startScan;
        minElem = &arr[startScan];
        
        for (int index = startScan + 1 ; index < *size ; index++)
        {
            if(arr[index] < *minElem)
            {
                minElem = &arr[index];
                minIndex = index;
            }
        }
        
        swap(arr[minIndex], arr[startScan]);
    }
    
    
    return arr;
}

void showArray(const int arr[], int *size)
{
    for (int count = 0 ; count < *size ; count++)
    {
        cout << "$" << arr[count] << " ";
    }
    cout << endl;
}

void showArrPtr(int *arr, int *size)
{
    for (int count = 0 ; count < *size ; count++)
    {
        cout << "$" << *(arr + count) << " ";
    }
    cout << endl;
}

void swap(int *intA, int *intB)
{
    int *intTemp = nullptr;
    
    intTemp = intA;
    intA = intB;
    intB = intTemp;
}
