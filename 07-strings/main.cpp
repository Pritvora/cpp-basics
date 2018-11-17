#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ifstream fin("text.txt");
	if (!fin) {
		cout << "File \"text.txt\" not found.";
		return 1;
	}

	// Print text.
	string line;
	while (getline(fin, line))
		cout << line << endl;
	cout << endl;

	fin.clear();
	fin.seekg(0, ios::beg);

	// Swap words in text.
	string first_word, second_word;
	while (getline(fin, line)) {
		string word;
		stringstream sin(line);
		bool is_first_word = true;
		while (sin >> word) {
			if (is_first_word) {
				first_word = word;
				is_first_word = false;
			}
			else {
				second_word = word;
				is_first_word = true;

				string puncts[4];

				size_t first_word_len = first_word.length();
				if (ispunct(first_word[0]) && first_word[0] != '"') {
					puncts[0] = first_word[0];
					first_word = first_word.substr(1, first_word_len);
					first_word_len--;
				}
				if (ispunct(first_word[first_word_len - 1]) &&
					first_word[first_word_len - 1] != '"') {
					puncts[1] = first_word[first_word_len - 1];
					first_word = first_word.substr(0, first_word_len - 1);
					first_word_len--;
				}

				size_t second_word_len = second_word.length();
				if (ispunct(second_word[0]) && second_word[0] != '"') {
					puncts[2] = second_word[0];
					second_word = second_word.substr(1, second_word_len);
					second_word_len--;
				}
				if (ispunct(second_word[second_word_len - 1]) &&
					second_word[second_word_len - 1] != '"') {
					puncts[3] = second_word[second_word_len - 1];
					second_word = second_word.substr(0, second_word_len - 1);
					second_word_len--;
				}

				cout << puncts[0] << second_word << puncts[1] << " ";
				cout << puncts[2] << first_word << puncts[3] << " ";
			}
		}
		cout << endl;
	}

	fin.close();
	return 0;
}