#include <iostream>
#include <string>
#include "Book.h"

using std::to_string;
using std::cin;
using std::cout;


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
	for (auto& i : v_books)
	{
		cout << i.author << i.genre;
	}

}

void Book::GetSingleRecord(string& record) const
{
    
    record = title + "," + author + "," + to_string(rating) + ", " + genre + "," + to_string(pages) + "," + to_string(yearReleased);
    
}
