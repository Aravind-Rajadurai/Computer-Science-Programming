// File name: IntStackDriver.cpp
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

int main()
{
    IntStack stack1;
    
    char temp;
    
    string filename;
    
    cout << "Enter File: ";
    cin >> filename;
    
    ifstream file(filename.c_str());
    stringstream buffer;
    
    buffer << file.rdbuf();
    string str = buffer.str();
    
    for(int i =0; i < str.length(); i++)
    {
        if(str.at(i) == '(')
        {
            stack1.push('(');
        }
        
        if(str.at(i) == '{')
        {
            stack1.push('{');
        }
        
        if(str.at(i) == '[')
        {
            stack1.push('[');
        }
        
        
        if(str.at(i) == ')' )
        {
            if(stack1.isEmpty())
            {
                cout << "Unmatched )";
                return 0;
            }
            else
            {
                temp = stack1.pop();
                if(temp != '(')
                {
                    if(temp = '{')
                    {
                        cout << "Expected } but found )" << endl;
                        return 0;
                    }
                    else if (temp == '[')
                    {
                        cout << "Expected ] but found )" << endl;
                        return 0;
                    }
                }
            }
        }
        
        if(str.at(i) == '}' )
        {
            if(stack1.isEmpty())
            {
                cout << "Unmatched }";
                return 0;
            }
            else
            {
                temp = stack1.pop();
                if(temp != '{')
                {
                    if(temp = '[')
                    {
                        cout << "Expected ] but found }" << endl;
                        return 0;
                    }
                    else if (temp == '(')
                    {
                        cout << "Expected ) but found }" << endl;
                        return 0;
                    }
                }
            }
        }
        
        if(str.at(i) == ']' )
        {
            if(stack1.isEmpty())
            {
                cout << "Unmatched ]";
                return 0;
            }
            else
            {
                temp = stack1.pop();
                if(temp != '[')
                {
                    if(temp = '{')
                    {
                        cout << "Expected } but found ]" << endl;
                        return 0;
                    }
                    else if (temp == '(')
                    {
                        cout << "Expected ) but found ]" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    
    if(!stack1.isEmpty())
    {
        temp = stack1.pop();
        
        if(temp == '(' )
        {
            cout << "missing: )" << endl;
        }
        
        if(temp == '{' )
        {
            cout << "missing: }" << endl;
        }
        
        if(temp == '[' )
        {
            cout << "missing: ]" << endl;
        }
    }
    else
        cout << "It Worked!" << endl;
    
    
    // Close the file.
    file.close();
    
    return 0;
}
