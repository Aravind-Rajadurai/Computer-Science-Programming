// File name: Film.cpp
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


#include "Film.h"

Film :: ~Film()
{
}

Film :: Film()
{
    id = 0;
    name = "";
    description = "";
    runningTime = 0;
    rating = UNRATED;
}

Film :: Film (int i, string f, string d, int t, string r)
{
    id = i;
    name = f;
    description = d;
    runningTime = t;
    rating = stringToFilmRating(r);
}

Film :: Film (int i, string f, string d, int t, FilmRating r)
{
    id = i;
    name = f;
    description = d;
    runningTime = t;
    rating = r;
}

void Film :: printFilm()
{
    cout << "Film title       : " << name << endl
         << "Film description : " << description << endl
         << "Film running time: " << runningTime << endl
         << "Film rating      : " << filmRatingToString(rating)
         << endl << endl;
}

void Film :: displayMoviesList (vector <Film> films)
{
    for (int i=0; i < films.size(); i++) // Prints the values in ascending
    {
        films[i].printFilm();
    }

    cout << endl;
}

int Film :: getId()
{
    return id;
}

string Film :: getName()
{
    return name;
}

void Film :: setName(string filmName)
{
    name = filmName;
}

string Film :: getDescription()
{
    return description;
}

void Film :: setDescription(string filmDescription)
{
    description = filmDescription;
}

int Film :: getRunningTime()
{
    return runningTime;
}

void Film :: setRunningTime(int filmRunningTime)
{
    runningTime = filmRunningTime;
}

void Film :: setRating(FilmRating filmRating)
{
    rating = filmRating;
}

Film :: FilmRating Film :: getRating()
{
    return rating;
}

string Film :: filmRatingToString(FilmRating r)
{
    if (r == G)
        return "G";

    else if(r == PG)
        return "PG";

    else if(r == PG_13)
        return "PG_13";

    else if(r == NC_17)
        return "NC_17";

    else if(r == R)
        return "R";

    else
        return "UNRATED";
}

Film :: FilmRating Film :: stringToFilmRating(string r)
{
    if (r == "G")
        return G;

    else if(r == "PG")
        return PG;

    else if(r == "PG_13")
        return PG_13;

    else if(r == "NC_17")
        return NC_17;

    else if(r == "R")
        return R;

    else
        return UNRATED;
}


