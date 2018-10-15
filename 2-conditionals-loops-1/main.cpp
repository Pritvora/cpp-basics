#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	double a, b, c, xn, xk, dx, F;
	const double kEps = 1e-15;
	cout << "Enter a=";
	cin >> a;
	cout << "Enter b=";
	cin >> b;
	cout << "Enter c=";
	cin >> c;
	cout << "Enter xn=";
	cin >> xn;
	cout << "Enter xk=";
	cin >> xk;
	cout << "Enter dx=";
	cin >> dx;
	if (dx < kEps) {
		cout << "ERROR" << string(10, ' ') << "NEED: dx>kEps\n";
	}
	else {
		cout << "|" << string(15, '\xc4') << "|";
		cout << string(15, '\xc4') << "|\n";

		cout << "|" << setw(8) << "x" << setw(8) << "|";
		cout << setw(8) << "F" << setw(9) << "|\n";

		cout << "|" << string(15, '\xc4') << "|";
		cout << string(15, '\xc4') << "|\n";
		for (double x = xn; x <= xk; x += dx) {

			if ((x < 0) && (abs(b) > kEps)) {
				if (abs(10 + b) < kEps) {
					cout << "ERROR: 10+b!=0";
				}
				else {
					F = a - (x / (10 + b));
				}
			}
			if ((x > 0) && (abs(b) < kEps)) {
				if (abs(x - c) < kEps) {
					cout << "ERROR: x-c!=0";
				}
				else {
					F = (x - a) / (x - c);
				}
			}
			else {
				if (abs(c) < kEps) {
					cout << "ERROR: c!=0";
				}
				else {
					F = 3 * x + 2 / c;
				}
			}
			if (((int(a) | int(b)) & int(c)) != 0) {

				cout << "|" << setw(8) << x << setw(8) << "|";
				cout << setw(8) << F << setw(9) << "|\n";
			}
			else {

				cout << "|" << setw(8) << x << setw(8) << "|" << setw(8);
				cout << int(F) << setw(9) << "|\n";
			}
			cout << "|" << string(15, '\xc4') << "|";
			cout << string(15, '\xc4') << "|\n";
		}
	}
	return 0;
}

