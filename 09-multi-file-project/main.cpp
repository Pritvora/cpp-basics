#include <iostream>
#include "functions.h"



using namespace std;

int main() {
	const int kArraySize = 10;
	double arr[kArraySize] = { -6, 0, -7, -2, -4, -3, 2, -5, 1, -6 };

	PrintArray(arr, kArraySize);
	cout << "\nMaximum array element = " << FindMax(arr, kArraySize) << endl;
	int last_positive_addr= FindLastPositive(arr,  kArraySize);
	
	if (last_positive_addr != -1) {
	
		cout << "Sum of elements before the last positive = ";
		cout << Sum(arr, last_positive_addr) << endl;
	}
	else {
		cout << "\nNo positive elements were found!\n";
	}

	double a, b;
	cout << "\nEnter boundaries [a, b]:\n";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	if (a <= b) {
		
		DeleteOutOf( arr,  kArraySize, a,  b);
		cout << "\nTransformed array:\n";
		PrintArray(arr, kArraySize);
	}
	else {
		cout << "\nERROR >>> NEED: a <= b\n";
	}

	return 0;
}
