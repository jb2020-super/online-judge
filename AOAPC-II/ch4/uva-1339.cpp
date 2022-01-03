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

class AncientCipher : public ProblemBase2
{
public:
	virtual int GetInput() override
	{
		return scanf("%s%s", _cipher, _origin);
	}

	virtual void RunAlgorithm() override
	{
		auto len_cipher = strlen(_cipher);
		auto len_origin = strlen(_origin);
		if (len_cipher != len_origin)
			return;
		const int ALPHA_CNT = 26;
		int origin_cnt[ALPHA_CNT]{};
		int cipher_cnt[ALPHA_CNT]{};
		for (int i = 0; i < len_cipher; ++i) {
			cipher_cnt[_cipher[i] - 'A']++;
			origin_cnt[_origin[i] - 'A']++;
		}
		std::sort(cipher_cnt, cipher_cnt + ALPHA_CNT, std::greater<int>());
		std::sort(origin_cnt, origin_cnt + ALPHA_CNT, std::greater<int>());
		for (int i = 1; i < ALPHA_CNT; ++i) {
			if (cipher_cnt[i] != origin_cnt[i]) {
				printf("NO\n");
				return;
			}
			if (!cipher_cnt[i])
				break;
		}
		printf("YES\n");
	}
private:
	const static int MAX_LENGTH = 101;
	char _origin[MAX_LENGTH];
	char _cipher[MAX_LENGTH];
};

int main()
{
	AncientCipher ac;
	ac.Loop();
	return 0;
}