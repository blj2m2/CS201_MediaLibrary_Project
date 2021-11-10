#include "Book.h"


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
