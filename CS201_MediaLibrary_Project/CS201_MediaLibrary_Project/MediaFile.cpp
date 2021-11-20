#include "MediaFile.h"

string MediaFile::GetTitle()
{
    return title;
}

int MediaFile::GetRating()
{
    return rating;
}

string MediaFile::GetGenre()
{
    return genre;
}

int MediaFile::GetYearReleased()
{
    return yearReleased;
}

void MediaFile::SetTitle(string title)
{
    this->title = title;
}

void MediaFile::SetRating(int rating)
{
    this->rating = rating;
}

void MediaFile::SetGenre(string genre)
{
    this->genre = genre;
}

void MediaFile::SetYearReleased(int yearReleased)
{
    this->yearReleased = yearReleased;
}

void MediaFile::PrintMediaList(vector<MediaFile*>) const
{
}

string MediaFile::GetSingleRecord() const
{
    return string();
}
