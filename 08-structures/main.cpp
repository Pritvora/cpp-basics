#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int n = 7;

struct Aeroflot
{
	string destination, type;
	int number;
};

int main()
{
	Aeroflot samolet[n];

	for (int i = 0; i < 7; i++)
	{
		cout << "\n Enter destination: ";
		cin >> samolet[i].destination;
		cout << "\n Enter flight number: ";
		cin >> samolet[i].number;
		cout << "\nEnter aircraft type: ";
		cin >> samolet[i].type;
		cout << "\n----------------------------------\n";
	}

	string type;
	cout << "What TYPE of aircraft do you want to fly?:";
	cin >> type;
	cout << "\n";
	Aeroflot p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (samolet[j].destination > samolet[j + 1].destination) {
				p = samolet[j + 1];
				samolet[j + 1] = samolet[j];
				samolet[j] = p;
			}

		}
	}


	bool samtype = false;
	
	for (int i = 0; i < n; i++) {

		if (samolet[i].type == type) {
			samtype = true;
			cout << "Destination-number\n";
			cout << samolet[i].destination << " - ";
			cout << samolet[i].number;
			cout << endl;


		}

	}
	if (samtype == false) {
		cout << "No planes !";
	}


	return 0;
}