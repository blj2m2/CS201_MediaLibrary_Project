
#include <iostream>
#include <exception>
#include <vector>
#include <iomanip>
#include "DataReader.h"
#include "Book.h"
#include "Movie.h"
#include "Song.h"
#include "TransactionProcessing.h"


using std::endl;
using std::cout;
using std::cin;
using std::setw;
using std::vector;
using std::string;
using std::runtime_error;
using std::invalid_argument;

DataReader file;
Book books;
Movie movies;
Song songs;
string fileName = "";
Transaction objTransaction;
void PrintMenu(char& option);
void GetMenuOption(char& option);
bool verifyOption(char& option);

int main()
{

	vector<vector<string>> v_records;
	vector<vector<string>> importConfig;
	char option = '\0';

	try
	{
		file.ImportFile(v_records,fileName);
		file.importFileConfig(importConfig);
		//use these objects to call functions that should be created below.
		objTransaction.ProcessFileData(v_records, importConfig ,books, movies, songs);
		cout << endl;
		do
		{
			//present the menu until the person select the Q option

			PrintMenu(option);
			GetMenuOption(option);

			//if should happen on false condition
			if (!verifyOption(option))
			{
				cout << "Please chose one of the options from the menu." << endl << endl;
				continue;
			}
			else
			{
				//movies, books and songs shoould all be availble to call directly from main as they were passed by reference to Transaction Processing
				vector < vector<string>> errorRecord;
				int transactionID = 0;
				switch (option)
				{
				case 'M':
					//Print from the movie class - function needs to be written
					cout << "Print Movie List" << endl << endl;
					
					break;
				case 'S':
					//Print from the song class - function needs to be written
					cout << "Print Song List" << endl << endl;
					break;
				case 'F':
					//Print from the move class - function needs to be written
					cout << "Find the Movie the Star is in" << endl << endl;
					break;
				case 'B':
					//Print from the book class - function needs to be written
					cout << "Print Book List" << endl << endl;
					for (auto& i : books.v_books)
					{
						
					}
					break;
				case 'A':
					//Print all Success objects rolled up.
					objTransaction.PrintTransactionSummary();
					break;
				case 'E':
					//Print all Error objects rolled up.
					objTransaction.PrintErrorLog();
					break;
				case 'R':
					cout << "option R chosen" << endl;
					cout << "Please enter the Transaction ID" << endl;
					cin >> transactionID;
					file.OpenFile(fileName, errorRecord,transactionID, books, movies, songs);
					break;
				case 'G':
					//Print from the movie class
					cout << "Print Stars for a Given Movie" << endl << endl;
					break;
				case 'T':
					//Print from the transaction process class. Log will contain all records that have been sucessfully processed
					cout << "Print Media Counts" << endl << endl;
					break;
				case 'Q':
					cout << "Quit" << endl << endl;
					break;

				default:
					break;
				}
			}

		} while (option != 'Q');
	}
	catch (runtime_error& e)
	{
		cout << e.what() << endl << endl;
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl << endl;
	}
    
}

//utility function to check value entered by user.
bool verifyOption(char& option)
{
	bool cleanOption = false;
	if (option != 'm' && option != 'M' && option != 's' && option != 'S' && 
		option != 'f' && option != 'F' && option != 'q' && option != 'Q' &&
		option != 'b' && option != 'B' && option != 'a' && option != 'A' &&
		option != 'G' && option != 'g' && option != 't' && option != 'T' && 
		option != 'E' && option != 'e' && option != 'r' && option != 'R')
	{
		cleanOption = false;
	}
	else
	{
		cleanOption = true;
	}
	return cleanOption;
}

//utility function to output menu choices
void PrintMenu(char& option)
{
	cout << endl;
	cout << setw(20);
	cout << "MENU CHOICES" << endl;
	cout << "M = Print movie list" << endl;
	cout << "B = Print book list" << endl;
	cout << "S = Print song list" << endl;
	cout << "A = Print All Media" << endl;
	cout << "E = Print Error Log" << endl;
	cout << "R = Reprocess error record" << endl;
	cout << "G - Print stars for a given movie" << endl;
	cout << "F - Search for movies based by star" << endl;
	cout << "T = Print Media Counts" << endl;
	cout << "Q - End application" << endl;

}

/// /utility function to get option from user and convert it to upper case
void GetMenuOption(char& option)
{
	cout << endl << "Option: ";
	cin >> option;
	cout << endl;
	cin.clear();
	option = toupper(option);
}