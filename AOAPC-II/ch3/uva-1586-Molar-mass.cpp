// uva 1586 Molar mass
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

int get_num(const char *pstart, const char *pend)
{
	int num = 0;
	while (pstart < pend)
	{
		if (isdigit(*pstart)) {
			num = num * 10 + (*pstart - '0');
			++pstart;
		}
		else
		{
			break;
		}		
	}
	return std::max(num, 1);
}

float get_mass(const char *pin)
{
	float mass = 0.0f;
	int len = strlen(pin);
	const char *pstart = pin;
	const char *pend = pin + len;
	const int BUFFER_SIZE = 27;
	int count[BUFFER_SIZE];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < len; ++i) {
		int num = get_num(pin + i + 1, pend);		
		count[pin[i] - 'A'] += num;
		if (num > 1 && num < 10) {
			++i;
		}
		else if (num >= 10)
		{
			i += 2;
		}		
	}
	mass += count['C' - 'A'] * 12.01f;
	mass += count['H' - 'A'] * 1.008f;
	mass += count['O' - 'A'] * 16.0f;
	mass += count['N' - 'A'] * 14.01;
	return mass;
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
		printf("%.3f\n", get_mass(input));
	}
	return 0;
}