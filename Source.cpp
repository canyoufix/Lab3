#include <iostream>

using namespace std;

const int  ROW = 3, COL = 10;

void inputStr(char str[][COL], const int ROW, const int COL) {
	cout << "Input" << endl;
	for (int i = 0; i < ROW; i++) {
		cout << i+1 << " string: ";
		cin.getline(str[i], COL);
	}
}

void outStr(char str[][COL], const int ROW, const int COL) {
	cout << endl << "Output: " << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << str[i][j];
		}
		cout << endl;
	}
}

int main() 
{
	char str[ROW][COL];
	char* str_p[ROW];
	inputStr(str, ROW, COL);
	outStr(str, ROW, COL);
	
	return 0;
}