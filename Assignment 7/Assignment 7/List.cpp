// File name: a_r815_assignment8.cpp
//
// Author: Aravind Rajadurai
// Date: 4/11/2018
// Assignment Number: 8
// CS 2308, Spring 2018
// Instructor: Patricia Carando
//
//  List.cpp
//
//  Created by Aravind Adric on 4/11/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//

#include "List.h"
#include "ListNode.h"

//#include <iostream>

List::List()
{

}

ListNode* List::getListHead()
{
    return listHead;
}

void List::setListHead (ListNode *listHead)
{
    this -> listHead = listHead;
}

void List::appendValue(int value)
{
    ListNode * newNode;
    ListNode * nodePtr;
    
    newNode = new ListNode(value);
    
    if(isEmpty())
    {
        setListHead(newNode);
        return;
    }
    
    nodePtr = getListHead();
    
    while(nodePtr -> getNext())
    {
        nodePtr = nodePtr -> getNext();
    }
    
    nodePtr -> setNext(newNode);
}

bool List::containsValue(int value)
{
    ListNode * nodePtr;
    nodePtr = getListHead();
    
    while(nodePtr)
    {
        if(nodePtr -> getValue() == value)
            return true;
            nodePtr= nodePtr->getNext();
    }
    return false;
}

void List::insertValue(int value)
{
    ListNode * newNode = new ListNode(value);
    ListNode * nodePtr = getListHead();
    
    if(isEmpty())
    {
        setListHead(newNode);
        return;
    }
    else
    {
        newNode->putValue(value);
        newNode->setNext(getListHead());
        setListHead(newNode);
    }
}

bool List::isEmpty()
{
    if(getListHead() == 0)
        return true;
    else
        return false;
}

void List::removeValue(int value)
{
    ListNode * nodePtr = new ListNode(value);
    ListNode * previousNode = nullptr;
    
    if (isEmpty())
        return;
    
    if(getListHead() -> getValue() == value)
    {
        nodePtr = getListHead();
        nodePtr = nodePtr->getNext();
        delete getListHead();
        setListHead(nodePtr);
    }
    else
    {
        nodePtr = getListHead();
        
        while(nodePtr != nullptr && nodePtr->getValue() != value)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr -> getNext();
        }
        
        if (nodePtr)
        {
            previousNode->setNext(nodePtr->getNext());
            delete nodePtr;
        }

    }
}

void List::print()
{
    if (isEmpty())
    {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    
    int nodeEntry = 0;
    ListNode *currentNode = getListHead();
    while (currentNode != nullptr)
    {
        std::cout << "Node " << nodeEntry << ": " << currentNode -> getValue() << std::endl;
        currentNode = currentNode->getNext();
        nodeEntry++;
    }
}

List::~List()
{
    ListNode * nodePtr = listHead;
    while(nodePtr != nullptr)
    {
        std::cout<< "Deleting node with values " << nodePtr -> getValue()<<std::endl;
        
        ListNode * deleteptr = nodePtr;
        nodePtr = nodePtr->getNext();
        delete deleteptr;
    }
}
