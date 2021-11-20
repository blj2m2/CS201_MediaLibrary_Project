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
#include <time.h>
#include <stdio.h>

Movie movie;
Book book;
Song song;
Transaction l_objTransaction;
using namespace std;


//Process data from csv into the application objects
void Transaction::ProcessFileData(vector<vector<string>> files, vector<vector<string>> config, Book& books, Movie& movies, Song& songs )
{
	int j = 0;
	string type;
	for (auto& i : files)
	{
		j = 1;
		try
		{
			if (i[0] == "M")
			{
				type = "Movie";
				//push the local movie object onto the movies object passed in by reference
				for (j = 1; j < 99; j++)
				{
					//does error check on each field
					if (!FieldValidation("M", j, i[j], config))
					{
						throw invalid_argument("Invalid Argument");
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
							}
							break;
						default:
							j = 99;
							break;
						}
						
					}

				}
				movies.v_movies.push_back(movie);
				AddTransactionToLog(movie, type);
				movie.stars.clear();

			}

			else if (i[0] == "B")
			{
				j = 1;
				type = "Book";
				//push the local movie object onto the movies object passed in by reference
				for (j = 1; j < 99; j++)
				{

					//does error check on each field
					if (!FieldValidation("B", j, i[j], config))
					{
						throw invalid_argument("Invalid Argument");
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
							j = 99;
							break;
						}
						
					}
				}
				books.v_books.push_back(book);
				AddTransactionToLog(book, type);
			}


			else if (i[0] == "S")
			{
				j = 1;
				type = "Song";
				//push the local movie object onto the movies object passed in by reference
				for (j = 1; j < 99; j++)
				{

					//does error check on each field
					if (!FieldValidation("S", j, i[j], config))
					{
						throw invalid_argument("Invalid Argument");
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
							j = 99;
							break;
						}
						
					}
				}
				songs.v_songs.push_back(song);
				AddTransactionToLog(song, type);

			}
		}
		catch (invalid_argument& e)
		{
			if (i[0] == "B")
			{
				string error;
				error = "Book: " + i[1] + " - ";
				error += e.what();
			
				AddTransactionErrorToLog(book, "Book", error);
				//cout << book.GetTitle() << " record processing produced error. " << e.what() << endl;
			}
			else if (i[0] == "M")
			{
				string error;
				error = "Movie: " + i[1] + " - ";
				error += e.what();
				AddTransactionErrorToLog(movie, "Movie", error);
				//cout << movie.GetTitle() << " record processing produced error. " << e.what() << endl;
			}
			else if (i[0] == "S")
			{
				string error;
				error = "Song: " + i[1] + " - ";
				error += e.what();
				AddTransactionErrorToLog(song, "Song", error);
				//cout << song.GetTitle() << " record processing produced error. " << e.what() << endl;
			}
			
		}
		catch (runtime_error& e)
		{
			if (i[0] == "B")
			{
				cout << book.GetTitle() << " record processing produced error. " << e.what() << " - Error" << endl;
			}
			else if (i[0] == "M")
			{
				cout << movie.GetTitle() << " record processing produced error. " << e.what() << " - Error" << endl;
			}
			else if (i[0] == "S")
			{
				cout << song.GetTitle() << " record processing produced error. " << e.what() << " - Error" << endl;
			}
			
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
			if (config[1][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 3:
			if (config[2][3] == "int")
			{
				
				
				
				return IntValidation(field);
			}
			else
			{
				return StringValidation(field);
			}
			break;
		case 4:
			if (config[3][3] == "string")
			{
				
				
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 5:
			if (config[4][3] == "int")
			{
				
				return IntValidation(field);
			}
			else
			{
				return StringValidation(field);
			}
			break;
		case 6:
			if (config[5][3] == "int")
			{
				
				return IntValidation(field);
			}
			else
			{
				return StringValidation(field);
			}
			break;
		case 7:
			if (config[6][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;

		default:
			break;
		}
	}
	else if (type == "B")
	{
		switch (index)
		{
			//case is index in config file
		case 1:

			if (config[7][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 2:
			if (config[8][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 3:
			if (config[9][3] == "int")
			{
			
				return IntValidation(field);
			}
			else
			{
				return StringValidation(field);
			}
			break;
		case 4:
			if (config[10][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 5:
			if (config[11][3] == "int")
			{
				
				return IntValidation(field);
			}
			else
			{
				return StringValidation(field);
			}
			break;
		case 6:
			if (config[12][3] == "int")
			{
				
				return IntValidation(field);
			}
			else
			{
				return StringValidation(field);
			}
			break;

		default:
			break;
		}
	}
	else if (type == "S")
	{
		switch (index)
		{
			//case is index in config file
		case 1:

			if (config[13][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 2:
			if (config[14][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 3:
			if (config[15][3] == "int")
			{
				
				
				
				return IntValidation(field);
			}
			else
			{
				return StringValidation(field);
			}
			break;
		case 4:
			if (config[16][3] == "string")
			{
				return StringValidation(field);
			}
			else
			{
				return IntValidation(field);
			}
			break;
		case 5:
			if (config[17][3] == "int")
			{
			
				return IntValidation(field);
			}
			else
			{
				return StringValidation(field);
			}
			break;
		case 6:
			if (config[18][3] == "int")
			{
				
				return IntValidation(field);
			}
			else
			{
				return StringValidation(field);
			}
			break;

		default:
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
			//write error to log for that specific record - stoi error
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
			//write to the log for this specific error - string validation error
			return false;
		}
	}
	return true;
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
	//could be used for an update function
}

void Transaction::PrintTransactionSummary()
{

	cout << setw(50);
	cout << "Transaction Listing" << endl;
	cout << "Movies:" << endl;
		cout << setw(15) << "Transaction ID " << setw(20) << "Transaction Type " << setw(25) << "Transaction Status " << setw(47) << "Transaction Desc. " << setw(27) << "Transaction Date/Time " << endl;
	for (auto& i : v_transaction)
	{
		if (i.transactionType == "Movie" && i.transactionStatus != "Error")
		{
			cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(47) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
		}
	}
	cout << endl;
	cout << "Books:" << endl;
	cout << setw(15) << "Transaction ID" << setw(20) << "Transaction Type" << setw(25)<< "Transaction Status" << setw(47) << "Transaction Desc." << setw(27) << "Transaction Date/Time" << endl;
	for (auto& i : v_transaction)
	{
		if (i.transactionType == "Book" && i.transactionStatus != "Error")
		{
			cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(47) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
		}
	}
	cout << endl;
	cout << "Songs:" << endl;
	cout << setw(15) << "Transaction ID" << setw(20) << "Transaction Type" << setw(25) << "Transaction Status" << setw(47) << "Transaction Desc." << setw(27) << "Transaction Date/Time" << endl;
	for (auto& i : v_transaction)
	{
		if (i.transactionType == "Song" && i.transactionStatus != "Error")
		{
			cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(47) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
		}
	}
}

void Transaction::PrintErrorLog()
{
	
	cout << setw(50);
	cout << "Transaction Error Log" << endl;
	cout << "Movies:" << endl;
	cout << setw(15) << "Transaction ID" << setw(20) << "Transaction Type" << setw(25) << "Transaction Status" << setw(67) << "Transaction Desc." << setw(27) << "Transaction Date/Time" << endl;
	for (auto& i : v_transaction)
	{
		if (i.transactionType == "Movie" && i.transactionStatus == "Error")
		{
			cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(67) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
		}
	}
	cout << endl;
	cout << "Books:" << endl;
	cout << setw(15) << "Transaction ID" << setw(20) << "Transaction Type" << setw(25) << "Transaction Status" << setw(67) << "Transaction Desc." << setw(27) << "Transaction Date/Time" << endl;
	for (auto& i : v_transaction)
	{
		if (i.transactionType == "Book" && i.transactionStatus == "Error")
		{
			cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(67) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
		}
	}
	cout << endl;
	cout << "Songs:" << endl;
	cout << setw(15) << "Transaction ID" << setw(20) << "Transaction Type" << setw(25) << "Transaction Status" << setw(67) << "Transaction Desc." << setw(27) << "Transaction Date/Time" << endl;
	for (auto& i : v_transaction)
	{
		if (i.transactionType == "Song" && i.transactionStatus == "Error")
		{
			cout << setw(14) << i.transactionId << setw(20) << i.transactionType << setw(25) << i.transactionStatus << setw(67) << i.transactionDescription << setw(27) << i.transactionDateTime << endl;
		}
	}

}

//overloaded Push to Error Log for Movies
void Transaction::AddTransactionErrorToLog(Movie& movie, string type, string error)
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	string rawData;
	movie.GetSingleRecord(rawData);
	l_objTransaction.transactionId = v_transaction.size() + 1;
	l_objTransaction.transactionType = type;
	l_objTransaction.transactionStatus = "Error";
	l_objTransaction.transactionDescription = error;
	l_objTransaction.transactionRecord = rawData;
	l_objTransaction.transactionDateTime = to_string(timeinfo.tm_mon + 1) + "." + to_string(timeinfo.tm_mday) + "." + to_string(1900 + timeinfo.tm_year)
		+ " - " + to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
	v_transaction.push_back(l_objTransaction);
}

//overloaded Push to Error Log for Books
void Transaction::AddTransactionErrorToLog(Book& book, string type, string error)
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	string rawData;
	book.GetSingleRecord(rawData);
	l_objTransaction.transactionId = v_transaction.size() + 1;
	l_objTransaction.transactionType = type;
	l_objTransaction.transactionStatus = "Error";
	l_objTransaction.transactionDescription = error;
	l_objTransaction.transactionRecord = rawData;
	l_objTransaction.transactionDateTime = to_string(timeinfo.tm_mon + 1) + "." + to_string(timeinfo.tm_mday) + "." + to_string(1900 + timeinfo.tm_year)
		+ " - " + to_string(timeinfo.tm_hour)	+ ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);

	v_transaction.push_back(l_objTransaction);
}

//overloaded Push to Error Log for Songs
void Transaction::AddTransactionErrorToLog(Song& song, string type, string error)
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	string rawData;
	song.GetSingleRecord(rawData);
	l_objTransaction.transactionId = v_transaction.size() + 1;
	l_objTransaction.transactionType = type;
	l_objTransaction.transactionStatus = "Error";
	l_objTransaction.transactionDescription = error;
	l_objTransaction.transactionRecord = rawData;
	l_objTransaction.transactionDateTime = to_string(timeinfo.tm_mon + 1) + "." + to_string(timeinfo.tm_mday) + "." + to_string(1900 + timeinfo.tm_year)
		+ " - " + to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
	v_transaction.push_back(l_objTransaction);
}

//Overloaded function for Adding a movie to the transaction log
void Transaction::AddTransactionToLog(Movie& movie, string type)
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	string rawData;
	movie.GetSingleRecord(rawData);
	l_objTransaction.transactionId = v_transaction.size()+1;
	l_objTransaction.transactionType = type;
	l_objTransaction.transactionStatus = "Successful";
	l_objTransaction.transactionDescription = movie.GetTitle();
	l_objTransaction.transactionRecord = rawData;
	l_objTransaction.transactionDateTime = to_string(timeinfo.tm_mon + 1) + "." + to_string(timeinfo.tm_mday) + "." + to_string(1900 + timeinfo.tm_year)
		+ " - " + to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
	v_transaction.push_back(l_objTransaction);
}

//Overloaded function for Adding a song to the transaction log
void Transaction::AddTransactionToLog(Song& song, string type)
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	string rawData;
	song.GetSingleRecord(rawData);
	l_objTransaction.transactionId = v_transaction.size() + 1;
	l_objTransaction.transactionType = type;
	l_objTransaction.transactionStatus = "Successful";
	l_objTransaction.transactionDescription = song.GetTitle();
	l_objTransaction.transactionRecord = rawData;
	l_objTransaction.transactionDateTime = to_string(timeinfo.tm_mon + 1) + "." + to_string(timeinfo.tm_mday) + "." + to_string(1900 + timeinfo.tm_year)
		+ " - " + to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
	v_transaction.push_back(l_objTransaction);

}

//Overloaded function for Adding a book to the transaction log
void Transaction::AddTransactionToLog(Book& book, string type)
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	string rawData;
	book.GetSingleRecord(rawData);
	l_objTransaction.transactionId = v_transaction.size() + 1;
	l_objTransaction.transactionType = type;
	l_objTransaction.transactionStatus = "Successful";
	l_objTransaction.transactionDescription = book.GetTitle();
	l_objTransaction.transactionRecord = rawData;
	l_objTransaction.transactionDateTime = to_string(timeinfo.tm_mon + 1) + "." + to_string(timeinfo.tm_mday) + "." + to_string(1900 + timeinfo.tm_year)
		+ " - " + to_string(timeinfo.tm_hour) + ":" + to_string(timeinfo.tm_min) + ":" + to_string(timeinfo.tm_sec);
	v_transaction.push_back(l_objTransaction);

}



