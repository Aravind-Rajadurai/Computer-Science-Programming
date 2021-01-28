// File name: FilmDriver.cpp
//
// Author: Aravind Rajadurai
// Date: 12/03/2017
// Assignment Number: 4
// CS 2308.256, Spring 2018
// Instructor: Patricia Carando
//
// Adapted from Gaddis source code

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>

#include "Film.h"

using namespace std;

int main()
{
    int id;
    string name;
    string description;
    int runningTime;
    string rating;
    
    string sid, sr;
    
    vector <Film> films; //initializing flims, contains the number of flims
    
    ifstream film;
    film.open("Film.txt"); // Text file
    
    if ( !film )
    {
        cout << endl << endl
        << " Program Terminated. " << endl << endl
        << "Input file failed to open!" << endl;
        
        return 1;
    }
    
    else
        for (int i = 0; i < NUM_FLIMS; i++)
        {
            getline(film, sid, ',');
            id = atoi(sid.c_str());
            
            getline(film, name, ',');
            getline(film, description, ',');
            getline(film, sr, ',');
            runningTime = atoi(sr.c_str());
            getline(film,rating);

        }
   

    
    Film object (id, name, description, runningTime, rating);
    object.displayMoviesList(films);
    
    
    film.close();
    
    return 0;
}
