// uva 1584	Circular Sequence
#include <iostream>
#include <cstring>

// -1, a < b
// 0, a == b
// 1, a > b
// other, error

int compare_string(const char *str, const int len, int idx_a, int idx_b)
{
	if (!str ||
		idx_a < 0 || idx_a >= len ||
		idx_b < 0 || idx_b >= len) {
		return -2;
	}
	int i = 0;
	while (i < len) {
		if (str[idx_a] < str[idx_b]){
			return -1;
		}
		else if (str[idx_a] > str[idx_b]) {
			return 1;
		}
		idx_a = (idx_a + 1) % len;
		idx_b = (idx_b + 1) % len;
		++i;
	}
	return 0;
}

int main()
{
	int T = 0;
	const int MAX_SIZE = 101;
	char seq[MAX_SIZE];
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%s", seq);
		int len = strlen(seq);		
		int smallest_idx = 0;
		for (int j = 1; j < len; ++j) {
			int rst = compare_string(seq, len, smallest_idx, j);
			if (rst == 1) {
				smallest_idx = j;
			}
		}
		for (int j = 0, idx = smallest_idx; j < len; ++j) {
			printf("%c", seq[idx]);
			idx = (idx + 1) % len;
		}
		printf("\n");
	}
	return 0;
}