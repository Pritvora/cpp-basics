#include <fstream>
#include <iostream>
using namespace std;

int** ReadMatrix(int& size);
void PrintMatrix(int** matrix, int size);
bool* FindNonNegativeCols(int** matrix, int size);
int SumCol(int** matrix, int size, int j);
int MinSecondaryDiagonalsSum(int** matrix, int size);

int main() {
	int size;
	int** matrix = ReadMatrix(size);
	if (!matrix)
		return 1;

	PrintMatrix(matrix, size);
	cout << endl;

	bool* is_col_nonnegative = FindNonNegativeCols(matrix, size);
	for (int j = 0; j < size; j++) {
		if (is_col_nonnegative[j]) {
			cout << "Sum of elements in " << j + 1 << " column: ";
			cout << SumCol(matrix, size, j) << endl;
		}
	}

	cout << "\nThe minimum among the sums of modules of elements of the\n";
	cout << "diagonals parallel to the secondary diagonal of the matrix: ";
	cout << MinSecondaryDiagonalsSum(matrix, size) << endl;

	for (int i = 0; i < size; i++) delete[] matrix[i];
	delete[] matrix;

	return 0;
}

int** ReadMatrix(int& size) {
	ifstream fin("matrix.txt");
	if (!fin) {
		cout << "File \"matrix.txt\" not found.";
		return nullptr;
	}

	// Finds dimension of matrix.
	size = 0;
	while (!fin.eof()) {
		char symbol;
		fin.get(symbol);
		if (symbol == ' ') size++;
		if (symbol == '\n') break;
	}
	size++;
	fin.seekg(0, ios::beg);
	fin.clear();

	// Reads from file.
	int **matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			fin >> matrix[i][j];
	}

	fin.close();
	return matrix;
}

void PrintMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << matrix[i][j] << "\t";
		cout << "\n";
	}
}

bool* FindNonNegativeCols(int** matrix, int size) {
	bool* is_col_nonnegative = new bool[size];
	for (int j = 0; j < size; j++) {
		is_col_nonnegative[j] = 1;
		for (int i = 0; i < size; i++) {
			if (matrix[i][j] < 0) {
				is_col_nonnegative[j] = 0;
				break;
			}
		}
	}
	return is_col_nonnegative;
}

int SumCol(int** matrix, int size, int j) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += matrix[i][j];
	return sum;
}

int MinSecondaryDiagonalsSum(int** matrix, int size) {
	int min = matrix[0][0];
	for (int i = 1; i < size * 2 - 1; i++) {
		int sum_diagonal = 0;
		for (int j = 0; j <= i; j++) {
			if (j < size && i - j < size)
				sum_diagonal += abs(matrix[j][i - j]);
		}

		if (sum_diagonal < min)
			min = sum_diagonal;
	}
	return min;
}