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
	int GetPages();
	void SetAuthor(string);
	void SetPages(int);
	vector<Book> v_books;
	void PrintMediaList(vector<MediaFile*>) const override;

};

