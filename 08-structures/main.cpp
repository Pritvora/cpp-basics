#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Aeroflot {
	string destination, plane_type;
	int flight_number;
};

void InputPlanes(Aeroflot* planes, const int kNumPlanes);
void SortPlanes(Aeroflot* planes, const int kNumPlanes);
void PrintPlanes(Aeroflot* planes, const int kNumPlanes);
void FindPlanes(Aeroflot* planes, const int kNumPlanes, string plane_type);

int main() {
	const int kNumPlanes = 2;
	Aeroflot planes[kNumPlanes];

	InputPlanes(planes, kNumPlanes);
	SortPlanes(planes, kNumPlanes);
	PrintPlanes(planes, kNumPlanes);
	cout << string(34, '=') << endl;

	string plane_type;
	cout << "\nWhat type of aircraft do you want to fly?: ";
	cin >> plane_type;
	FindPlanes(planes, kNumPlanes, plane_type);

	return 0;
}

void InputPlanes(Aeroflot* planes, const int kNumPlanes) {
	for (int i = 0; i < kNumPlanes; i++) {
		cout << "Enter destination: ";
		getline(cin, planes[i].destination);
		cout << "Enter flight number: ";
		cin >> planes[i].flight_number;
		cin.ignore();
		cout << "Enter aircraft type: ";
		getline(cin, planes[i].plane_type);
		cout << endl << string(34, '-') << endl << endl;
	}
}

void SortPlanes(Aeroflot* planes, const int kNumPlanes) {
	for (int i = 0; i < kNumPlanes - 1; i++)
		for (int j = 0; j < kNumPlanes - i - 1; j++)
			if (planes[j].destination > planes[j + 1].destination)
				swap(planes[j], planes[j + 1]);
}

void PrintPlanes(Aeroflot* planes, const int kNumPlanes) {
	for (int i = 0; i < kNumPlanes; i++) {
		cout << "Destination: " << planes[i].destination;
		cout << "\nflight number: " << planes[i].flight_number;
		cout << "\naircraft type: " << planes[i].plane_type << endl << endl;
	}
}

void FindPlanes(Aeroflot* planes, const int kNumPlanes, string plane_type) {
	bool is_found = false;
	for (int i = 0; i < kNumPlanes; i++) {
		if (planes[i].plane_type == plane_type) {
			is_found = true;
			cout << "\nDestination: " << planes[i].destination;
			cout << "\nflight number: " << planes[i].flight_number << endl;
		}
	}
	if (!is_found)
		cout << "No planes!\n";
}
