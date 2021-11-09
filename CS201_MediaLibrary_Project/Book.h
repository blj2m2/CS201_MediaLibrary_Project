#pragma once
#include <iostream>
#include "MediaFile.h"


class Book: public MediaFile
{

private:
	string author;
	int pages;

protected:

public:
	Book()
	{
		author = "";
		pages = 0;
	}
	string GetAuthor();
	string GetPages();
	void SetAuthor();
	void SetPages();
	vector<Book> books;
	void PrintMediaList(vector<MediaFile*>) const override;

};

