#pragma once
#include <iostream>
#include "MediaFile.h"


class Books: public MediaFile
{

private:
	string author;
	int pages;

protected:

public:
	Books()
	{
		author = "";
		pages = 0;
	}
	string GetAuthor();
	string GetPages();
	void SetAuthor();
	void SetPages();
	vector<Books> books;
	void PrintMediaList(vector<MediaFile*>) const override;

};

