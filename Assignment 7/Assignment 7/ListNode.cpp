// File name: a_r815_assignment8.cpp
//
// Author: Aravind Rajadurai
// Date: 4/11/2018
// Assignment Number: 8
// CS 2308, Spring 2018
// Instructor: Patricia Carando
//
//  ListNode.cpp
//
//
//  Created by Aravind Adric on 4/11/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//

#include "List.h"
#include "ListNode.h"

//#include <iostream>

ListNode::ListNode(int node)
{
    this -> nodeValue = node;
}

ListNode *ListNode::getNext()
{
    return next;
}

void ListNode::setNext(ListNode *node)
{
    this -> next = node;
}

int ListNode::getValue()
{
    return nodeValue;
}

void ListNode::putValue(int Value)
{
    nodeValue = Value;
}

ListNode::~ListNode()
{
    
}
