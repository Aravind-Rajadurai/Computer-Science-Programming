// File name: IntStack.h
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

class IntStack
{
private:
    struct Node          // the Nodes of the linked list
    {
        char data;           // data is a integer
        Node *next;      // points to next node in list
    };
    
    Node *head;           // ptr to top
    
public:
    // Constructor
    IntStack();
    
    //Destructor
    ~IntStack();
    
    // Stack operations
    void push(int);
    int pop();
    bool isFull();
    bool isEmpty();
};

