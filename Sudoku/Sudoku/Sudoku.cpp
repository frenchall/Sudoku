#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

void Print_Table();
void Transposing_Table();
void Mixing_Table();
void Delete_Cell();
void Check_Your_Self();

int BaseTable[9][9] = { { 1,2,3,4,5,6,7,8,9 },
						{ 4,5,6,7,8,9,1,2,3 },
						{ 7,8,9,1,2,3,4,5,6 },
						{ 2,3,4,5,6,7,8,9,1 },
						{ 5,6,7,8,9,1,2,3,4 },
						{ 8,9,1,2,3,4,5,6,7 },
						{ 3,4,5,6,7,8,9,1,2 },
						{ 6,7,8,9,1,2,3,4,5 },
						{ 9,1,2,3,4,5,6,7,8 } };

int TransposingBaseTable[9][9];
int InternalCheckTable[9][9];
int CheckingTable[9][9];
int i, j, d, InputComplexity, Plenum, LineNumber, ColumnNumber, Item;
int NumberMixingLines, NumberMixingColumns;
int NumberMixingVerticalBlocks, NumberMixingHorizontalBlocks;

int const N = 9;

int main(int argc, char *argv[])
{
	cout << "Enter the level of difficulty from 1 to 3 = ";
	cin >> InputComplexity;
	srand(time(0));
	if (InputComplexity == 1) {
		NumberMixingLines = rand() % 30 + 1;
		NumberMixingColumns = rand() % 30 + 1;
		NumberMixingVerticalBlocks = rand() % 30 + 1;
		NumberMixingHorizontalBlocks = rand() % 30 + 1;
	}
	if (InputComplexity == 2) {
		NumberMixingLines = rand() % 30 + 50;
		NumberMixingColumns = rand() % 30 + 50;
		NumberMixingVerticalBlocks = rand() % 30 + 50;
		NumberMixingHorizontalBlocks = rand() % 30 + 50;
	}
	if (InputComplexity == 3) {
		NumberMixingLines = rand() % 30 + 100;
		NumberMixingColumns = rand() % 30 + 100;
		NumberMixingVerticalBlocks = rand() % 30 + 100;
		NumberMixingHorizontalBlocks = rand() % 30 + 100;
	}
	if (InputComplexity > 3 || InputComplexity < 1) {
		cout << "Incorrect value, try again";
		printf("\n");
	}
	else {
		Transposing_Table();
		Mixing_Table();
		Delete_Cell();
		Print_Table();
		do {
			Plenum = 0;
			cout << "Enter the line number: ";
			cin >> LineNumber;
			cout << "Enter the number of the column: ";
			cin >> ColumnNumber;
			cout << "Enter the item: ";
			cin >> Item;
			printf("\n");
			TransposingBaseTable[LineNumber - 1][ColumnNumber - 1] = Item;
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (TransposingBaseTable[i][j] == 0)
						d = 1;
					else
						d = 0;
					if (Plenum<d)
						Plenum = 1;
				}
			}
			printf("|-----------------------------------");
			printf("| \n");
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					printf("| %i ", TransposingBaseTable[i][j]);
				}
				printf("| \n");
				printf("|-----------------------------------");
				printf("| \n");
			}
			printf("\n");
		} while (Plenum == 1);
		Check_Your_Self();
	}
	system("pause");
	return 0;
}

void Print_Table() {
	int i, j;
	printf("|-----------------------------------");
	printf("| \n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("| %i ", TransposingBaseTable[i][j]);
		}
		printf("| \n");
		printf("|-----------------------------------");
		printf("| \n");
	}
	printf("\n");
}
void Transposing_Table() {
	int i, j;
	const int N = 9;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			TransposingBaseTable[i][j] = BaseTable[j][i];
		}
	}
}
void Mixing_Table() {
	int i, j, SumSwap, Storage;
	int LineStorage[9];
	int LineStorage1[9];
	int LineStorage2[9];
	for (SumSwap = 0; SumSwap < NumberMixingLines; SumSwap++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				Storage = TransposingBaseTable[i][j];
				TransposingBaseTable[i][j] = TransposingBaseTable[j][i];
				TransposingBaseTable[j][i] = Storage;
			}
		}
		for (j = 0; j < N; j++) {
			LineStorage[j] = TransposingBaseTable[0][j];
			TransposingBaseTable[0][j] = TransposingBaseTable[1][j];
			TransposingBaseTable[1][j] = TransposingBaseTable[2][j];
			TransposingBaseTable[2][j] = LineStorage[j];
			LineStorage[j] = TransposingBaseTable[3][j];
			TransposingBaseTable[3][j] = TransposingBaseTable[4][j];
			TransposingBaseTable[4][j] = TransposingBaseTable[5][j];
			TransposingBaseTable[5][j] = LineStorage[j];
			LineStorage[j] = TransposingBaseTable[6][j];
			TransposingBaseTable[6][j] = TransposingBaseTable[7][j];
			TransposingBaseTable[7][j] = TransposingBaseTable[8][j];
			TransposingBaseTable[8][j] = LineStorage[j];
		}
	}
	for (SumSwap = 0; SumSwap < NumberMixingColumns; SumSwap++) {
		for (i = 0; i < N; i++) {
			LineStorage[i] = TransposingBaseTable[i][0];
			TransposingBaseTable[i][0] = TransposingBaseTable[i][1];
			TransposingBaseTable[i][1] = TransposingBaseTable[i][2];
			TransposingBaseTable[i][2] = LineStorage[i];
			LineStorage[i] = TransposingBaseTable[i][3];
			TransposingBaseTable[i][3] = TransposingBaseTable[i][4];
			TransposingBaseTable[i][4] = TransposingBaseTable[i][5];
			TransposingBaseTable[i][5] = LineStorage[i];
			LineStorage[i] = TransposingBaseTable[i][6];
			TransposingBaseTable[i][6] = TransposingBaseTable[i][7];
			TransposingBaseTable[i][7] = TransposingBaseTable[i][8];
			TransposingBaseTable[i][8] = LineStorage[i];
		}
	}
	for (SumSwap = 0; SumSwap < NumberMixingHorizontalBlocks; SumSwap++) {
		for (j = 0; j < N; j++) {
			LineStorage[j] = TransposingBaseTable[0][j];
			LineStorage1[j] = TransposingBaseTable[1][j];
			LineStorage2[j] = TransposingBaseTable[2][j];
			TransposingBaseTable[0][j] = TransposingBaseTable[3][j];
			TransposingBaseTable[1][j] = TransposingBaseTable[4][j];
			TransposingBaseTable[2][j] = TransposingBaseTable[5][j];
			TransposingBaseTable[3][j] = TransposingBaseTable[6][j];
			TransposingBaseTable[4][j] = TransposingBaseTable[7][j];
			TransposingBaseTable[5][j] = TransposingBaseTable[8][j];
			TransposingBaseTable[6][j] = LineStorage[j];
			TransposingBaseTable[7][j] = LineStorage1[j];
			TransposingBaseTable[8][j] = LineStorage2[j];
		}
	}
	for (SumSwap = 0; SumSwap < NumberMixingVerticalBlocks; SumSwap++) {
		for (i = 0; i < N; i++) {
			LineStorage[i] = TransposingBaseTable[i][0];
			LineStorage1[i] = TransposingBaseTable[i][1];
			LineStorage2[i] = TransposingBaseTable[i][2];
			TransposingBaseTable[i][0] = TransposingBaseTable[i][3];
			TransposingBaseTable[i][1] = TransposingBaseTable[i][4];
			TransposingBaseTable[i][2] = TransposingBaseTable[i][5];
			TransposingBaseTable[i][3] = TransposingBaseTable[i][6];
			TransposingBaseTable[i][4] = TransposingBaseTable[i][7];
			TransposingBaseTable[i][5] = TransposingBaseTable[i][8];
			TransposingBaseTable[i][6] = LineStorage[i];
			TransposingBaseTable[i][7] = LineStorage1[i];
			TransposingBaseTable[i][8] = LineStorage2[i];
		}
	}
}
void Delete_Cell() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			InternalCheckTable[i][j] = TransposingBaseTable[i][j];
		}
	}
	TransposingBaseTable[1][1] = 0;
	//for (i = 0; i < N; i += 3) {
	//	for (j = 2; j < N; j += 3) {
	//		TransposingBaseTable[i][j] = 0;
	//	}
	//}
	//for (i = 1; i < N; i += 2) {
	//	for (j = 0; j < N; j += 2) {
	//		TransposingBaseTable[i][j] = 0;
	//	}
	//}
	//for (i = 2; i < N; i += 2) {
	//	for (j = 1; j < N; j += 2) {
	//		TransposingBaseTable[i][j] = 0;
	//	}
	//}
}
void Check_Your_Self() {
	int i, j, s;
	int ResultChecking = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (TransposingBaseTable[i][j] == InternalCheckTable[i][j]) {
				s = 0;
			}
			else {
				s = 1;
			}
			if (ResultChecking<s)
				ResultChecking = 1;
		}
	}
	if (ResultChecking == 1)
		cout << "You lost, try again.";
	else
		cout << "You win, congrats!";
	printf("\n");
}