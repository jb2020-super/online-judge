// uva 401 Palindromes
#include <iostream>
#include <cstring>


char get_mirror(char ch)
{
	static char mima[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	static int mima_len = strlen(mima);
	char mir = ch;
	if (isdigit(ch)) {
		mir = mima[ch - '1' + 26];
	}
	else
	{
		mir = mima[ch - 'A'];
	}
	return mir;
}

int main()
{
	char result[][32] = {
		"is not a palindrome",
		"is a mirrored string",
		"is a regular palindrome",
		"is a mirrored palindrome"
	};
	
	const int BUFFER_SIZE = 30;
	char str[BUFFER_SIZE];
	while (scanf("%s", str) != EOF)
	{
		int is_palindrome = 1;
		int is_mirrored = 1;
		int first = 0;
		int last = strlen(str) - 1;
		while (first <= last)
		{
			if (get_mirror(str[first]) != str[last]) {
				is_mirrored = 0;
			}
			if (str[first] != str[last]) {
				is_palindrome = 0;
			}
			if (!is_mirrored && !is_palindrome)
				break;
			++first;
			--last;
		}
		printf("%s -- %s.\n\n", str, result[is_palindrome * 2 + is_mirrored]);
	}
	return 0;
}