#include <iostream>
#include <iomanip>

using namespace std;

void PrintArray(double arr[], int kArraySize) {
	cout << "Array elements:\n";
	for (int i = 0; i < kArraySize; i++)
		cout << arr[i] << " ";
	cout << endl;
}
double FindMax(double arr[], int kArraySize) {
	double arr_max = arr[0];
	for (int i = 1; i < kArraySize; i++) {
		if (arr[i] > arr_max)
			arr_max = arr[i];
	}
	return arr_max;
}
int FindLastPositive(double arr[], int kArraySize) {
	int last_positive_addr = -1;
	for (int i = kArraySize - 1; i >= 0; i--) {
		if (arr[i] > 0) {
			last_positive_addr = i;
			break;
		}
	}
	return last_positive_addr;
}
double Sum(double arr[], int last_ind) {
	double sum = 0.0;
	for (int i = 0; i < last_ind; i++)
		sum += arr[i];
}
void DeleteOutOf(double arr[], int kArraySize, double a, double b) {
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
}