// uva 1588
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
private:
};

class Kickdown : public ProblemBase2
{
public:
	virtual int GetInput() override
	{
		return scanf("%s%s", _first, _second);
	}
	virtual void RunAlgorithm() override
	{
		int len1 = 0;
		int len2 = 0;		
		len1 = run_impl(_second, _first);
		len2 = run_impl(_first, _second);
		printf("%d\n", std::min(len1, len2));
	}
	int run_impl(char *first, char *second)
	{
		int len1 = strlen(first);
		int len2 = strlen(second);
		for (int i = 0; i < len2; ++i) {
			bool succeed = true;
			for (int j = 0, k = i; j < len1 && k < len2; ++j, ++k) {
				if (first[j] == '2' && second[k] == '2') {
					succeed = false;
					break;
				}
			}
			if (succeed) {
				return std::max(i + len1, len2);
			}
		}
		return len1 + len2;
	}
private:
	const static int MAX_COUNT = 101;
	char _first[MAX_COUNT];
	char _second[MAX_COUNT];
};

int main()
{
	Kickdown kd;
	kd.Loop();
	return 0;
}
/*
Sample Input:
2112112112
2212112
12121212
21212121
2211221122
2121222
21
22
12

Sample Output:
10
8
15
3
3
*/