#include <iostream>
#include <string>
#include <iomanip>
#include "Song.h"

using std::to_string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::left;


string Song::GetArtist()
{
    return artist;
}

int Song::GetDuration()
{
    return duration;
}

void Song::SetArtist(string artist)
{
    this->artist = artist;
}

void Song::SetDuration(int duration)
{
    this->duration = duration;
}

void Song::PrintMediaList()
{
    cout << setw(20) << left << "Song Listing" << endl << endl;

    cout << setw(40) << "Title" << setw(25) << "Author" << setw(10) << "Rating" << setw(25) << "Genre" << setw(10) << "# Pages" << setw(20) << "Year Published" << endl;
    for (auto& i : v_songs)
    {


        cout << setw(40) << i.title << setw(25) << i.artist << setw(10) << i.rating << setw(25) << i.genre << setw(10) << i.duration << setw(20) << i.yearReleased << endl;

    }
}

void Song::GetSingleRecord(string& record) const
{
    record = title + "," + artist + "," + to_string(rating) + "," + genre + "," + to_string(duration) + "," + to_string(yearReleased);

}
