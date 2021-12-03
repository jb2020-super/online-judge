// 232
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <string>


class Puzzle
{
public:
	bool GetSquare() 
	{
		scanf("%d", &row);
		if (!row)
			return false;
		scanf("%d", &col);
		for (int i = 0; i < row; ++i) {
			scanf("%s", m_square[i]);
		}
		return true; // not return will cause RunTime error.
	}
	
	bool IsWhite(int i, int j)
	{
		if (i >= 0 && i < row &&
			j >= 0 && j < col)
		{
			return m_square[i][j] != '*';
		}
		return false;
	}
	void InitLabel()
	{
		int no = 1;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (IsWhite(i, j) && (
					!IsWhite(i, j - 1) ||
					!IsWhite(i - 1, j) ))
				{
					m_label[i][j] = no++;
				}
			}
		}
	}
	void SolveAcross()
	{
		printf("Across\n");
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (IsWhite(i, j)) 
				{
					printf("%3d.", m_label[i][j]);
					while (IsWhite(i, j)) {
						printf("%c", m_square[i][j++]);
					}
					printf("\n");
				}
			}
		}
	}
	void SolveDown()
	{
		printf("Down\n");
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (IsWhite(i, j) && !IsWhite(i - 1, j))
				{
					printf("%3d.", m_label[i][j]);
					int k = i;
					while (IsWhite(k, j)) {
						printf("%c", m_square[k++][j]);
					}
					printf("\n");
				}
			}
		}
	}

private:
	const static int MAX_SIZE = 11;
	char m_square[MAX_SIZE][MAX_SIZE];
	char m_label[MAX_SIZE][MAX_SIZE];
	int row;
	int col;
};

int main()
{
	Puzzle pz;
	int no = 1;
	while (pz.GetSquare()) {
		if (no > 1) {
			printf("\n");
		}
		printf("puzzle #%d:\n", no++);
		pz.InitLabel();
		pz.SolveAcross();
		pz.SolveDown();
	}
	return 0;
}
/*
Input:

2 2
AT
*O
6 7
AIM*DEN
*ME*ONE
UPON*TO
SO*ERIN
*SA*OR*
IES*DEA
*/