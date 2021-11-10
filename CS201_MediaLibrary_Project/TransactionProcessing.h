#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include "Movie.h"
#include "Song.h"

using namespace std;


class Transaction
{
private:
	int transactionId;
	string transactionType;
	string transactionStatus;
	string transactionDescription;
	string transactionRawData;
	//Add data fields for mediaFile tracking in transaction log
	

	//vector used to stor all transactions that occur during processing
	vector<Transaction> transactions;
	
	//validate the integer value for content
	bool IntValidation(string);

	//validate the double value for account
	bool StringValidation(string);

	//function to print error or full log
	void PrintTransactionLog(string);

public:

	Transaction()
	{
		transactionId = 0;
		transactionType = "N/A";
		transactionStatus = "Pending";
		transactionDescription = "N/A";
		transactionRawData = "N/A";
	
	}


	void SetTransactionID(vector<Transaction>& v_transaction);
	void SetTransactionType(string);
	void SetTransactionStatus(string);
	void SetTransactionDescription(string);

	//Process each line individually and parse out content taking action on each line
	void ProcessFileData(vector<vector<string>>, vector<vector<string>>, Book&, Movie&, Song&);

	bool FieldValidation(string, int, string&, vector<vector<string>> config);

	//write values to the transaction log
	void UpdateLog(string, string, string, string);

	//output the full list of all transactions, screen and file
	void PrintTransactionSummary();

	//output the fill list of errors from within the transactions vector
	void PrintErrorLog();





};

