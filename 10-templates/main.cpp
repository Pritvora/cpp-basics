#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
T** ReadMatrix(string file_name, int& size);

template <class T>
void PrintMatrix(T** matrix, int size);

template <class T>
bool* FindNonNegativeCols(T** matrix, int size);

template <class T>
T SumCol(T** matrix, int size, int j);

template <class T>
T MinSecondaryDiagonalsSum(T** matrix, int size);

template <class T>
int Execute(string file_name);

int main() {
	string select;
selection:
	cout << "Want matrix? What type do you want? (0-int / 1-double / 2-float): ";
	cin >> select;
	if (select == "0") {
		Execute<int>("matrix_int.txt");
	}
	else if (select == "1") {
		Execute<double>("matrix_double.txt");
	}
	else if (select == "2") {
		Execute<float>("matrix_float.txt");
	}
	else {
		cout << "Error input! (Only 0, 1 or 2).\n\n";
		goto selection;
	}

	return 0;
}

template <class T>
int Execute(string file_name) {
	int size;
	T** matrix = ReadMatrix<T>(file_name, size);
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

template <class T>
T** ReadMatrix(string file_name, int& size) {
	ifstream fin(file_name);
	if (!fin) {
		cout << "File \"" << file_name << "\" not found.";
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
	T **matrix = new T*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new T[size];
		for (int j = 0; j < size; j++)
			fin >> matrix[i][j];
	}

	fin.close();
	return matrix;
}

template <class T>
void PrintMatrix(T** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << matrix[i][j] << "\t";
		cout << "\n";
	}
}

template <class T>
bool* FindNonNegativeCols(T** matrix, int size) {
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

template <class T>
T SumCol(T** matrix, int size, int j) {
	T sum = 0;
	for (int i = 0; i < size; i++)
		sum += matrix[i][j];
	return sum;
}

template <class T>
T MinSecondaryDiagonalsSum(T** matrix, int size) {
	T min = matrix[0][0];
	for (int i = 1; i < size * 2 - 1; i++) {
		T sum_diagonal = 0;
		for (int j = 0; j <= i; j++) {
			if (j < size && i - j < size)
				sum_diagonal += abs(matrix[j][i - j]);
		}

		if (sum_diagonal < min)
			min = sum_diagonal;
	}
	return min;
}