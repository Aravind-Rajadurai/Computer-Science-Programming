// File name: IntStack.cpp
//
// Author: Aravind Rajadurai
// Date: 12/03/2017
// Assignment Number: 6
// CS 2308.256, Fall 2017
// Instructor: Yijuan Lu
//
// Represents a list of strings.
// Supports adding and removing strings, displaying and sorting strings,
// finding the minimum and count of the number of strings in the list.
// Specification file for the IntStack class
// Adapted from Gaddis source code

#include<iostream>
#include<fstream>
#include<sstream>
#include <assert.h>
#include<iomanip>
using namespace std;

#include "IntStack.h"

IntStack :: IntStack() // constructor
{
    head = NULL;
}

IntStack :: ~IntStack() // destructor
{
    Node *temp = NULL;
    
    while(head != NULL)
    {
        temp = head;
        head = head -> next;
        delete temp;
    }
}

void IntStack :: push(int num)
{
    assert(!isFull());
    
    Node *newN = new Node;
    newN -> data = num;
    newN -> next = head;
    head = newN;
}

int IntStack :: pop()
{
    assert(!isEmpty());
    
    Node *temp = head;
    int result = head -> data;
    head = head -> next;
    delete temp;
    return result;
}

bool IntStack :: isFull()
{
    return false;
}

bool IntStack :: isEmpty()
{
    return (head == NULL);
}
