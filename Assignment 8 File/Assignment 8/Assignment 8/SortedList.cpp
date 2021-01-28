// File name: a_r815_assignment8.cpp
//
// Author: Aravind Rajadurai
// Date: 4/11/2018
// Assignment Number: 8
// CS 2308, Spring 2018
// Instructor: Patricia Carando
//
//  SortedList.cpp
//
//  Created by Aravind Adric on 4/18/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//

#include "List.h"
#include "SetList.h"
#include "SortedList.h"

//#include <iostream>

SortedList::SortedList()
{
    
}

void SortedList::appendValue(int value)
{
    
}

void SortedList::insertValue(int value)
{
    
    
    ListNode * newNode;
    ListNode * nodePtr;
    ListNode * previousNode;
    
    newNode = new ListNode(value);
    nodePtr = getListHead();
    previousNode = NULL;
    
    if(isEmpty())
    {
        setListHead(newNode);
        return;
    }
    else
    {
        nodePtr = getListHead();
        previousNode = NULL;
        
        while(nodePtr != NULL && nodePtr->getValue() < value)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->getNext();
        }
        if (previousNode == NULL)
        {
            newNode->setNext(nodePtr);
            setListHead(newNode);
        }
        else
        {
            
            previousNode -> setNext(newNode);
            newNode -> setNext(nodePtr);
            
        }
    }
    
}

SortedList::~SortedList()
{
    
}


