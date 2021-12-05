// uva 1368
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

class DNAConsensusString : public ProblemBase
{
public:
	virtual void GetInput() override
	{
		scanf("%d%d", &m, &n);
		for (int i = 0; i < m; ++i) {
			scanf("%s", dna[i]);
		}
	}
	virtual void RunAlgorithm() override
	{
		memset(result, 0, sizeof(result));
		distance = 0;
		int a = 0, t = 0, c = 0, g = 0;
		for (int i = 0; i < n; ++i) {
			a = 0, t = 0, c = 0, g = 0;
			for (int j = 0; j < m; ++j) {
				if (dna[j][i] == 'A') {
					a++;
				}
				else if (dna[j][i] == 'T') {
					t++;
				}
				else if (dna[j][i] == 'C') {
					c++;
				}
				else
				{
					g++;
				}
			}
			result[i] = GetSmallest(a, t, c, g);
		}
		printf("%s\n%d\n", result, distance);
	}
	char GetSmallest(int a, int t, int c, int g)
	{
		int larger = a;
		char ch = 'A';
		if (c > larger) {
			ch = 'C';
			larger = c;
		}
		if (g > larger) {
			ch = 'G';
			larger = g;
		}
		if (t > larger) {
			ch = 'T';
			larger = t;
		}

		if (ch != 'A') {
			distance += a;
		}
		if (ch != 'T') {
			distance += t;
		}
		if (ch != 'C') {
			distance += c;
		}
		if (ch != 'G') {
			distance += g;
		}
		return ch;
	}
private:	
	const static int MAX_LEN = 1001;
	int m;
	int n;
	int distance;
	char dna[51][MAX_LEN];
	char result[MAX_LEN];
};

int main()
{
	DNAConsensusString dna;
	dna.Init();
	dna.Loop();
	return 0;
}