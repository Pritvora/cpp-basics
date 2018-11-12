#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main()
{
	string str;
	string newStr = "";
	char prop[] = { ' ', '.', ':', ';', '?', ',' };

	ifstream file("text.txt");
	if (!file.is_open())
	{
		cout << "Error!!!\n" << endl;
		return 0;
	}
	else {


		while (file) {
			getline(file, str);
			str += " ";
			int prevSpace = -1,
				firstSpace = (int )str.find(' '),
				secondSpace =(int)str.find(' ', firstSpace + 1);
			while (firstSpace != -1 && secondSpace != -1)
			{
				string a1 = "", a2 = "";
				for (int i = 0; i < 6; i++)
				{
					if (str[firstSpace - 1] == prop[i])
					{
						a1 += prop[i];
						firstSpace--;
					}
					if (str[secondSpace - 1] == prop[i])
					{
						a2 += prop[i];
						secondSpace--;
					}
				}
				int off1 = 1;
				if (str[firstSpace + off1] == ' ')
					off1 = 2;
				int off2 = 1;
				if (str[prevSpace + off2] == ' ')
					off2 = 2;
				newStr += str.substr(firstSpace + off1, secondSpace - firstSpace - off1) + a1 + " "  ;
				newStr += str.substr(prevSpace + off2, firstSpace - prevSpace - off2) + a2 + " ";
				prevSpace = secondSpace,
					firstSpace = (int)str.find(' ', secondSpace + 2);
				secondSpace = (int)str.find(' ', firstSpace + 2);
			}
			
			if (firstSpace != -1)
			{
				newStr += str.substr(prevSpace + 1, firstSpace - prevSpace);
			}
			newStr += "\r\n";
			cout << str<<endl;
		}
	

		cout <<endl<< newStr;
		file.close();

		return 0;
	}
}