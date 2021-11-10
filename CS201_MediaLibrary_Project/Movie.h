#pragma once
#include <iostream>
#include "MediaFile.h"

using std::vector;

class Movie: public MediaFile
{
private:
	string director;
	int duration;
	
	

protected:

public:
	Movie()
	{
		director = "";
		duration = 0;
	}
	string GetDirector();
	int GetDuration();

	void SetDirector(string);
	void SetDuration(int);

	
	void listMovieStars();
	void findMovies();
	void PrintMediaList(vector<MediaFile*>) const override;
	void AddMovie(string, string, int, string, int, int, vector<string>);
	vector<Movie> v_movies;
	vector<string> stars;


};

