// uva 340 - Master-Mind Hints
#include <iostream>
#include <algorithm>
#include <cstring>

bool read_input(char *pdata, int n)
{
	int i = 0;
	while (i < n && scanf("%d", &pdata[i])) {
		++i;
	}
	if (!pdata[0])
		return false;
	return true;
}

void get_hints(const char* code, const char* guess, int n)
{
	int strong = 0;
	const int NUMS = 10;
	int code_cnt[NUMS];
	int guess_cnt[NUMS];
	memset(code_cnt, 0, sizeof(code_cnt));
	memset(guess_cnt, 0, sizeof(guess_cnt));
	for (int i = 0; i < n; ++i) {
		if (code[i] == guess[i]) {
			++strong;
		}
		else
		{
			code_cnt[code[i]]++;
			guess_cnt[guess[i]]++;
		}
	}
	int weak = 0;
	for (int i = 1; i <= 9; ++i) {
		weak += std::min(code_cnt[i], guess_cnt[i]);
	}
	printf("    (%d,%d)\n", strong, weak);
}

int main()
{
	int n = 0;
	const int MAX_N = 1001;
	char code[MAX_N];
	char guess[MAX_N];
	int game_no = 1;
	while (scanf("%d", &n) != EOF && n)
	{
		printf("Game %d:\n", game_no++);
		if (!read_input(code, n)) {
			continue;
		}
		do
		{
			if (!read_input(guess, n)) {
				break;
			}
			get_hints(code, guess, n);

		} while (true);
		
	}
	return 0;
}