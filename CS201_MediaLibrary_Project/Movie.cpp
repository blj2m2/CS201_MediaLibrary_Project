#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <exception>
#include <algorithm>
#include "Movie.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::setw;
using std::cin;
using std::invalid_argument;

Movie obj_movie;

string Movie::GetDirector()
{
    return director;
}

int Movie::GetDuration()
{
    return duration;
}

void Movie::SetDirector(string director)
{
    this->director = director;
}

void Movie::SetDuration(int duration)
{
    this->duration = duration;
}

void Movie::listMovieStars()
{
}

void Movie::findMovies()
{
}

void Movie::PrintMediaList(vector<MediaFile*>) const
{
}

void Movie::AddMovie(string title, string director, int rating, string genre, int duration, int yearReleased, vector<string> stars) 
{
    unsigned j;
    obj_movie.title = title;
    obj_movie.director = director;
    obj_movie.rating = rating;
    obj_movie.genre = genre;
    obj_movie.duration = duration;
    obj_movie.yearReleased = yearReleased;
    //test this portion of stars
    for (j = 8; j < stars.size(); j++)
    {
        obj_movie.stars.push_back(stars[j]);
    }
    movies.push_back(obj_movie);
    obj_movie.stars.clear();
}
