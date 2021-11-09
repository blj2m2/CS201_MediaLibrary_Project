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
	void SetArtist();
	void SetDuration();
	vector<Song> songs;
	void PrintMediaList(vector<MediaFile*>) const override;



};

