#pragma once
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class MediaFile
{
private:

protected:
	
	string title;
	int rating;
	string genre;
	int yearReleased;

public:
	MediaFile()
	{
		title = "";
		rating = 0;
		genre = "";
		yearReleased = 1200;
	}

	
	string GetTitle();
	int GetRating();
	string GetGenre();
	int GetYearReleased();

	void SetTitle(string);
	void SetRating(int);
	void SetGenre(string);
	void SetYearReleased(int);

	virtual void PrintMediaList(vector<MediaFile *>) const;



};

