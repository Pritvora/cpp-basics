
#include <iostream>

using namespace std;

int main() {
	const int kArraySize = 10;
	double arr[kArraySize] = { -6, 0, -7, -2, -4, -3, 2, -5, 1, -6 };

	cout << "Array elements:\n";
	for (int i = 0; i < kArraySize; i++)
		cout << arr[i] << " ";
	cout << endl;

	double arr_max = arr[0];
	for (int i = 1; i < kArraySize; i++) {
		if (arr[i] > arr_max)
			arr_max = arr[i];
	}
	cout << "\nMaximum array element = " << arr_max << endl;

	int last_positive_addr = -1;
	for (int i = kArraySize; i >= 0; i--) {
		if (arr[i] > 0) {
			last_positive_addr = i;
			break;
		}
	}
	if (last_positive_addr != -1) {
		double sum_before_last_positive = 0.0;
		for (int i = 0; i < last_positive_addr; i++)
			sum_before_last_positive += arr[i];

		cout << "Sum of elements before the last positive = ";
		cout << sum_before_last_positive << endl;
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
		int i = 0;
		int num_kept_elements = kArraySize;
		while (i < num_kept_elements) {
			if (abs(arr[i]) >= a && abs(arr[i]) <= b) {
				num_kept_elements--;
				for (int j = i; j < num_kept_elements; j++)
					arr[j] = arr[j + 1];
				arr[num_kept_elements] = 0.0;
			}
			else {
				i++;
			}
		}

		cout << "\nTransformed array:\n";
		for (int i = 0; i < kArraySize; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else {
		cout << "\nERROR >>> NEED: a <= b\n";
	}

	return 0;
}