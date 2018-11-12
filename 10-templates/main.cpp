#include <fstream>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T** Input_Matrix(string fileName,int& n);
template <typename T>
void Print_Matrix(T** x,int n);
template <typename T>
void First_Task(T** x, int n);
template <typename T>
T Second_Task(T** x, int n);
int main()
{
	int n=0;
	string want_matrix;
	cout << "Want matrix?What type do you want?(int/double/float)";
	cin >> want_matrix;
	if (want_matrix =="int" ) {
		int** m = Input_Matrix<int>("matrix_int.txt", n);
		Print_Matrix<int>(m, n);
		First_Task<int>(m, n);
		cout << "The minimum sum of modules of the elements";
		cout << " of the diagonals that are parallel to the side:";
		cout << Second_Task<int>(m, n) << endl;

	}
	if (want_matrix == "double") {
		double** m = Input_Matrix<double>("matrix_double.txt", n);
		Print_Matrix<double>(m, n);
		First_Task<double>(m, n);
		cout << "The minimum sum of modules of the elements";
		cout << " of the diagonals that are parallel to the side:";
		cout << Second_Task<double>(m, n) << endl;

	}
	if (want_matrix == "float") {
		float** m = Input_Matrix<float>("matrix_float.txt", n);
		Print_Matrix<float>(m, n);
		First_Task<float>(m, n);
		cout << "The minimum sum of modules of the elements";
		cout << " of the diagonals that are parallel to the side:";
		cout << Second_Task<float>(m, n) << endl;

	}

	
	return 0;
}
template <typename T>
T** Input_Matrix(string fileName ,int& n) {
	ifstream in(fileName);
	if (in.is_open())
	{

		while (!in.eof())
		{
			char symbol;
			in.get(symbol);
			if (symbol == ' ') n++;
			if (symbol == '\n') break;
		}
		n++;
		in.seekg(0, ios::beg);
		in.clear();
		T** x = new T*[n];
		for (int i = 0; i < n; i++) x[i] = new T[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				in >> x[i][j];

		in.close();
		return x;
	}
	else
	{
		cout << "File not found.";
		return(0);
	}

}
template <typename T>
void Print_Matrix(T** x, int n) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << x[i][j] << "\t";
		cout << "\n";
	}
	cout << "dimension: " << n << endl;
}
template <typename T>
void First_Task(T** x, int n) {

	bool ot = false;
	for (int j = 0; j < n; j++) {
		bool hm = false;
		for (int i = 0; i < n; i++) {
			if (x[i][j] < 0) {
				hm = true;
			}
		}
		if (!hm) {
			T sum = 0;
			ot = true;
			for (int i = 0; i < n; i++) {
				sum += x[i][j];
			}
			cout << "Sum of items in " << j + 1 << " column:";
			cout << sum << endl;
		}
	}
	if (!ot) {
		cout << "\nError:  all columns has minus elements" << endl;
	}


}
template <typename T>
T Second_Task(T** x, int n) {
	T min = -1;
	for (int i = 0; i < n * 2 - 1; i++) {
		T sumd = 0;
		for (int j = 0; j <= i; j++) {
			if (j < n && i - j < n)
			{
				sumd += abs(x[j][i - j]);
			}
		}
		if ((sumd < min) || (min == -1)) {
			min = sumd;
		}
	}
	return min;
}
