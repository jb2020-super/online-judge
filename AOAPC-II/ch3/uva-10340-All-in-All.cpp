// uva 10340
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

class AllInAll : public ProblemBase2
{
public:
	virtual int GetInput() override
	{
		return scanf("%s%s", _s, _t); // return 0 will result into TLE
	}

	virtual void RunAlgorithm() override
	{
		auto s_len = strlen(_s);
		auto t_len = strlen(_t);
		if (s_len > t_len) {
			printf("No\n");
			return;
		}
		int s_idx = 0;
		int t_idx = 0;
		while (s_idx < s_len && t_idx < t_len && (s_len - s_idx) <= (t_len - t_idx)) {
			if (_s[s_idx] == _t[t_idx]) {
				++s_idx;
				++t_idx;
			}
			else
			{
				++t_idx;
			}
		}
		if (s_idx == s_len) {
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
private:
	const static int MAX_SIZE = 100000; // Not enough MAX_SIZE will result into Runtime Error
	char _s[MAX_SIZE];
	char _t[MAX_SIZE];
};

int main()
{
	AllInAll aia;
	aia.Loop();
	return 0;
}