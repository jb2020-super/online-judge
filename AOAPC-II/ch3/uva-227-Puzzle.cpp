// 227
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <string>

class Puzzle
{
public:
	bool GetSquare() {		
		std::getline(std::cin, m_square[0]);		
		if (m_square[0].size() == 1 && m_square[0][0] == 'Z') {
			return false;
		}
		for (int i = 1; i < SQUARE_SIZE; ++i) {
			std::getline(std::cin, m_square[i]);
		}
		return true;
	}
	void Init()
	{
		m_isillegal = false;
		for (int i = 0; i < SQUARE_SIZE; ++i) {
			for (int j = 0; j < SQUARE_SIZE; ++j) {
				if (m_square[i][j] == ' ') {
					m_pos_x = i;
					m_pos_y = j;
					return;
				}
			}
		}
	}
	bool IllegalCheck(int x, int y)
	{
		if (x < 0 || x >= SQUARE_SIZE ||
			y < 0 || y >= SQUARE_SIZE)
			return true;
		return false;
	}
	void Swap(char &a, char &b)
	{
		char t = a;
		a = b;
		b = t;
	}
	void StartMove()
	{		
		char op;
		while ((op = getchar()) != '0') {
			if (m_isillegal)
				continue;
			switch (op)
			{
			case 'A':
				if (IllegalCheck(m_pos_x - 1, m_pos_y)) {
					m_isillegal = true;
				}
				else
				{
					Swap(m_square[m_pos_x][m_pos_y], m_square[m_pos_x - 1][m_pos_y]);
					m_pos_x--;
				}				
				break;
			case 'B':
				if (IllegalCheck(m_pos_x + 1, m_pos_y)) {
					m_isillegal = true;
				}
				else
				{
					Swap(m_square[m_pos_x][m_pos_y], m_square[m_pos_x + 1][m_pos_y]);
					m_pos_x++;
				}
				break;
			case 'R':
				if (IllegalCheck(m_pos_x, m_pos_y + 1)) {
					m_isillegal = true;
				}
				else
				{
					Swap(m_square[m_pos_x][m_pos_y], m_square[m_pos_x][m_pos_y + 1]);
					m_pos_y++;
				}
				break;
			case 'L':
				if (IllegalCheck(m_pos_x, m_pos_y - 1)) {
					m_isillegal = true;
				}
				else
				{
					Swap(m_square[m_pos_x][m_pos_y], m_square[m_pos_x][m_pos_y - 1]);
					m_pos_y--;
				}
				break;
			default:
				break;
			}
		}
		while((op = getchar()) != '\n'){}
	}
	bool IsIllegal() {
		return m_isillegal;
	}
	void Print()
	{
		for (int i = 0; i < SQUARE_SIZE; ++i) {
			for (int j = 0; j < SQUARE_SIZE; ++j) {
				if (j)
					printf(" ");
				printf("%c", m_square[i][j]);
			}
			printf("\n");
		}
	}
private:
	const static int SQUARE_SIZE = 5;
	std::string m_square[SQUARE_SIZE];
	char m_isillegal;
	int m_pos_x;
	int m_pos_y;
};

int main()
{
	int no = 1;
	Puzzle puz;

	while (puz.GetSquare())
	{
		if (no > 1) {
			printf("\n");
		}
		printf("Puzzle #%d:\n", no++);
		puz.Init();
		puz.StartMove();
		if (puz.IsIllegal()) {
			printf("This puzzle has no final configuration.\n");
		}
		else
		{
			puz.Print();
		}
	}
	return 0;
}
/*
ABCDE
FGHIJ
KLMNO
PQRS 
TUVWX
AAA
LLLL0
TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBL0
ABCDE
ABCDE
ABCDE
A CDE
ABCDE
A0
ABCDE
ABCDE
ABCDE
A CDE
ABCDE
B0
ABCDE
ABCDE
ABCDE
A CDE
ABCDE
R0
ABCDE
ABCDE
ABCDE
A CDE
ABCDE
L0
*/