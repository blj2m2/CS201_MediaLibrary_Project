
#include <iostream>
#include <exception>
#include <vector>

using namespace std;
vector<vector<string>>& v_records;

int main()
{
	try
	{
		std::cout << "Hello World!\n";
	}
	catch (runtime_error& e)
	{
		cout << e.what();
	}
	catch (invalid_argument& e)
	{
		cout << e.what();
	}
    
}

