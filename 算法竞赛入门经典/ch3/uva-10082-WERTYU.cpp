// UVA 10082 WERTYU
#include <iostream>
#include <cstring>

int main()
{
	char mima[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	int len = strlen(mima);
	int ch{};
	while ((ch = getchar()) != EOF) {
		if (isspace(ch)) {
			putchar(ch);
			continue;
		}
		int i = 0;
		for (; i < len; ++i) {
			if (mima[i] == ch && i > 0) {
				putchar(mima[i - 1]);
				break;
			}
		}
		if (i >= len) {
			putchar(ch);
		}
	}
	return 0;
}