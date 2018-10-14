#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
int main() {
	const int MaxIter = 500;
	double  xn, xk, dx, eps;
	const double kEps = 1e-15;
	cout << "Enter value |xn|<1: ";
	cin >> xn;
	cout << "Enter value |xk|<1: ";
	cin >> xk;
	cout << "Enter value dx: ";
	cin >> dx;
	cout << "Enter value accuracy eps>0 : ";
	cin >> eps;
	if ((abs(xn) >= 1) || (abs(xk) >= 1) || (dx < kEps) || (eps < kEps)) {
		cout << "\t\ERROR IN THE VALUES OF VARIABLES\t\ " << endl;
		cout << "\t\NEED: |xn|<1 , |xk|<1 , eps>0 , dx>0 " << endl;
	}
	else {
		cout << "|" << string(8, '\xc4') << "|" << string(13, '\xc4') << "|" << string(13, '\xc4') << "|" << string(8, '\xc4') << "|" << endl;
		cout << "|" << setw(6) << "x" << setw(3) << "|" << setw(11) << "F" << setw(3) << "|" << setw(11) << "T" << setw(3) << "|" << setw(6) << "ITER" << setw(3) << "|" << endl;
		cout << "|" << string(8, '\xc4') << "|" << string(13, '\xc4') << "|" << string(13, '\xc4') << "|" << string(8, '\xc4') << "|" << endl;
		for (double x = xn; x <= xk; x += dx) {
			int n;
			double F = log((1 + x) / (1 - x));
			double Ty = 0;
			for ( n = 0; n < MaxIter; n++) {
				double tmp = 2 * (pow(x, 1 + n * 2) / (1 + n * 2));
				if (abs(tmp) <= kEps)
				{
					break;
				}
				Ty += tmp;
			}
			cout << "|" << setw(6) << x << setw(3) << "|" << setw(11) << F << setw(3) << "|" << setw(11) << Ty << setw(3) << "|" << setw(6) << n << setw(3) << "|" << endl;
		}

		cout << "|" << string(8, '\xc4') << "|" << string(13, '\xc4') << "|" << string(13, '\xc4') << "|" << string(8, '\xc4') << "|" << endl;
	}

	return 0;
}
