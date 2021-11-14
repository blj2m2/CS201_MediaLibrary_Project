#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include "Movie.h"
#include "Song.h"
#include "MediaFile.h"

using namespace std;


class Transaction
{
private:
	int transactionId;
	string transactionType;
	string transactionStatus;
	string transactionDescription;
	string transactionRecord;
	string transactionDateTime;

	//vector used to stor all transactions that occur during processing

	
	//validate the integer value for content
	bool IntValidation(string);

	//validate the double value for account
	bool StringValidation(string);




public:

	Transaction()
	{
		transactionId = 0;
		transactionType = "N/A";
		transactionStatus = "Pending";
		transactionDescription = "N/A";
		transactionRecord = "N/A";
	}


	
	void SetTransactionType(string);
	void SetTransactionStatus(string);
	void SetTransactionDescription(string);
	vector<Transaction> v_transaction;


	//Process each line individually and parse out content taking action on each line
	void ProcessFileData(vector<vector<string>>, vector<vector<string>>, Book&, Movie&, Song&);

	bool FieldValidation(string, int, string&, vector<vector<string>> config);

	//write values to the transaction log
	void UpdateLog(string, string, string, string);

	//output the full list of all transactions, screen and file
	void PrintTransactionSummary();

	//output the fill list of errors from within the transactions vector
	void PrintErrorLog();

	void AddTransactionErrorToLog(Movie&, string, string);

	void AddTransactionErrorToLog(Book&, string, string);

	void AddTransactionErrorToLog(Song&, string, string);


	void AddTransactionToLog(Movie&, string);

	void AddTransactionToLog(Song&, string);

	void AddTransactionToLog(Book&, string);





};



