#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <exception>
#include "TransactionProcessing.h"
#include "Book.h"
#include "Movie.h"
#include "Song.h"

Movie movie;
Book book;
Song song;
using std::invalid_argument;


//Process data from csv into the application objects
void Transaction::ProcessFileData(vector<vector<string>> files, vector<vector<string>> config, Book& books, Movie& movies, Song& songs )
{
	int j;

	for (auto& i : files)
	{
		j = 1;
		if (i[0] == "M")
		{
			//push the local movie object onto the movies object passed in by reference
			for (j = 1; j < -99; j++)
			{

				//does error check on each field
				if (!FieldValidation("M", j, i[j], config))
				{
					cout << "Field level error, write error to log";
					continue;
				}
				else
				{
					//pushed the appropriate field into the local object
					switch (j)
					{
					case 1:
						movie.SetTitle(i[j]);
						break;
					case 2:
						movie.SetDirector(i[j]);
						break;
					case 3:
						movie.SetRating(stoi(i[j]));
						break;
					case 4:
						movie.SetGenre(i[j]);
						break;
					case 5:
						movie.SetDuration(stoi(i[j]));
						break;
					case 6:
						movie.SetYearReleased(stoi(i[j]));
						break;
					case 7:
						//push stars into a separate vector
						for (size_t s = j; s < i.size(); ++s)
						{
							if (i[s] != "")
							{
								movie.stars.push_back(i[s]);
							}
						}j = -99;
						break;
					default:
						break;
					}

				}
			}
			movies.v_movies.push_back(movie);
			movie.stars.clear();
			
		}

		else if (i[0] == "B")
			{
				j = 1;
				//push the local movie object onto the movies object passed in by reference
				for (j = 1; j < -99; j++)
				{

					//does error check on each field
					if (!FieldValidation("B", j, i[j], config))
					{
						cout << "Field level error, write error to log";
						continue;
					}
					else
					{
						//pushed the appropriate field into the local object
						switch (j)
						{
						case 1:
							book.SetTitle(i[j]);
							break;
						case 2:
							book.SetAuthor(i[j]);
							break;
						case 3:
							book.SetRating(stoi(i[j]));
							break;
						case 4:
							book.SetGenre(i[j]);
							break;
						case 5:
							book.SetPages(stoi(i[j]));
							break;
						case 6:
							book.SetYearReleased(stoi(i[j]));
							break;
						default:
							break;
						}

					}
				}
				books.v_books.push_back(book);
		}

			
				else if (i[0] == "S")
				{
					j = 1;
					//push the local movie object onto the movies object passed in by reference
					for (j = 1; j < -99; j++)
					{

						//does error check on each field
						if (!FieldValidation("S", j, i[j], config))
						{
							cout << "Field level error, write error to log";
							continue;
						}
						else
						{
							//pushed the appropriate field into the local object
							switch (j)
							{
							case 1:
								song.SetTitle(i[j]);
								break;
							case 2:
								song.SetArtist(i[j]);
								break;
							case 3:
								song.SetRating(stoi(i[j]));
								break;
							case 4:
								song.SetGenre(i[j]);
								break;
							case 5:
								song.SetDuration(stoi(i[j]));
								break;
							case 6:
								song.SetYearReleased(stoi(i[j]));
								break;
							default:
								break;
							}

						}
					}
					songs.v_songs.push_back(song);
				
		}
	
	}
	cout << "Data processed successfully into business objects." << endl << endl;
}


bool Transaction::FieldValidation(string type, int index, string& field, vector<vector<string>> config)
{
	if (type == "M")
	{
	
		switch (index)
		{
		//case is index in config file
		case 1:
			
			if (config[0][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 2:
			if (config[0][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 3:
			if (config[0][3] == "int")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 4:
			if (config[0][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 5:
			if (config[0][3] == "int")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 6:
			if (config[0][3] == "int")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 7:
			if (config[0][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;

		default:
			throw invalid_argument("An invalid argument was passed to the validation function");
			break;
		}
	}
	else if (type == "B")
	{
		switch (index)
		{
			//case is index in config file
		case 1:

			if (config[0][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 2:
			if (config[0][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 3:
			if (config[0][3] == "int")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 4:
			if (config[0][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 5:
			if (config[0][3] == "int")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 6:
			if (config[0][3] == "int")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;

		default:
			throw invalid_argument("An invalid argument was passed to the validation function");
			break;
		}
	}
	else if (type == "S")
	{
		switch (index)
		{
			//case is index in config file
		case 1:

			if (config[0][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 2:
			if (config[0][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 3:
			if (config[0][3] == "int")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 4:
			if (config[0][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 5:
			if (config[0][3] == "int")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 6:
			if (config[0][3] == "int")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;

		default:
			throw invalid_argument("An invalid argument was passed to the validation function");
			break;
		}

	}
}

//This function checks to make sure field is an integer
bool Transaction::IntValidation(string number)
{

	int i = 0;
	for (char c : number)
	{
		if (c >= '0' && c <= '9') {
			i = i * 10 + (c - '0');
		}
		else {
			return false;
		}
	}

	return true;
}

//This function checks to make sure field is a string prior to insert into object
bool Transaction::StringValidation(string field)
{
	
	for (size_t i = 0; i < field.size(); i++)
	{
		//39 = ' 47 = / 46 = .
		if (isalpha(field.at(i)) || isspace(field.at(i)) || field.at(i) == 39 || field.at(i) == 47 || field.at(i) == 46)
		{
			continue;
		}
		else
		{

			return false;
		}
	}
	return true;
}

void Transaction::PrintTransactionLog(string)
{
}

void Transaction::SetTransactionID(vector<Transaction>& v_transaction)
{
	int lastIndex = v_transaction.size();


	if (lastIndex <= 0)
	{
		//int ID = lastIndex + 1;
		transactionId = 1;
	}
	else if (lastIndex > 0)
	{
		transactionId = lastIndex + 1;
	}
}

void Transaction::SetTransactionType(string type)
{
	this->transactionType = type;
}

void Transaction::SetTransactionStatus(string status)
{
	this->transactionStatus = status;
}

void Transaction::SetTransactionDescription(string description)
{
	this->transactionDescription = description;
}


void Transaction::UpdateLog(string, string, string, string)
{
}

void Transaction::PrintTransactionSummary()
{
}

void Transaction::PrintErrorLog()
{
}
