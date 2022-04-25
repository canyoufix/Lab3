#include <iostream>
#include <iomanip>

using namespace std;

const int  ROW = 7, COL = 50;

//FUNCTION
void inputStr(char** pstr, char str[][COL]) {
	for (int i = 0; i < ROW; i++)					//array pstr
		pstr[i] = str[i];

	cout << "\tINPUT" << endl;						//input
	for (int i = 0; i < ROW; i++) {
		cout << i + 1 << " | ";
		cin.getline(pstr[i], COL);
	}
	cout << endl;
}

int secondNum(char** pstr, int indexStr) {
	int num2 = 0, j = 0;
	while (pstr[indexStr][j] != '\0') {
		if (pstr[indexStr][j] >= 48 && pstr[indexStr][j] <= 57) num2++;
		if (num2 == 2) {
			return pstr[indexStr][j];
		}
		j++;
	}
	return -1;
}

int countNum(char** pstr, int indexStr) {
	int nNum = 0, j = 0;
	while (pstr[indexStr][j] != '\0') {
		if (pstr[indexStr][j] >= 48 && pstr[indexStr][j] <= 57)
			nNum++;
		j++;
	}
	return nNum;
}

void outStr(char** pstr) {
	int num2 = 0;
	cout << "\tRESULT:" << endl;
	for (int i = 0; i < ROW; i++) {
		cout << i + 1 << " | " << pstr[i] << endl;
		cout << "  |" << setw(30) << "Num of digits: " << countNum(pstr, i);
		num2 = secondNum(pstr, i);
		if (num2 >= 0) {
			cout << "\tSecond num: " << num2 - 48 << endl;
		}
		else
			cout << "\tNo numbers (or missing 2nd element) in the string" << endl;
	}
}

void sortStr(char** pstr) {
	char* buffer;												//backup
	for (int i = 0; i < ROW - 1; i++)
	{
		bool isSwap = false;									//optimization
		for (int j = 0; j < ROW - 1 - i; j++)
		{
			if (countNum(pstr, j) > countNum(pstr, j + 1)) {
				buffer = pstr[j];
				pstr[j] = pstr[j + 1];
				pstr[j + 1] = buffer;
				isSwap = true;
			}
		}
		if (isSwap == false)
			break;
	}
}
//FUNCTION


int main() 
{
	char str[ROW][COL];
	char* pstr[ROW];
	
	inputStr(pstr, str);
	sortStr(pstr);
	outStr(pstr);

	return 0;
}