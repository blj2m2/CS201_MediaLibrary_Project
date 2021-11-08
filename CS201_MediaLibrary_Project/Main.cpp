
#include <iostream>
#include <exception>
#include <vector>
#include <iomanip>
#include "DataReader.h"


using std::endl;
using std::cout;
using std::cin;
using std::setw;
using std::vector;
using std::string;
using std::runtime_error;
using std::invalid_argument;

DataReader file;
void PrintMenu(char& option);
void GetMenuOption(char& option);

int main()
{

	vector<vector<string>> v_records;
	char option = '\0';

	try
	{
		file.ImportFile(v_records);
		//This needs to be coded for all objects not just movies.
		//movie.LoadMovies(records);
		cout << endl;
		do
		{
			//present the menu until the person select the Q option

			PrintMenu(option);
			GetMenuOption(option);

			if (verifyOption(option))
			{
				cout << "Please chose one of the options from the menu." << endl << endl;
				continue;
			}
			else
			{
				//You need to be able to call a specific function in a derived class
				// not just the main class. 
				//movie.LoadMovies(records);
				//change this to switch statement for option
				if (option == 'M')
				{
					//movie.PrintMovieList();
					cout << endl;
				}
				if (option == 'S')
				{
					//movie.GetStarsByMovie();
					cout << endl;
				}
				if (option == 'F')
				{
					//movie.GetMoviesByStar();
					cout << endl;
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
    
}

bool verifyOption(char& option)
{
	bool cleanOption = false;
	if (option != 'm' && option != 'M' && option != 's' && option != 'S' && 
		option != 'f' && option != 'F' && option != 'q' && option != 'Q' &&
		option != 'b' && option != 'B' && option != 'a' && option != 'A' &&
		option != 'G' && option != 'g' && option != 't' && option != 'T')
	{
		cleanOption = false;
	}
	else
	{
		cleanOption = true;
	}
	return cleanOption;
}

void PrintMenu(char& option)
{
	cout << setw(20);
	cout << "MENU CHOICES" << endl;
	cout << "M = Print movie list" << endl;
	cout << "B = Print book list" << endl;
	cout << "S = Print song list" << endl;
	cout << "A = Print All Media" << endl;
	cout << "S - Print stars for a given movie" << endl;
	cout << "F - Search for movies based by star" << endl;
	cout << "T = Print Media Counts" << endl;
	cout << "Q - End application" << endl;

}

void GetMenuOption(char& option)
{
	cout << endl << "Option: ";
	cin >> option;
	cout << endl;
	cin.clear();
	option = toupper(option);
}