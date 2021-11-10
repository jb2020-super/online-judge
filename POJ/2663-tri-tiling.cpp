// poj-2663
#include <iostream>

int main() {
	const int MAX_COUNT = 31;
	int result[MAX_COUNT];
	memset(result, 0, sizeof(result));
	result[0] = 1;
	int cum = 0;
	for (int i = 2; i < MAX_COUNT; i += 2) {
		result[i] = 3 * result[i - 2];
		result[i] += cum * 2;
		cum += result[i - 2];
		//printf("%d\n", result[i]);
	}
	int n = 0;
	while (scanf("%d", &n) != EOF && n != -1) {
		printf("%d\n", result[n]);
	}

	return 0;
}