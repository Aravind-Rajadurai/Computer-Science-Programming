// File name: a_r815_assignment2.cpp
//
// Author: Aravind Rajadurai
// Date: 2/06/2018
// Assignment Number: 2
// CS 2308, Spring 2018
// Instructor: Patricia Carando
//
//  Created by Aravind Adric on 2/6/18.
//  Copyright © 2018 Aravind Adric. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


// Constants for Film Ratings
const int FILM_RATING_G       = 0;
const int FILM_RATING_PG      = 1;
const int FILM_RATING_PG_13   = 2;
const int FILM_RATING_R       = 3;
const int FILM_RATING_NC_17   = 4;
const int FILM_RATING_UNRATED = 5;


const int NUM_FLIMS = 10;

struct Film
{
    int id; // the unique id of the film
    string name; // the film's name
    string description; // the film's description
    int runningTime; // the film's running time in minutes <= 180
    int rating; // the film's rating, from the const decls
};

vector <Film> storeMovies(vector <Film> films);
vector <Film> selectionSort (vector <Film> films);
vector <Film> findFilmsByRating ( int, vector <Film> films);
vector <Film> findFilmsByRatingAndRunningTime ( int, int, vector <Film> films);
void displayMoviesList (vector <Film> films);
void printFlim (Film);
string filmRatingToString(int);


int main()
{
    vector <Film> sortedFilms,sortedRatings, sortedFilmsRatings;
    
    
    vector <Film> films (NUM_FLIMS); //initializing flims, contains the number of flims
    
    films = storeMovies(films);
    
   //sortedRatings= sortedFilms (films);
    
    
    
    cout << "****** Films in sorted order by run time *****" << endl;
    sortedFilms = selectionSort (films);
    displayMoviesList(sortedFilms);
    
    cout << "****** Films in sorted order by rating *****" << endl;
    sortedRatings = findFilmsByRating (2, sortedFilms);
    displayMoviesList(sortedRatings);

    cout << "****** Films rated PG 13 or less with running time < 90 *****" << endl;
    sortedFilmsRatings = findFilmsByRatingAndRunningTime (2, 90, sortedFilms);
    displayMoviesList(sortedFilmsRatings);
    
        return 0;
}

vector <Film> storeMovies(vector <Film> films)
{
    Film film;
    
    //Vector now has 1 element at index 0
    films [0].id = 0;
    films [0].name = "Interstellar";
    films [0].description = "Plans to save mankind via a wormhole";
    films [0].runningTime = 169;
    films [0].rating = FILM_RATING_PG_13;
    
    //Vector now has 2 element at index 1
    films [1].id = 1;
    films [1].name = "The Curious Case of Benjamin Buttons";
    films [1].description = "Man born under unusual circumstances";
    films [1].runningTime = 166;
    films [1].rating = FILM_RATING_PG_13;
    
    
    //Vector now has 3 element at index 2
    films [2].id = 2;
    films [2].name = "Age of Adeline";
    films [2].description = "Women stuck being 29 years of age for nearly eight decades";
    films [2].runningTime = 112;
    films [2].rating = FILM_RATING_PG_13;
    
    //Vector now has 4 element at index 3
    films [3].id = 3;
    films [3].name = "The Wolf of Wall Street";
    films [3].description = "Wealthy stock-broker living the high life to his fall involving crime";
    films [3].runningTime = 180;
    films [3].rating = FILM_RATING_R;
    
    //Vector now has 5 element at index 4
    films [4].id = 4;
    films [4].name = "Gone Girl";
    films [4].description = "Wife's disappearance";
    films [4].runningTime = 149;
    films [4].rating = FILM_RATING_R;
    
    //Vector now has 6 element at index 5
    films [5].id = 5;
    films [5].name = "Thor Ragnarok";
    films [5].description = "Imprisoned on the other side of the universe";
    films [5].runningTime = 130;
    films [5].rating = FILM_RATING_PG_13;
    
    //Vector now has 7 element at index 6
    films [6].id = 6;
    films [6].name = "Independence Day";
    films [6].description = "The aliens try to invade and destroy Earth";
    films [6].runningTime = 90;
    films [6].rating = FILM_RATING_PG_13;
    
    //Vector now has 8 element at index 7
    films [7].id = 7;
    films [7].name = "Deadpool";
    films [7].description = "Hero, quest for revenge";
    films [7].runningTime = 108;
    films [7].rating = FILM_RATING_R;
    
    //Vector now has 9 element at index 8
    films [8].id = 8;
    films [8].name = "South Paw";
    films [8].description = "champion boxer revives his professional career";
    films [8].runningTime = 124;
    films [8].rating = FILM_RATING_R;
    
    //Vector now has 10 element at index 9
    films [9].id = 9;
    films [9].name = "The Notebook";
    films [9].description = "Love story";
    films [9].runningTime = 123;
    films [9].rating = FILM_RATING_PG_13;
    
    return films;
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
        return "R";
    
    else if(rating == 4)
        return "NC_17";
    
    else
        return "UNRATED";
}

void printFlim (Film movie)
{
    cout << "Film title \t: " << movie.name << endl
    << "Film description \t: " << movie.description << endl
    << "Film running time \t : " << movie.runningTime << endl
    << "Film rating \t: " << filmRatingToString(movie.rating) << endl;
    
    cout << endl;
    
}

void displayMoviesList (vector <Film> films)
{
    for (int i=0; i < films.size(); i++) // Prints the values in ascending
    {
        printFlim(films[i]);
    }
    
    cout << endl;
}

vector <Film> selectionSort (vector <Film> films)
{
    int minIndex, minValue; //initializing
    
    Film temp;
    
    for (int start = 0; start < films.size(); start++) //runs the loop of the values
    {
        minIndex = start; //stored the location starting value
        minValue = films[start].runningTime; //stores the starting value
        
        for (int index = start + 1; index < films.size(); index++) //runs the loop of the values
        {
            if (films[index].runningTime < minValue) //compares the value
            {
                minValue = films[index].runningTime; //stores the value
                minIndex = index; //stores the index
            }
        }
        temp = films[minIndex]; //using temp to store minimum
        films[minIndex] = films[start]; //storing the start value to minIndex
        films[start] = temp; //switches the value held in temp to start
    }
    
    return films;
}

vector <Film> findFilmsByRating ( int rating, vector <Film> films)
{
    int index = 0; // Used as a subscript to search the array
    
    Film film;
    
    vector <Film> foundMovies;
    
    while (index >= 0 && index < films.size())
    {
        if (films[index].rating <= rating) // If the value is found
        {
            foundMovies.push_back(films[index]);
        }
        index++; // Go to the next element
    }
    return foundMovies; // Return the position, or -1
}

vector <Film> findFilmsByRatingAndRunningTime ( int rating, int runningTime, vector <Film> films)
{
    int index = 0; // Used as a subscript to search the array
    
    Film film;
    
    vector <Film> foundMovies;
    
    while (index >= 0 && index < films.size())
    {
        if (films[index].rating <= rating && films[index].runningTime <= runningTime) // If the value is found
        {
            foundMovies.push_back(films[index]);
        }
        index++; // Go to the next element
    }
    return foundMovies; // Return the position, or -1
}
