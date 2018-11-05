#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("text.txt");
	if (in.is_open())
	{
		
	}
	else
	{
		cout << "File not found.";
		return(0);
	}
	return 0;
}