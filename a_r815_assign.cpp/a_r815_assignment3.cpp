// File name: a_r815_assignment3.cpp
//
// Author: Aravind Rajadurai
// Date: 2/06/2018
// Assignment Number: 3
// CS 2308, Spring 2018
// Instructor: Patricia Carando
//
// A program illustrating dynamic allocation of memory, dynamic resizing, and
// copying original values into a dynamically allocated array but in reverse order
//
//  Created by Aravind Adric on 2/6/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int NUM_FILMS = 4;

struct Film
{
    int id; // the unique id of the film
    string name; // the film's name
    string description; // the film's description
    int runningTime; // the film's running time in minutes <= 180
    int rating; // the film's rating, from the const decls
};

enum FilmRating  {G, PG, PG_13, NC_17, R, UNRATED};

string filmRatingToString(int rating);
void printFlim (Film);
void printFilms (Film*);
Film * resize (Film *films, int currentSize, int newSize);
Film * reverse (Film *films, int currentSize);


int main()
{
    
    Film *films = new Film[NUM_FILMS];
    
    
    
    //Array now has 1 element at index 0
    films[0].id = 0;
    films[0].name = "Interstellar";
    films[0].description = "Plans to save mankind via a wormhole";
    films[0].runningTime = 169;
    films[0].rating = PG_13;
    
    //Array now has 2 element at index 1
    films[1].id = 1;
    films[1].name = "The Curious Case of Benjamin Buttons";
    films[1].description = "Man born under unusual circumstances";
    films[1].runningTime = 166;
    films[1].rating = PG_13;
    
    
    //Array now has 3 element at index 2
    films[2].id = 2;
    films[2].name = "Age of Adeline";
    films[2].description = "Women stuck being 29 years of age for nearly eight decades";
    films[2].runningTime = 112;
    films[2].rating = PG_13;
    
    //Array now has 4 element at index 3
    films[3].id = 3;
    films[3].name = "The Wolf of Wall Street";
    films[3].description = "Wealthy stock-broker living the high life to his fall involving crime";
    films[3].runningTime = 180;
    films[3].rating = R;
    
    cout << "****** Films in original order *****" << endl;
    printFilms(films);
    
    
    films = resize(films, NUM_FILMS, NUM_FILMS+1);
    
    NUM_FILMS = 4 + 1;
    
    //Array now has 5 element at index 4
    films [4].id = 4;
    films [4].name = "Thor Ragnarok";
    films [4].description = "Imprisoned on the other side of the universe";
    films [4].runningTime = 130;
    films [4].rating = PG_13;
    
    // The function that "resizes" the memory for an array, usually allocating
    // more memory
    cout << "****** Films After resized by 1 *****" << endl;
    printFilms(films);
    
    // The function that allocates memory for the reverse copy of the input
    // array and creates the reverse copy
    films = reverse (films, NUM_FILMS);
    cout << "****** Films reversed after 1 *****" << endl;
    printFilms(films);
    
    
    films = resize(films, NUM_FILMS, NUM_FILMS+1);
    
    NUM_FILMS = 4 + 2;
    
    //Array now has 7 element at index 6
    films [5].id = 5;
    films [5].name = "Independence Day";
    films [5].description = "The aliens try to invade and destroy Earth";
    films [5].runningTime = 90;
    films [5].rating = PG_13;
    
    // The function that "resizes" the memory for an array, usually allocating
    // more memory
    cout << "****** Films After resized by 2 *****" << endl;
    printFilms(films);
    
    // The function that allocates memory for the reverse copy of the input
    // array and creates the reverse copy
    films = reverse (films, NUM_FILMS);
    cout << "****** Films reversed after 2 *****" << endl;
    printFilms(films);
    
    
    return 0;
}

string filmRatingToString(int rating)
{
    if (rating == 0)
        return "G";
    
    else if(rating == 1)
        return "PG";
    
    else if(rating == 2)
        return "PG_13";
    
    else if(rating == 3)
        return "NC_17";
    
    else if(rating == 4)
        return "R";
    
    else
        return "UNRATED";
}

void printFlim (Film films)
{
    cout << "Film title \t: " << films.name << endl
    << "Film description \t: " << films.description << endl
    << "Film running time \t : " << films.runningTime << endl
    << "Film rating \t: " << filmRatingToString(films.rating) << endl;
    
    cout << endl;
    
}

void printFilms (Film *films)
{
    for (int i = 0; i < NUM_FILMS; i++) // Prints the values in ascending
    {
        printFlim(films[i]);
    }
    
    cout << endl;
}

Film * resize (Film *films, int currentSize, int newSize)
{
    Film *newArrFilms = new Film[newSize];
    
    for (int i = 0; i < currentSize; i++) {
        newArrFilms[i] = films[i];
    }
    
    delete[] films;
    return newArrFilms;
}

Film * reverse (Film *films, int currentSize)
{
    Film *newArrFilms = new Film[currentSize];
    
    int fromTheEnd = currentSize - 1;
    for (int i = 0; i < currentSize; i++)
    {
        newArrFilms [fromTheEnd] = films[i];
        fromTheEnd--;
    }
    return newArrFilms;
}
