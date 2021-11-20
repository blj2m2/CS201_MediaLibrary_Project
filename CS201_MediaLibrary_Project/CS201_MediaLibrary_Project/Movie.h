#pragma once
#include <iostream>
#include "MediaFile.h"

using std::vector;

class Movie: public MediaFile
{
private:
	string director;
	int duration;
	string movieRecord;
	
	

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

	void SetMovieRecord(string record);

	
	void listMovieStars();
	void findMovies();
	void PrintMediaList();
	void GetSingleRecord(string&) const;
	void AddMovie(string, string, int, string, int, int, vector<string>);
	vector<Movie> v_movies;
	vector<string> stars;


};

