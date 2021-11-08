#pragma once
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class MediaFile
{
private:

protected:
	char type;
	string title;
	int rating;
	string genre;
	int yearReleased;

public:
	MediaFile()
	{
		type = '\0';
		title = "";
		rating = 0;
		genre = "";
		yearReleased = 1200;
	}

	char GetType();
	string GetTitle();
	int GetRating();
	string GetGenre();
	int GetYearReleased();

	void SetType();
	void SetTitle();
	void SetRating();
	void SetGenre();
	void SetYearReleased();

	virtual void PrintMediaList(vector<MediaFile *>) const;



};

