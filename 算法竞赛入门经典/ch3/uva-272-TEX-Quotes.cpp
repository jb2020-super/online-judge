// uva-272
#include <iostream>

int main() {
	int ch{};
	bool flg = true;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '"') {
			if (flg) {
				printf("``");
			}
			else
			{
				printf("''");
			}
			flg = !flg;
		}
		else
		{
			putchar(ch);
		}
	}
	return 0;
}