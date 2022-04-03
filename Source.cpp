#include <iostream>

using namespace std;

const int SIZE = 80, N = 2;

void inputStr(char **Str) {
	for (int i = 0; i <= N; i++) {
		cout << "Enter " << i + 1 <<  " string: ";
		cin.getline(Str[i], SIZE);
	}
	cout << endl;
}

void outStr(char **Str) {
	for (int i = 0; i <= N; i++) {
		cout << i + 1 << ')' << '\t';
		puts(Str[i] + i);
	}
}

void sortStr(char** Str, int *numOfNumbers) {
	int i = 0;
	for (int j = 0; j <= N; j++) {
		while (Str[i][j] != '\0') {
			if (Str[i][j] >= 48 && Str[i][j] <= 57) {
				numOfNumbers[j]++;
			}
			j++;
		}
	}
}

int main() {
	char Str[SIZE][N];
	int numOfNumbers[N+1];

	inputStr((char**)Str);
	outStr((char**)Str);

	return 0;
}