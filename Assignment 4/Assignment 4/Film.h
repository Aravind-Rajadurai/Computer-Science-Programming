// File name: Film.h
//
// Author: Aravind Rajadurai
// Date: 12/03/2017
// Assignment Number: 4
// CS 2308.256, Spring 2018
// Instructor: Patricia Carando
//
// Adapted from Gaddis source code
//
//  Created by Aravind Adric on 3/1/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

#ifndef FILM_H
#define FILM_H

const int NUM_FLIMS = 10;

class Film
{
public:
    enum FilmRating  {G, PG, PG_13, NC_17, R, UNRATED};

private:
    //Member Functions
    int id; // the unique id of the film
    string name; // the film's name
    string description; // the film's description
    int runningTime; // the film's running time in minutes <= 180
    FilmRating rating; // the film's rating, from the const decls



public:
    Film(); //default constructor
    ~Film(); // destructor
    Film (int, string, string, int, string); //overload constructor
    Film (int, string, string, int, FilmRating); //overload constructor
    vector <Film> storeMovies(vector <Film> films);
    void printFilm ();
    void displayMoviesList (vector <Film> films);

    int getId();
    string getName();
    void setName(string);
    string getDescription();
    void setDescription(string);
    int getRunningTime();
    void setRunningTime(int);
    void setRating(FilmRating);
    FilmRating getRating();
    string filmRatingToString(FilmRating);
    FilmRating stringToFilmRating(string);

};

#endif /* FILM_H */
