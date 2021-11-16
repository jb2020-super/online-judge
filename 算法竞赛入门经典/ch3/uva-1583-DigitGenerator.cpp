// uva 1583 - Digit Generator
#include <iostream>
#include <cmath>
#include <algorithm>

int generate(int num)
{
	int gen = num;
	while (num > 0) {
		gen += num % 10;
		num /= 10;
	}
	return gen;
}

int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		int n = 0;
		scanf("%d", &n);
		int gen_smallest = 0;
		int range = static_cast<int>(ceil(log10(n) + 0.5)) * 9;
		int idx = std::max(1,  n - range);
		while (idx < n) {
			int gen = generate(idx);
			if (gen == n) {
				gen_smallest = idx;
				break;
			}
			++idx;
		}
		printf("%d\n", gen_smallest);
	}
	return 0;
}