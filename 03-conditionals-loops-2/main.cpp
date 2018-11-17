#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main() {
	const int kMaxIters = 500;

	double xn, xk, dx, eps;
	cout << "Enter value |xn| < 1: ";
	cin >> xn;
	cout << "Enter value |xk| < 1 (xk >= xn): ";
	cin >> xk;
	cout << "Enter value dx > 0: ";
	cin >> dx;
	cout << "Enter accuracy eps > 0 : ";
	cin >> eps;

	if ((abs(xn) >= 1) || (abs(xk) >= 1) || (dx <= 0) || (eps <= 0) || (xn > xk)) {
		cout << "\tERROR IN THE VALUES OF VARIABLES\t \n";
		cout << "\tNEED: |xn|<1 , |xk|<1 , eps>0 , dx>0 , xk>=xn " << endl;
	}
	else {
		cout << "|" << string(11, '\xc4') << "|" << string(17, '\xc4');
		cout << "|" << string(17, '\xc4') << "|" << string(9, '\xc4') << "|\n";
		cout << "|" << setw(6) << "x" << setw(6);
		cout << "|" << setw(16) << "ln((1+x)/(1-x))" << setw(2);
		cout << "|" << setw(16) << "ln((1+x)/(1-x))" << setw(2);
		cout << "|" << setw(7) << "iters" << setw(4) << "|\n";
		cout << "|" << string(11, ' ') << "|" << setw(12) << "(cmath)" << setw(6);
		cout << "|" << setw(12) << "(mine)" << setw(6) << "|" << string(9, ' ') << "|\n";
		cout << "|" << string(11, '\xc4') << "|" << string(17, '\xc4');
		cout << "|" << string(17, '\xc4') << "|" << string(9, '\xc4') << "|\n";

		cout << fixed;
		cout.precision(6);

		for (double x = xn; x <= xk; x += dx) {
			int n;
			double ln = 0;
			for (n = 0; n <= kMaxIters; n++) {
				double nth_term = 2 * (pow(x, 1 + n * 2) / (1 + n * 2));
				ln += nth_term;
				if (abs(nth_term) < eps) break;
			}

			cout << "|" << setw(10) << x << setw(2);
			cout << "|" << setw(13) << log((1 + x) / (1 - x)) << setw(5) << "|";
			if (n <= kMaxIters)
				cout << setw(13) << ln << setw(5);
			else
				cout << " limit exceeded! ";
			cout << "|" << setw(5) << n << setw(6) << "|\n";
		}

		cout << "|" << string(11, '\xc4') << "|" << string(17, '\xc4');
		cout << "|" << string(17, '\xc4') << "|" << string(9, '\xc4') << "|\n";
	}

	return 0;
}