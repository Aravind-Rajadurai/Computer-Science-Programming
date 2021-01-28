// File name: a_r815_assignment8.cpp
//
// Author: Aravind Rajadurai
// Date: 4/11/2018
// Assignment Number: 8
// CS 2308, Spring 2018
// Instructor: Patricia Carando
//
//  ListNode.h
//
//  Created by Aravind Adric on 4/11/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h

#include <string>
#include <iostream>

class ListNode {
private:
    ListNode *next = nullptr;
    int nodeValue  = 0;
public:
    ListNode (int);
    ListNode *getNext();
    void setNext (ListNode*);
    int getValue();
    void putValue (int);
    virtual ~ListNode();
};


#endif /* ListNode_h */
