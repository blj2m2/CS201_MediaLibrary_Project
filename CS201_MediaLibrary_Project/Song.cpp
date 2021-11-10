#include "Song.h"


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
