#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Transaction
{
private:
	int transactionId;
	string transactionType;
	string transactionStatus;
	string transactionDescription;
	//Add data fields for mediaFile tracking in transaction log
	

	//vector used to stor all transactions that occur during processing
	vector<Transaction> transactions;
	
	//validate the integer value for content
	int IntValidation(string);

	//validate the double value for account
	string StringValidation(string);

	//function to print error or full log
	void PrintTransactionLog(string);

public:

	Transaction()
	{
		transactionId = 0;
		transactionType = "N/A";
		transactionStatus = "Pending";
		transactionDescription = "N/A";
	
	}
	Transaction(int transactionId)
	{
		//pass in the transactionID of the last index + 1
		//increment transactionID with each new transaction
		this->transactionId = transactionId + 1;
	}

	void SetTransactionID(vector<Transaction>& v_transaction);
	void SetTransactionType(string);
	void SetTransactionStatus(string);
	void SetTransactionDescription(string);

	//Process each line individually and parse out content taking action on each line
	void ProcessFileData(vector<vector<string>>, vector<vector<string>>);

	//write values to the transaction log
	void UpdateLog(string, string, string, string);

	//output the full list of all transactions, screen and file
	void PrintTransactionSummary();

	//output the fill list of errors from within the transactions vector
	void PrintErrorLog();





};

