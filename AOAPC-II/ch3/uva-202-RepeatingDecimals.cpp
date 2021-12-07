// uva 202
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

class ProblemBase2
{
public:
	virtual int GetInput() = 0;
	virtual void RunAlgorithm() = 0;

	void Loop() {
		while (GetInput() != EOF) {
			RunAlgorithm();
		}
	}
protected:
	bool _is_first = true;
private:
};

class RepeatingDecimals : public ProblemBase2
{
public:
	virtual int GetInput() override
	{
		return scanf("%d%d", &_numerator, &_denominator);
	}

	virtual void RunAlgorithm() override
	{
		memset(_remainders, 0, sizeof(_remainders));
		memset(_quotients, 0, sizeof(_quotients));
		int end = 1;
		int start = 1;
		_integer = _numerator / _denominator;
		int remainder = _numerator % _denominator;
		_remainders[0] = remainder;
		
		while (remainder) {
			_quotients[end] = (remainder * 10) / _denominator;
			remainder = (remainder * 10) % _denominator;
			_remainders[end] = remainder;
			int rst = SearchEqual(remainder, end++);
			if (rst >= 0) {
				start = rst + 1;
				break;
			}
		}
		if (!remainder) {
			start = end;
			end++;
		}
		print(start, end);
	}
	int SearchEqual(int rm, int cnt)
	{
		for (int i = 0; i < cnt; ++i) {
			if (_remainders[i] == rm) {
				return i;
			}
		}
		return -1;
	}
	void print(int start, int end)
	{
		printf("%d/%d = %d.", _numerator, _denominator, _integer);
		for (int i = 1; i < end && i <= 50; ++i) {
			if (i == start) {
				printf("(");
			}
			printf("%d", _quotients[i]);
		}
		if (end > 51) {
			printf("...)");
		}
		else
		{
			printf(")");
		}
		printf("\n");
		printf("   %d = number of digits in repeating cycle\n\n", end - start);
	}
private:
	const static int MAX_SIZE = 3000; //Runtime caused by a smaller MAX_SIZE
	int _numerator;
	int _denominator;
	int _integer;
	int _remainders[MAX_SIZE];
	int _quotients[MAX_SIZE];
};

int main()
{
	RepeatingDecimals rd;
	rd.Loop();
	return 0;
}