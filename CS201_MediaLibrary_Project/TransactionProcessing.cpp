#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "TransactionProcessing.h"
#include "Book.h"
#include "Movie.h"
#include "Song.h"

Book books;
Movie movies;
Song songs;
Transaction obj_transaction;

//Process data from csv into the application objects
void Transaction::ProcessFileData(vector<vector<string>> files, vector<vector<string>> config)
{
	for (auto& i : files)
	{
		if (i[0] == "M")
		{
			
			
		}
		else if (i[0] == "B")
		{

		}
		else if (i[0] == "S")
		{

		}
	
	}

}



int Transaction::IntValidation(string)
{
    return 0;
}

string Transaction::StringValidation(string)
{
    return "";
}

void Transaction::PrintTransactionLog(string)
{
}

void Transaction::SetTransactionID(vector<Transaction>& v_transaction)
{
}

void Transaction::SetTransactionType(string)
{
}

void Transaction::SetTransactionStatus(string)
{
}

void Transaction::SetTransactionDescription(string)
{
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
