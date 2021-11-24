#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"


using std::to_string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::left;


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

void Book::PrintMediaList()
{
	cout << setw(20) << left << "Book Listing" << endl << endl;

	cout << setw(40) << "Title" << setw(25) << "Author" << setw(10) << "Rating" << setw(25) << "Genre" << setw(10) << "# Pages" << setw(20) << "Year Published" << endl;
	for (auto& i : v_books)
	{


		cout << setw(40) << i.title << setw(25) << i.author << setw(10) << i.rating << setw(25) << i.genre << setw(10) << i.pages << setw(20) << i.yearReleased <<  endl;

	}
}

void Book::GetSingleRecord(string& record) const
{
	
	record = title + "," + author + "," + to_string(rating) + ", " + genre + "," + to_string(pages) + "," + to_string(yearReleased);
	
}
