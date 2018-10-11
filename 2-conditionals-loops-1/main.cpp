#include <iostream>
#include<iomanip>
using namespace std;
int main() {
	int ac, bc, cc;
	double a, b, c, xn, xk, dx, x, F;
	const double keps = 1e-15;
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
	ac = int(a), bc = int(b), cc = int(c);
	
	cout << "|" << setw(1) << "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4" << setw(1) << "|" << setw(1) << "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4" << setw(1) << "|" << endl;
	
	cout << "|" << setw(8) << "x" << setw(8) << "|" << setw(8) << "F" << setw(8) << "|" << endl;
	
	cout << "|" << setw(1) << "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4" << setw(1) << "|" << setw(1) << "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4" << setw(1) << "|" << endl;
	for (x = xn; x <= xk; x += dx) {
		if ((abs(c)< keps) || (abs(10 + b)<keps) || (abs(x - c)<keps)) {
			cout << "ERROR" << endl;
			break;
		}
		if ((x < keps) && (abs(b)>keps )) {
			F = a - (x / (10 + b));
		}
		if ((x > keps) && (abs(b) < keps)) {
			F = (x - a) / (x - c);
		}
		else {
			F = 3 * x + 2 / c;
		}
		if (((ac || bc) && cc) != 0) {
			
			cout << "|" << setw(8) << x << setw(8) << "|" << setw(8) << F << setw(8) << "|" << endl;
		}
		else {
			
			cout << "|" << setw(8) << x << setw(8) << "|" << setw(8) << int(F) << setw(8) << "|" << endl;
		}
	
		cout << "|" << setw(1) << "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4" << setw(1) << "|" << setw(1) << "\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4" << setw(1) << "|"<<endl
			;
	}
	return 0;
}

