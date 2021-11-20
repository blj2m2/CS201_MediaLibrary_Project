#pragma once
#include <iostream>
#include "MediaFile.h"




class Song: public MediaFile
{

private:
	string artist;
	int duration;

protected:


public:
	Song()
	{
		artist = "";
		duration = 0;
	}
	string GetArtist();
	int GetDuration();
	void SetArtist(string);
	void SetDuration(int);
	vector<Song> v_songs;
	void PrintMediaList();

	void GetSingleRecord(string&) const;



};

