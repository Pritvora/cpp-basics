#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
void Print_Hat() {
	cout << "|" << string(8, '\xc4') << "|" << string(13, '\xc4');
	cout << "|" << string(13, '\xc4') << "|" << string(8, '\xc4') << "|\n";
	cout << "|" << setw(6) << "x" << setw(3);
	cout << "|" << setw(11) << "F" << setw(3) << "|" << setw(11) << "T" << setw(3);
	cout << "|" << setw(6) << "ITER" << setw(4) << "|\n";
	cout << "|" << string(8, '\xc4') << "|" << string(13, '\xc4');
	cout << "|" << string(13, '\xc4') << "|" << string(8, '\xc4') << "|\n";
	
}
void Function( double xn, double xk, double dx,double eps, const int MaxIter, const double kEps) {
	for (; xn <= xk; xn += dx) {
		int n;
		double F = log((1 + xn) / (1 - xn));
		double Ty = 0;
		for (n = 0; n < MaxIter; n++) {
			double tmp = 2 * (pow(xn, 1 + n * 2) / (1 + n * 2));
			if (abs(tmp) <= kEps)
			{
				break;
			}
			Ty += tmp;
		}
		cout << "|" << setw(6) << xn << setw(3);
		cout << "|" << setw(11) << F << setw(3);
		cout << "|" << setw(11) << Ty << setw(3);
		cout << "|" << setw(6) << n << setw(4) << "|\n";
		
	}

	
}
void End() {
	cout << "|" << string(8, '\xc4') << "|" << string(13, '\xc4');
	cout << "|" << string(13, '\xc4') << "|" << string(8, '\xc4') << "|\n";
}


int main() {
	const int MaxIter = 500;
	const double kEps = 1e-15;
	double  xn, xk, dx, eps;

	cout << "Enter value |xn|<1: ";
	cin >> xn;
	cout << "Enter value |xk|<1: ";
	cin >> xk;
	cout << "Enter value dx: ";
	cin >> dx;
	cout << "Enter value accuracy eps>0 : ";
	cin >> eps;
	cout << fixed;
	cout.precision(3);
	if ((abs(xn) >= 1) || (abs(xk) >= 1) || (dx < kEps) || (eps < kEps)) {
		cout << "\tERROR IN THE VALUES OF VARIABLES\t \n";
		cout << "\tNEED: |xn|<1 , |xk|<1 , eps>0 , dx>0 " << endl;
	}
	else {
		Print_Hat();
		Function(xn, xk, dx, eps, MaxIter, kEps);
		End();
	}
	return 0;
}