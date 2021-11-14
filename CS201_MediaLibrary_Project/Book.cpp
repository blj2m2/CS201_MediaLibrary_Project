#include <iostream>
#include <string>
#include "Book.h"

using std::to_string;


string Book::GetAuthor()
{
	return author;
}

int Book::GetPages()
{
	return pages;
}


void Book::SetAuthor(string author)
{
	this->author = author;
}

void Book::SetPages(int pages)
{
	this->pages = pages;
}

void Book::PrintMediaList(vector<MediaFile*>) const
{
}

void Book::GetSingleRecord(string& record) const
{
    
    record = title + "," + author + "," + to_string(rating) + ", " + genre + "," + to_string(pages) + "," + to_string(yearReleased);
    
}
