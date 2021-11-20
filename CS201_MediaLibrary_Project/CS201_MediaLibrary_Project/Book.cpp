#include <iostream>
#include <string>
#include "Book.h"

using std::to_string;
using std::cin;
using std::cout;
using std::endl;


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
	cout << "Book Listing" << endl;
	//Title - Author - Rating - Genre - Pages - Year Released

	for (auto& i : v_books)
	{
		cout << i.author << i.genre;
	}
	/*cout << setw(15) << "Transaction ID" << setw(20) << "Transaction Type" << setw(25) << "Transaction Status" << setw(47) << "Transaction Desc." << setw(27) << "Transaction Date/Time" << endl;
	for (auto& i : v_transaction)
	{
		if (i.transactionType == "Book" && i.transactionStatus != "Error")
		{
			cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(47) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
		}
	}*/
}

void Book::GetSingleRecord(string& record) const
{
	
	record = title + "," + author + "," + to_string(rating) + ", " + genre + "," + to_string(pages) + "," + to_string(yearReleased);
	
}
