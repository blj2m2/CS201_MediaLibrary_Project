#include <iostream>
#include <sstream>
#include <exception>
#include <limits>
#include <fstream>
#include "DataReader.h"
#include "rapidxml-1.13/rapidxml.hpp"


using namespace std;
using namespace rapidxml;



//function used to import all data in the csv file and load it into a vector of vectors.
void DataReader::OpenFile(string fileName, vector<vector<string>>& v_records)
{
	ifstream inSS;
	inSS.open(fileName, ios::in);
	if (!inSS)
	{
		throw runtime_error("Unable to Read file, please run Import process again.");
	}
	vector<string> row;
	string line, field;
	while (getline(inSS, line))
	{
		//clear each row prior to reading values into it
		row.clear();
		stringstream s(line);
		while (getline(s, field, ','))
		{
			row.push_back(field);
		}
		records.push_back(row);
	}inSS.close();

	cout << "Import successful" << endl;
	v_records = records;

	cout << v_records.size() << " records imported. Files still need to be processed." << endl;
	
}


//function used to get the file path and check that the entry is correct
void DataReader::ImportFile(vector<vector<string>>& v_records)
{
	cout << "Please enter the file name that should be used for Import (ex. medialist.csv):  ";
	if (!cin)
	{
		throw runtime_error("The file name or path you entered was incorrect.");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (cin)
	{
		cin >> fileName;
	}

	OpenFile(fileName, v_records);



}


void DataReader::importFileConfig(vector < vector<string>>& importConfig)
{
	xml_document<> doc;
	xml_node<>* root_node;
	vector<string> fieldConfig;
	// Read the xml file into a vector
	ifstream configFile;
	configFile.open("csv_config.xml", ios::in);
	if (!configFile)
	{
		throw runtime_error("Unable to Read file, please run Import process again.");
	}
	else
	{
		vector<char> buffer((istreambuf_iterator<char>(configFile)), istreambuf_iterator<char>());
		buffer.push_back('\0');
		// Parse the buffer using the xml file parsing library into doc 
		doc.parse<0>(&buffer[0]);
		// Find our root node
		root_node = doc.first_node("MediaLibraryData");
		for (xml_node<>* media_node = root_node->first_node("Media"); media_node; media_node = media_node->next_sibling())
		{
			

			for (xml_node<>* field_node = media_node->first_node("Field"); field_node; field_node = field_node->next_sibling())
			{
				fieldConfig.push_back(media_node->first_attribute("media_type")->value());
				fieldConfig.push_back(field_node->first_attribute("name")->value());
				fieldConfig.push_back(field_node->first_attribute("dataType")->value());
				importConfig.push_back(fieldConfig);
				fieldConfig.clear();
			}
		}
	}


	cout << "Configuration file loaded successfully" << endl;
	
}

