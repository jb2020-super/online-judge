// uva 1585 Score, EASY, ×Ö·û´®Í³¼Æ
#include <iostream>
#include <cstring>

int get_score(const char *pin)
{
	int len = strlen(pin);
	int sum = 0;
	int score = 1;
	for (int i = 0; i < len; ++i) {
		if (pin[i] == 'O') {
			sum += score;
			score++;
		}
		else
		{
			score = 1;
		}
	}
	return sum;
}

int main()
{
	int T = 0;
	const int MAX_SIZE = 81;
	char input[MAX_SIZE];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", input);
		printf("%d\n", get_score(input));		
	}
	return 0;
}