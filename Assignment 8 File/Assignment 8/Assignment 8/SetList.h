// File name: a_r815_assignment8.cpp
//
// Author: Aravind Rajadurai
// Date: 4/11/2018
// Assignment Number: 8
// CS 2308, Spring 2018
// Instructor: Patricia Carando
//
//  SetList.hpp
//  Assignment 8
//
//  Created by Aravind Adric on 4/11/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//

#ifndef SetList_h
#define SetList_h

#include "SortedList.h"
class SortedList;

class SetList {
private:
    SortedList *sortedList;
    
public:
    SetList();
    void       addValue (int);
    bool       containsValue (int);
    bool       isEmpty();
    void       print();
    void       removeValue(int);
    virtual ~SetList();
};


#endif /* SetList_h */
