#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	int  Max = -RAND_MAX, sum = 0, n, a, b, minEnd = 0;
	const int size = 10;
	int arr[size] = { -5, -8, -7, -56, -4, -98, -1, -45, 25, -6 };
	n = size - 1;
	int index = 0;
	cout << "Ehlementy massiva:" << endl;
	while (index < size) {
		cout << arr[index] << endl;
		index++;
	}
	for (int i = 0; i < size; i++) {
		if (Max < *(arr + i)) {
			Max = *(arr + i);
		}
	}
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) {
			sum += arr[i];
			if (i == 10) {
				cout << "Sum of values to last plus number = " << sum << endl;
			}
		}
	}
	sum = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0) {
			minEnd = i;
		}
	}
	for (int i = 0; i < minEnd; i++) {
		sum += arr[i];
		if (i == minEnd - 1) {
			cout << "Sum of values to last plus number = " << sum << endl;
		}
	}


	cout << "Maximum array element = " << Max << endl;
	cout << "Vvedite granicy promezhytka: " << endl << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	int i = 0;
	n = size;
	if (a > b) {
		cout << "ERROR>>>>NEED:a>=b";
	}
	else {
		while (i < n)
			if (arr[i] <= b && arr[i] >= a) {
				n -= 1;
				for (int j = i; j < n; j++)
					arr[j] = arr[j + 1];
			}
			else {
				i += 1;
			}

		for (i = n; i < size; i++) arr[i] = 0;
		for (i = 0; i < size; i++) {
			cout << arr[i] << "  ";
		}
	}

	return 0;
}