// File Name: assign3_a_r815.cpp
//
// Author: Aravind Rajadurai
// Date: 10/16/2017
// Assignment Number: 3
// CS 2308.256, Fall 2017
// Instructor: Yijuan Lu
//
// The following program takes in the data and allocates it into the memory
// efficiently, so later it is easily searched and called for.

#include<iostream>
#include<iomanip>

using namespace std;

//***********************************************************
// isSorted: checks the values in the array
// arr: the value in the array
// size: the number of values in the array
// returns the true or false depending on if everything is sorted
//***********************************************************
bool isSorted(int *arr, int size)
{
    for(int i = 0; i < size -1; i++)
        if (*(arr + i) > *(arr + i + 1))
            return false;
    return true;
}

//***********************************************************
// chain: converts inches into feet
// totalInches: the value in inches
// feet: points to the number of inches in feet
// inches: points to the remaining inches
// returns the the conversions of feet and inches
//***********************************************************
double chain(int totalInches, int *feet, int *inches)
{
    *feet = totalInches/12;
    *inches = totalInches%12;
    return (*feet)*3.49 + (*inches)*.30;
}

//***********************************************************
// grow: makes a duplicate of the values and stores into a different array
// arr: the value in the array
// growSize: the number of values in the array
// returns the values after it is sorted
//***********************************************************
int *grow(int arr[], int growSize)
{
    int *growArr = new int [growSize*2];

    for(int i = 0; i < growSize*2; i++)
        growArr[i]  = arr[i/2];
    return growArr;
}

//***********************************************************
// duplicateArray: makes duplicates of the values
// arr: the value in the array
// size: the number of values in the array
// returns the values in the array after it makes a copy
//***********************************************************
int *duplicateArray (int *arr, int size) {

   int *newArray;
   if (size <= 0)         //size must be positive
      return NULL;        //NULL is 0, an invalid address

   newArray = new int [size];  //allocate new array

   for (int index = 0; index < size; index++)
      newArray[index] = arr[index];  //copy to new array

   return newArray;
}

//***********************************************************
// subArray: show the value of length
// array: points to the values stored in the array
// start: initates where to start
// length: the number of values needed. size
// returns the values in the array
//***********************************************************
int *subArray (int *array, int start, int length)
{
    int *result = duplicateArray(array+start, length);
    return result;
}

int main()
{
    int feet,
        inches,
        start = 5,
        length = 4,
        totalInches = 53,
        size = 8,
        growSize = 9;

    double chain1;

    int arr1[] = {1,2,3,4,5,6,7,8};
    int arr2[] = {8,7,6,5,4,3,2,1};
    int arr3[] = {1,2,3,5,4,6,7,8};

    int growArr[] = {1,2,3,4,5,6,7,8,9};

    int subArr[] = {1,2,3,4,5,6,7,8,9};

    int *doubledArr;

// Display the results.
    cout << "testing isSorted: " << endl
         << "test data array 1: 1 2 3 4 5 6 7 8" << endl
         << "Expected result: true" << endl
         << "Actual result: " << boolalpha << isSorted(arr1, size) << endl
         << "test data array 2: 8 7 6 5 4 3 2 1" << endl
         << "Expected result: false" << endl
         << "Actual result: " << boolalpha << isSorted(arr2, size) << endl
         << "test data array 3: 1 2 3 5 4 6 7 8" << endl
         << "Expected result: false" << endl
         << "Actual result: " << boolalpha << isSorted(arr3, size) << endl << endl;

    chain1 = chain(totalInches, &feet, &inches);

// Display the results.
    cout  << "testing chain for 53 inches: " << endl
          << "Expected result: 15.46 feet: 4 inches: 5" << endl
          << "Actual results : " << chain1 << " feet: " << feet
          << " inches: " << inches << endl << endl;


    doubledArr = grow(growArr, growSize);

// Display the results.
    cout << "testing grow: " << endl
         << "test data: 1 2 3 4 5 6 7 8 9" << endl
         << "Expected result: 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9" << endl
         << "Actual results: ";

// Display the Actual results.
    for(int i = 0; i < growSize*2; i++)
    {
        cout << doubledArr[i] << " ";
    }

    subArray (subArr,start,length);

// Display the results.
    cout << endl << endl
         << "testing subArray:" << endl
         << "test data: 1 2 3 4 5 6 7 8 9" << endl
         << "start: " << start << " length: " << length << endl
         << "Expected result: 6 7 8 9" << endl
         << "Actual result: ";

// Display the Actual results.
    for(int i = 0; i < length; i++)
    {
        cout << subArr[i] << " ";
    }

    cout << endl;

    return 0;
}
