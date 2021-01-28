// File name: a_r815_assignment8.cpp
//
// Author: Aravind Rajadurai
// Date: 4/11/2018
// Assignment Number: 8
// CS 2308, Spring 2018
// Instructor: Patricia Carando
//
//  SortedList.h
//  Assignment 8
//
//  Created by Aravind Adric on 4/18/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//

#ifndef SortedList_h
#define SortedList_h

#include "List.h"
#include "SetList.h"

class SortedList:
public List
{
public:
    SortedList();
    void appendValue (int);
    void insertValue (int);
    virtual ~SortedList();
};


#endif /* SortedList_h */

