#pragma once
#include <iostream>
#include "MediaFile.h"

using std::vector;

class Movies: public MediaFile
{
private:
	string director;
	int duration;


protected:

public:
	Movies()
	{
		director = "";
		duration = 0;
	}
	string GetDirector();
	string GetDuration();

	void SetDirector();
	void SetDuration();

	vector<string> stars;
	vector<Movies> movies;
	void listMovieStars();
	void findMovies();
	void PrintMediaList(vector<MediaFile*>) const override;


};

