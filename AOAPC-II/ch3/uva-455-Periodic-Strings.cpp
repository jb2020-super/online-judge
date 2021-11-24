// 455 - Periodic Strings
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

class ProblemBase
{
public:
	virtual void GetInput() = 0;
	virtual void RunAlgorithm() = 0;
	void Init() {
		scanf("%d", &T);
	}
	void Loop() {
		for (int i = 0; i < T; ++i) {
			GetInput();
			RunAlgorithm();
		}
	}
private:
	int T{ 0 };
};

class PeriodicStrings : public ProblemBase
{
public:
	// Í¨¹ý ProblemBase ¼Ì³Ð
	virtual void GetInput() override
	{
		scanf("%s", str);
	}
	virtual void RunAlgorithm() override
	{
		m_len = strlen(str);
		int period = m_len;
		for (int i = 1; i <= m_len / 2; ++i) {
			if (m_len % i == 0 &&
				IsValid(i)) 
			{
				period = i;
				break;
			}
		}
		if (m_is_first_cast) {
			m_is_first_cast = false;
		}
		else
		{
			printf("\n");
		}
		printf("%d\n", period);
	}
	bool IsValid(int size)
	{
		int i = 0, j = size;
		while (i < m_len) {
			if (str[i] != str[j]) {
				return false;
			}
			++i;
			j = (j + 1) % size;
		}
		return true;
	}
private:
	static const int MAX_SIZE = 81;
	char str[MAX_SIZE];
	int m_len;
	bool m_is_first_cast = true;
};

int main()
{
	PeriodicStrings ps;
	ps.Init();
	ps.Loop();
	return 0;
}