// File Name: assign2_a_r815.cpp
//
// Author: Aravind Rajadurai
// Date: 10/01/2017
// Assignment Number: 2
// CS 2308.256, Fall 2017
// Instructor: Yijuan Lu
//
// The following program takes in the data from an output file and stores it
// efficiently, so later it is easily searched and called for.

#include<iostream>
#include<iomanip>
#include<fstream>
#define MAX_DEVICES 100

using namespace std;

// Constants for menu choices
const int DISPLAY = 1,
          LOOKUP_SKU_CHOICE = 2,
          LOOKUP_NAME_CHOICE = 3,
          QUIT_CHOICE = 4;

// The Structure
struct Inventory
{
    string name;
    int sku;
    int quantity;
    double price;
};

// This program displays a menu and asks the user to make a
// selection. A do-while loop repeats the program until the
// user selects item 4 from the menu.
int getChoice()
{
    int choice;

    // Display the menu.
    cout << "Manage Inventory Menu" << endl
         << "1. Display inventory sorted by sku" << endl
         << "2. Lookup a product by sku" << endl
         << "3. Lookup a product by name" << endl
         << "4. Quit the Program" << endl << endl
         << "Enter your choice: ";
     cin >> choice;

    // Validate the menu selection.
    while (choice < DISPLAY || choice > QUIT_CHOICE)
      {
         cout << "Please enter a valid menu choice: ";
         cin >> choice;
      }

    return choice;
}

// Definition of function bubbleSort
// This function performs an ascending order bubble sort on
// array. size is the number of elements in the array.
void skuSort(Inventory devices[], int size)
{
    bool swap;
    int temp;

    do
    {
        swap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (devices[count].sku > devices[count + 1].sku)
            {
                temp = devices[count].sku;
                devices[count].sku = devices[count + 1].sku;
                devices[count + 1].sku = temp;
                swap = true;
            }
        }
    } while (swap);

}

// The binarySearch function performs a binary search on an
// integer array. array, which has a maximum of size elements,
// is searched for the number stored in value. If the number is
// found, its array subscript is returned. Otherwise, -1 is
// returned indicating the value was not in the array.
void skuSearch(Inventory devices[], int size)
{
    skuSort(devices, size);

    int first = 0,             // First array element
        last = size - 1,       // Last array element
        middle,                // Mid point of search
        position = -1,         // Position of search value
        value;
    bool found = false;        // Flag

    cout << "Enter sku of product to find: " << endl;
    cin >> value;


    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (devices[middle].sku == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (devices[middle].sku > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    }

    if(position == -1)
        cout << "ERROR: PRODUCT NOT FOUND!" << endl << endl;
    else
        cout << devices[position].name << " " << devices[position].sku << " "
            << devices[position].quantity << " " << devices[position].price
            << endl << endl;
}

// The searchList function performs a linear search on an
// integer array. The array list, which has a maximum of numElems
// elements, is searched for the number stored in value. If the
// number is found, its array subscript is returned. Otherwise,
// -1 is returned indicating the value was not in the array.
void nameSearch(Inventory devices[], int size)
{
    string value;
    int index = -1;       // Used as a subscript to search array
    bool found = false;  // Flag to indicate if the value was found

    cout << "Enter product name of product to find: " << endl;
    cin >> value;

    while (index < size && !found)
    {
    index++;                   // Go to the next element

    if (devices[index].name == value)  // If the value is found
        found = true;           // Set the flag
    }

    if(!found)
    cout << "ERROR: PRODUCT NOT FOUND!" << endl << endl;
    else
    cout << devices[index].name << " " << devices[index].sku << " "
         << devices[index].quantity << " " << devices[index].price
         << endl << endl;

}

// This program displays a menu and asks the user to make a
// selection. A do-while loop repeats the program until the
// user selects item 4 from the menu.
void display(Inventory devices[], int size)
{
    skuSort(devices, size);

    for(int x = 0; x < size; x++)
    {
        cout << setw(4) << devices[x].sku << setw(6)
             << devices[x].quantity << setw(9) << devices[x].price
             << " " << devices[x].name << endl << endl;
    }
}




int main()
{
    int choice,
        size = 0;

    ifstream inputFile;

    Inventory devices[MAX_DEVICES];

   // Open the file.
   inputFile.open("inventory.dat");


    for(int x = 0; x < MAX_DEVICES && inputFile >> devices[x].name; x++)
    {
        inputFile >> devices[x].sku
                  >> devices[x].quantity >> devices[x].price;

        size++;
    }

    // Validate and process the user's choice.
    do
    {
        choice = getChoice();
        // Respond to the user's menu selection.
        switch (choice)
        {
        case DISPLAY:
            display(devices, size);
            break;
        case LOOKUP_SKU_CHOICE:
            skuSearch(devices, size);
            break;
        case LOOKUP_NAME_CHOICE:
            nameSearch(devices, size);
            break;
        }
    }while (choice != QUIT_CHOICE);

    // Close the file.
    inputFile.close();

   return 0;
}
