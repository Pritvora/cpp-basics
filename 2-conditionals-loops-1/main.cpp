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
	if (dx<kEps) {
		cout << "ERROR" << string(10, ' ') << "NEED: dx>kEps" << endl;
	}
	else {
		cout << "|" << setw(1) << string(15, '\xc4') << setw(1) << "|" << setw(1) << string(15, '\xc4') << setw(1) << "|" << endl;

		cout << "|" << setw(8) << "x" << setw(8) << "|" << setw(8) << "F" << setw(8) << "|" << endl;

		cout << "|" << setw(1) << string(15, '\xc4') << setw(1) << "|" << setw(1) << string(15, '\xc4') << setw(1) << "|" << endl;
		for (double x = xn; x <= xk; x += dx) {
	
			if ((x < 0) && (abs(b) > kEps&&(abs(10 + b) > kEps))) {
				F = a - (x / (10 + b));
			}
			if ((x > 0) && (abs(b) < kEps)&& (abs(x - c) > kEps)) {
				F = (x - a) / (x - c);
			}
			else if((abs(c) > kEps)) {
				F = 3 * x + 2 / c;
			}
			if (((int(a) | int(b)) & int(c)) != 0) {

				cout << "|" << setw(8) << x << setw(8) << "|" << setw(8) << F << setw(8) << "|" << endl;
			}
			else {

				cout << "|" << setw(8) << x << setw(8) << "|" << setw(8) << int(F) << setw(8) << "|" << endl;
			}
			cout << "|" << setw(1) << string(15, '\xc4') << setw(1) << "|" << setw(1) << string(15, '\xc4') << setw(1) << "|" << endl;
		}
	}
	return 0;
}

