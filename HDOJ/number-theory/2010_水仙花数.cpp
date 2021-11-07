#include <cstdio>
// HDOJ 2010
bool IsShuiXianHuaNum(int num) {
	int a = num / 100;
	int b = (num % 100) / 10;
	int c = num % 10;
	if (num == a * a * a + b * b * b + c * c * c) {
		return true;
	}
	return false;
}

int main()
{
	int m{}, n{};
	while (scanf("%d%d", &m, &n) != EOF) {
		int cnt = 0;
		for (int i = m; i <= n; ++i) {
			if (IsShuiXianHuaNum(i)) {
				if (cnt) {
					printf(" ");
				}
				printf("%d", i);
				++cnt;
			}
		}
		if (!cnt) {
			printf("no");
		}
		printf("\n");
	}
	return 0;
}