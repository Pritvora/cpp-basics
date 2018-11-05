#include <fstream>
#include <iostream>
using namespace std;

int n = 0;
int** Input_Matrix();
void Print_Matrix(int** x);
void First_Task(int** x);
int Second_Task(int** x);
int main()
{
	int** m= Input_Matrix();
	Print_Matrix(m);
	First_Task(m);

	cout << "The minimum sum of modules of the elements :";
	cout<<" of the diagonals that are parallel to the side:";
	cout << Second_Task(m) << endl;

	return 0;
}

int** Input_Matrix() {
	ifstream in("matrix.txt");
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
		int **x = new int*[n];
		for (int i = 0; i < n; i++) x[i] = new int[n];
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
void Print_Matrix(int** x) {
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << x[i][j] << "\t";
		cout << "\n";
	}
	cout << "dimension: " << n<< endl;
}
void First_Task(int** x) {
	
	bool ot = false;
	for (int j = 0; j < n;j++) {
		bool hm = false;
		for (int i = 0; i < n;i++) {
			if (x[i][j] < 0) {
				hm = true;
			}
		}
		if (!hm) {
			int sum = 0;
			ot = true;
			for (int i = 0; i < n; i++) {
				sum += x[i][j];
			}
			cout << "Sum of items in "<<j+1<<" column:";
			cout << sum << endl;
		}
	}
	if (!ot) {
		cout << "\nError:  all columns has minus elements" << endl;
	}
	
	
}
int Second_Task(int** x) {
	int min = -1;
	for (int i = 0; i < n * 2 - 1; i++) {
		int sumd = 0;
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
