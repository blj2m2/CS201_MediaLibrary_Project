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
    string choice;
    //this function is for listing the movie stars of a certain movie
    cout << "Which movie?" << endl;
    cin >> choice;
    for (auto& i : v_movies) {
        if (i.title == choice) {
            for (size_t j = 0; j < i.stars.size(); j++)
            {
                cout << i.stars.at(j) << endl;
            }
        }
    }

}

void Movie::findMovies()
{
    //user will input a star. search through stars, if star is found, print out the movie they are in.
    string choice;
    cout << "Which star?" << endl;
    cin.ignore();
    getline(cin, choice);
    for (auto& i : v_movies) {
        for (size_t j = 0; j < i.stars.size(); j++) {
            if (i.stars.at(j) == choice) {
                cout << i.title << endl;
            }
        }
    }

}

void Movie::PrintMediaList()
{

    cout << setw(40) << "Title" << setw(30) << "Director" << setw(20) << "Rating" << setw(20) << "Genre" << setw(20) << "Duration" << setw(15) << "Year Released" << endl;
    for (auto& i : v_movies) {
        //v_movies? or individual calls like below function?
        cout << setw(40) << i.title << setw(30) << i.director << setw(20) << i.rating << setw(20) << i.genre << setw(20) << i.duration << setw(15) << i.yearReleased << endl;
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
