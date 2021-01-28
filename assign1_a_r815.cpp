// File name: a_r815_assignment1.cpp
//
// Author: Aravind Rajadurai
// Date: 2/06/2018
// Assignment Number: 2
// CS 2308, Spring 2018
// Instructor: Patricia Carando
//
//  Created by Aravind Adric on 2/6/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

double computeMean (vector <int>);
int computeMedian (vector <int>);
int searchBinary (int, vector <int>);
int searchLinear (int, vector <int>);
void selectionSort (vector <int>, bool);

int main()
{
    int index,  // initializeing index
        searchValue1,  // initializeing searchvalue1
        searchValue2,  // initializeing searchvalue2
        searchValue3;  // initializeing searchvalue3
    
    bool ascending;
    
    // initialize the random number generator to the 25th Fibonacci number
    const unsigned int seed = 75025;
    const unsigned int moduloValue = 517;
    
    srand(seed);
    
    const int COUNT = 101; //Set the count to 101
    
    vector <int> numbers (COUNT); //initializing COUNT to vertex
    
    for (int i=0; i<COUNT; i++) //Produces random number
    {
        numbers[i] = rand() % moduloValue;
    }
    
    searchValue1 = numbers[0]; //stores the first value
    searchValue2 = numbers[1]; //stores the second value
    searchValue3 = numbers[2]; //stores the third value
    
 //Output
    cout << "Vector of values randomly generated" << endl;
    
    for (int i=0; i<COUNT; i++) //Prints out values generated
    {
        cout << "Value" << i << ": " << numbers[i] << endl;
    }
    
    cout << endl; //Linebreak
    
// Ascending
    cout << "Vector of values sorted (ascending) by selection sort" << endl;
    
    selectionSort(numbers, ascending);
    
    cout << endl; //Linebreak
    
//Linear Sort
    cout << "****Linear Searches****" << endl;
//Searching for 4
    index = searchLinear(4, numbers); //Passing in the values
    if(index == -1) //Prints out the location where the value is found
        cout << "Searching for 4 using linear search" << endl
             << "!!4 not found" << endl;
    else //Prints out if value is not found
    {
        cout << "Searching for 4 using linear search" << endl
             << "Found 4 at location" << " " << index << endl;
    }
//Searching for 510
    index = searchLinear(510, numbers);
    if(index == -1) //Prints out the location where the value is found
        cout << "Searching for 510 using linear search" << endl
             << "!!510 not found" << endl;
    else //Prints out if value is not found
        {
            cout << "Searching for 510 using linear search" << endl
                 << "Found 510 at location" << " " << index << endl;
        }
//Searching for -1
    index = searchLinear(-1, numbers);
    if(index == -1) //Prints out the location where the value is found
        cout << "Searching for -1 using linear search" << endl
             <<"!!-1 not found" << endl;
    else //Prints out if value is not found
        {
            cout << "Searching for -1 using linear search" << endl
              << "Found -1 at location" << " " << index << endl;
        }
//Searching for 1024
    index = searchLinear(1024, numbers);
    if(index == -1) //Prints out the location where the value is found
        cout << "Searching for 1024 using linear search" << endl
             << "!!1024 not found" << endl;
    else //Prints out if value is not found
        {cout << "Searching for 1024 using linear search" << endl
              << "Found 1024 at location" << " " << index << endl;
        }
        
    
    cout << endl; //Linebreak
    
//Binary Search
    cout << "****Binary Searches****" << endl;
//Searching for 4
    index = searchLinear(4, numbers);
    if(index == -1) //Prints out the location where the value is found
        cout << "Searching for 4 using linear search" << endl
             << "!!4 not found" << endl;
    else //Prints out if value is not found
    {
        cout << "Searching for 4 using binary search" << endl
             << "Found 4 at location" << " " << index << endl;
    }
//Searching for 510
    index = searchLinear(510, numbers);
    if(index == -1) //Prints out the location where the value is found
        cout << "Searching for 510 using linear search" << endl
             << "!!510 not found" << endl;
    else //Prints out if value is not found
    {
            cout << "Searching for 510 using binary search" << endl
                 << "Found 510 at location" << " " << index << endl;
    }
//Searching for -1
    index = searchLinear(-1, numbers);
    if(index == -1) //Prints out the location where the value is found
        cout << "Searching for -1 using linear search" << endl
             <<"!!-1 not found" << endl;
    else //Prints out if value is not found
    {
        cout << "Searching for -1 using binary search" << endl
             << "Found -1 at location" << " " << index << endl;
    }
//Searching for 1024
    index = searchLinear(1024, numbers);
    if(index == -1) //Prints out the location where the value is found
        cout << "Searching for 1024 using linear search" << endl
             << "!!1024 not found" << endl;
    else //Prints out if value is not found
    {
        cout << "Searching for 1024 using binary search" << endl
             << "Found 1024 at location" << " " << index << endl;
    }
    
    cout << endl;  //Linebreak
    
//Median
    cout << "Median is: " << computeMedian(numbers) << endl;
    
    cout << endl;  //Linebreak
    
//Mean
    cout << "Mean is: " << computeMean(numbers) << endl;

    return 0;
}

//Mean
double computeMean (vector <int> numbers)
{
    double total = 0, //initialize total
    avg = 0; //initialize
    
    for(int i = 0; i < numbers.size(); i++) //gets the total of all the values
    {
        total += numbers[i]; //adds up the totals
    }
    
    avg = total/numbers.size(); //Calulates the average
    
    return avg; //return average
}

//Median
int computeMedian (vector <int> numbers)
{
    if (numbers.size() == 0) //if there is no data
    {
        return 0;  // Undefined, really.
    }
    else if (numbers.size() == 1)
    {
        return numbers[0];
    }
    else //if data is found, calcualate the median
    {
        sort(numbers.begin(), numbers.end()); //sorting
        if (numbers.size() % 2 == 0) //finding the middle
        {
            return (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2; //returns the middle
        }
        else //find the middle
        {
            return numbers[numbers.size() / 2]; //return the median
        }
    }
}

//Binary Search
int searchBinary (int value, vector <int> numbers)
{
    int first = 0,           // First array element
    last = numbers.size()- 1,       // Last array element
    middle,                // Mid point of search
    position = -1;         // Position of search value
    bool found = false;        // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (numbers[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (numbers[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    }
    return position;
}

//Linear Search
int searchLinear (int value, vector <int> numbers)
{
    int index = 0;      // Used as a subscript to search the vertex
    int position = -1;  // To record the position of search value
    bool found = false; // Flag to indicate if value was found
    
    while (index < numbers.size() && !found)
    {
        if (numbers[index] == value) // If the value is found
        {
            found = true; // Set the flag
            position = index; // Record the value's subscript
        }
        index++; // Go to the next element
    }
    return position; // Return the position, or -1
}

//Selection Sort
void selectionSort (vector <int> numbers, bool ascending)
{
    int minIndex, minValue, temp; //initializing
    
    if(ascending) // In Ascending
    {
        for (int start = 0; start < (numbers.size() - 1); start++) //runs the loop of the values
        {
            minIndex = start; //stored the location starting value
            minValue = numbers[start]; //stores the starting value
        
            for (int index = start + 1; index < numbers.size(); index++) //runs the loop of the values
            {
                if (numbers[index] < minValue) //compares the value
                {
                    minValue = numbers[index]; //stores the value
                    minIndex = index; //stores the index
                }
            }
            temp = numbers[minIndex]; //using temp to store minimum
            numbers[minIndex] = numbers[start]; //storing the start value to minIndex
            numbers[start] = temp; //switches the value held in temp to start
        }
        
        for (int i=0; i<numbers.size(); i++) // Prints the values in ascending
        {
            cout << "Value" << i << ": " << numbers[i] << endl;
        }
        
    }
        else // In Decending Order
        {
            for (int start = 0; start < (numbers.size() - 1); start++)
            {
                minIndex = start; //stored the location starting value
                minValue = numbers[start]; //stores the starting value
                
                for (int index = start + 1; index < numbers.size(); index++) //runs the loop of the values
                {
                    if (numbers[index] > minValue) //compares the value
                    {
                        minValue = numbers[index]; //stores the value
                        minIndex = index; //stores the index
                    }
                }
                temp = numbers[minIndex]; //using temp to store minimum
                numbers[minIndex] = numbers[start]; //storing the start value to minIndex
                numbers[start] = temp; //switches the value held in temp to start
            }
            
            for (int i=0; i<numbers.size(); i++) // Prints the values in decending order
            {
                cout << "Value" << i << ": " << numbers[i] << endl;
            }
        }
}
