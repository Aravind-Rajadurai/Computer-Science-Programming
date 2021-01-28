// File name: LabRats.cpp
//
// Author: Aravind Rajadurai
// Date: 12/03/2017
// Assignment Number: 1
// CS 2308.256, Fall 2017
// Instructor: Yijuan Lu
//
// Represents a list of strings.
// Supports adding and removing strings, displaying and sorting strings,
// finding the minimum and count of the number of strings in the list.
// Specification file for the IntStack class
// Adapted from Gaddis source code

#include<iostream>
#include<iomanip>

using namespace std;

const int NUM_RATS = 9;

struct Rat {
    string name;
    double weight;
    int time;
};

double getAverageWeight (Rat rats[])
{
    double total = 0;
    
    for(int index = 0; index < NUM_RATS; index++)
        total = total + rats[index].weight;
    return total/NUM_RATS;
}

void fastestAndSlowest (Rat rats[], int &maxIndex, int &minIndex)
{
    minIndex = 0;
    maxIndex = 0;
    
    for(int index = 0; index < NUM_RATS; index++)
    {
        if (rats[index].time < rats[minIndex].time)
            minIndex = index;
        if (rats[index].time > rats[maxIndex].time)
            maxIndex = index;
    }
}

int main()
{
    Rat labRats[NUM_RATS] = {
        {"Ben", 6.5, 29},
        {"Fred", 5.8, 31},
        {"Spinter", 7.7, 33},
        {"Black Bean", 5.8, 31},
        {"Pinto Bean", 9.8, 34},
        {"Skat", 6.5, 29},
        {"Big Pook", 9.8, 34},
        {"Tiger", 7.7, 33}
    };
    
    for (int i =  0; i < NUM_RATS; i++)
        cout << labRats[i].name << " " << labRats[i].weight << "" << labRats[i].time << endl;
    
    cout << endl;
    
    cout << "Average weight: " << getAverageWeight(labRats) << endl;
    
    int slowIndex, fastIndex;
    fastestAndSlowest(labRats, slowIndex, fastIndex);
    cout << "Fastest Rat: " << labRats[fastIndex].name << "Time: " << labRats[fastIndex].time << endl;
    cout << "Slowest Rat: " << labRats[slowIndex].name << "Time: " << labRats[slowIndex].time << endl;
    
        
}
