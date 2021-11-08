#pragma once
#include <iostream>
#include <vector>

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
	void OpenFile(string, vector<vector<string>>&);

public:
	DataReader()
	{
		fileName = "N/A";
	}

	//single function to import and store strings into a vector
	void ImportFile(vector<vector<string>>&);
	void importFileConfig(vector<vector<string>>&);


};


