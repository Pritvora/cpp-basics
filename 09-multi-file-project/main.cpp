#include "functions.h"

int main() {
	const int kArraySize = 10;
	double arr[kArraySize] = { -6, 0, -7.1, 2, -0.1, -3.1, 2, -5, 1, -6 };

	cout << "Array elements:\n";
	PrintArray(arr, kArraySize);

	cout << "\nMaximum array element = " << FindMax(arr, kArraySize) << endl;

	int last_positive_addr = FindLastPositiveAddr(arr, kArraySize);
	cout << "\nSum of elements before the last positive = ";
	if (last_positive_addr != -1) {
		if (last_positive_addr != 0)
			cout << GetSum(arr, kArraySize, last_positive_addr) << endl;
		else
			cout << "\nLast positive element is the first one!\n";
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
		TransformArray(arr, kArraySize, a, b);
		cout << "\nTransformed array:\n";
		PrintArray(arr, kArraySize);
	}
	else {
		cout << "\nERROR >>> NEED: a <= b\n";
	}

	return 0;
}