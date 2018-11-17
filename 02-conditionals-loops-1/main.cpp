#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	const double kEps = 1e-15;

	double a, b, c, xn, xk, dx;
	cout << "Enter a = ";
	cin >> a;
	cout << "Enter b = ";
	cin >> b;
	cout << "Enter c = ";
	cin >> c;
	cout << "Enter xn = ";
	cin >> xn;
	cout << "Enter xk (xk >= xn) = ";
	cin >> xk;
	cout << "Enter dx (dx > 0) = ";
	cin >> dx;

	if (dx <= 0) {
		cout << "\nError. Need: dx > 0.\n";
	}
	else if (xn > xk) {
		cout << "\nError. Need: xk >= xn.\n";
	}
	else {
		cout << "|" << string(15, '\xc4');
		cout << "|" << string(15, '\xc4') << "|\n";
		cout << "|" << setw(8) << "x" << setw(8);
		cout << "|" << setw(8) << "F" << setw(9) << "|\n";
		cout << "|" << string(15, '\xc4');
		cout << "|" << string(15, '\xc4') << "|\n";

		cout << fixed;
		cout.precision(3);

		for (double x = xn; x <= xk; x += dx) {
			cout << "|" << setw(10) << x << setw(6) << "|";

			double f;
			if ((x < 0) && (abs(b) >= kEps)) {
				if (abs(10 + b) < kEps) {
					cout << " division by 0 |\n";
					continue;
				}
				else {
					f = a - x / (10 + b);
				}
			}
			else if ((x > 0) && (abs(b) < kEps)) {
				if (abs(x - c) < kEps) {
					cout << " division by 0 |\n";
					continue;
				}
				else {
					f = (x - a) / (x - c);
				}
			}
			else {
				if (abs(c) < kEps) {
					cout << " division by 0 |\n";
					continue;
				}
				else {
					f = 3 * x + 2 / c;
				}
			}

			int ac = static_cast<int>(a);
			int bc = static_cast<int>(b);
			int cc = static_cast<int>(c);
			if ((ac | bc) & cc)
				cout << setw(10) << f << setw(7);
			else
				cout << setw(8) << static_cast<int>(f) << setw(9);
			cout << "|\n";
		}
		cout << "|" << string(15, '\xc4') << "|" << string(15, '\xc4') << "|";
	}
	return 0;
}