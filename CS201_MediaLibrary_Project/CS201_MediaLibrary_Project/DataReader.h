#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include "Movie.h"
#include "Song.h"

using std::vector;
using std::string;

/*
The purpose of this content is to retrieve file content, break it
down into strings and load it into a vector to be parsed
*/

class DataReader
{
private:
	vector<vector<string>> records;
	string fileName;
	

public:
	DataReader()
	{
		fileName = "N/A";
	}

	//single function to import and store strings into a vector
	void ImportFile(vector<vector<string>>&, string&);
	void ImportFile(vector<vector<string>>&);
	void importFileConfig(vector<vector<string>>&);
	void OpenFile(string fileName, vector<vector<string>> v_records, int transactionID, Book& book, Movie& movie, Song& song);
	string OpenFile(string fileName, vector<vector<string>>& v_records);


};


