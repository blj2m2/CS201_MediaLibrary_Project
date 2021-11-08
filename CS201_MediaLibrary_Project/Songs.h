#pragma once
#include <iostream>
#include "MediaFile.h"




class Songs: public MediaFile
{

private:
	string artist;
	int duration;

protected:


public:
	Songs()
	{
		artist = "";
		duration = 0;
	}
	string GetArtist();
	int GetDuration();
	void SetArtist();
	void SetDuration();
	vector<Songs> songs;
	void PrintMediaList(vector<MediaFile*>) const override;



};

