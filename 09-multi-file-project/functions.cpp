#include "functions.h"

void PrintArray(double arr[], const int kArraySize) {
	for (int i = 0; i < kArraySize; i++)
		cout << arr[i] << "  ";
	cout << endl;
}

double FindMax(double arr[], const int kArraySize) {
	double arr_max = arr[0];
	for (int i = 1; i < kArraySize; i++)
		if (arr[i] > arr_max)
			arr_max = arr[i];
	return arr_max;
}

int FindLastPositiveAddr(double arr[], const int kArraySize) {
	int last_positive_addr = -1;
	for (int i = kArraySize - 1; i >= 0; i--) {
		if (arr[i] > 0) {
			last_positive_addr = i;
			break;
		}
	}
	return last_positive_addr;
}

double GetSum(double arr[], const int kArraySize, int end) {
	double sum = 0.0;
	for (int i = 0; i < end; i++)
		sum += arr[i];
	return sum;
}

void TransformArray(double arr[], const int kArraySize, double a, double b) {
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