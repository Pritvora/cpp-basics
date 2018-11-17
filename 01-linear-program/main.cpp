#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a;
	cout << "Please enter the number of degrees or radians to perform the counting.\n";
	cin >> a;

	double z1 = 1 - 0.25*(pow(sin(2 * a), 2)) + cos(2 * a);
	double z2 = pow(cos(a), 2) + pow(cos(a), 4);
	cout << "Znachenie z1: " << z1 << endl << "Znachenie z2: " << z2;

	return 0;
}