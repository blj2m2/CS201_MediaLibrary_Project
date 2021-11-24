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
using std::to_string;

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

void Movie::SetMovieRecord(string record)
{
    movieRecord = record;
}

void Movie::listMovieStars()
{
}

void Movie::findMovies()
{
}

void Movie::PrintMediaList()
{

    cout << "Movie Listing" << endl;
    //Title - Author - Rating - Genre - Pages - Year Released

    for (auto& i : v_movies)
    {
        cout << i.title << i.director << endl;
            for (size_t j = 0; j < i.stars.size(); j++)
            {
                cout << i.stars.at(j);
            }
    }
}

void Movie::GetSingleRecord(string& record) const
{
    
    record = title + "," + director + "," + to_string(rating) + "," + genre + "," + to_string(duration) + "," + to_string(yearReleased);
    for (size_t i = 0; i < stars.size(); i++)
    {
        
        record.append (" , " + stars.at(i));
    }
 
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
    v_movies.push_back(obj_movie);
    obj_movie.stars.clear();
}
