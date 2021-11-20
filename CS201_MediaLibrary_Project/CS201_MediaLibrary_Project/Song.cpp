#include <iostream>
#include <string>
#include "Song.h"

using std::to_string;


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

void Song::PrintMediaList(vector<MediaFile*>) const
{
}

void Song::GetSingleRecord(string& record) const
{
    record = title + "," + artist + "," + to_string(rating) + "," + genre + "," + to_string(duration) + "," + to_string(yearReleased);

}
