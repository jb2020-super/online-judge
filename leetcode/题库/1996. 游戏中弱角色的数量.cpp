#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		sort(properties.begin(), properties.end(), [](vector<int>& first, vector<int>& second) {
			if (first[0] != second[0]) {
				return first[0] < second[0];
			}
			return first[1] < second[1];
		});
		int len = properties.size();
		vector<int> range_max(len, 0);
		vector<int> range_max2(len, 0);
		int max_val = properties[len - 1][1];
		int max_val2 = properties[len - 1][0];
		for (int i = len - 1; i >= 0; --i) {
			if (properties[i][1] > max_val) {
				max_val = properties[i][1];
			}
			range_max[i] = max_val;
			if (properties[i][0] > max_val2) {
				max_val2 = properties[i][0];
			}
			range_max2[i] = max_val2;
		}
		int count = 0;
		for (int i = 0; i < len; ++i) {
			if (properties[i][1] < range_max[i] && properties[i][0] < range_max2[i]) {
				++count;
			}
		}
		return count;
	}
};
/*
[[5,5],[6,3],[3,6]]
[[2,2],[3,3]]
[[1,5],[10,4],[4,3]]
[[2,3],[3,2]]
[[1,1],[1,1]]
[[1,1],[2,2],[3,3]]
[[3,3],[2,2],[1,1]]
[[3,3],[2,2],[1,1],[4,4]]
[[1,1],[2,1],[2,2],[1,2]]
*/