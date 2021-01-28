// File name: a_r815_assignment8.cpp
//
// Author: Aravind Rajadurai
// Date: 4/11/2018
// Assignment Number: 8
// CS 2308, Spring 2018
// Instructor: Patricia Carando
//
//  List.h
//
//  Created by Aravind Adric on 4/11/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//
#include "ListNode.h"

#ifndef List_h
#define List_h

class List {
private:
    ListNode *listHead = NULL;
    
protected:
    ListNode *getListHead();
    void setListHead (ListNode *);
    
public:
    List();
    virtual void appendValue(int);
    bool containsValue (int);
    virtual void insertValue(int);
    bool isEmpty();
    void removeValue(int);
    void print();
    virtual ~List();
};


#endif /* List_h */
