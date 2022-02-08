#include <vector>
#include <map>
#include <set>

#include <iostream>
using namespace std;
class Solution {
public:
	vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
		map<int, int> lighted_rows;
		map<int, int> lighted_cols;
		map<int, int> lighted_slash;
		map<int, int> lighted_backslash;
		set<long long> lamps_pos;
		long long base = 1000000000L;
		for (const auto& pos : lamps) {
			long long posll = static_cast<long long>(pos[0]) * base + pos[1];
			if (lamps_pos.find(posll) != lamps_pos.end()) {
				continue;
			}
			lamps_pos.insert(posll);
			{
				auto it = lighted_rows.find(pos[0]);
				if (it == lighted_rows.end()) {
					lighted_rows.insert({ pos[0], 1 });
				}
				else {
					++(it->second);
				}
			}
			{
				auto it = lighted_cols.find(pos[1]);
				if (it == lighted_cols.end()) {
					lighted_cols.insert({ pos[1], 1 });
				}
				else {
					++(it->second);
				}
			}
			{
				auto it = lighted_slash.find(pos[1] - pos[0]);
				if (it == lighted_slash.end()) {
					lighted_slash.insert({ pos[1] - pos[0], 1 });
				}
				else {
					++(it->second);
				}
			}
			{
				auto it = lighted_backslash.find(pos[0] + pos[1]);
				if (it == lighted_backslash.end()) {
					lighted_backslash.insert({ pos[0] + pos[1], 1 });
				}
				else {
					++(it->second);
				}
			}
		}
		vector<int> rst(queries.size(), 0);
		int dir[9][2] = {
			{-1, -1},
			{-1, 0},
			{-1, 1},
			{0, -1},
			{0, 0},
			{0, 1},
			{1, -1},
			{1, 0},
			{1, 1}
		};
		int k{ 0 };
		for (const auto& pos : queries) {
			bool find{ false };
			do {
				if (lighted_rows.find(pos[0]) != lighted_rows.end()) {
					find = true;
					break;
				}
				if (lighted_cols.find(pos[1]) != lighted_cols.end()) {
					find = true;
					break;
				}
				if (lighted_slash.find(pos[1] - pos[0]) != lighted_slash.end()) {
					find = true;
					break;
				}
				if (lighted_backslash.find(pos[0] + pos[1]) != lighted_backslash.end()) {
					find = true;
					break;
				}
			} while (false);
			if (find) {
				rst[k++] = 1;
			}
			else {
				rst[k++] = 0;
			}
			for (int i = 0; i < 9; ++i) {
				int x = pos[0] + dir[i][0];
				int y = pos[1] + dir[i][1];
				if (x >= 0 && x < n && y >= 0 && y < n) {
					long long posll = static_cast<long long>(x) * base + y;
					if (lamps_pos.find(posll) != lamps_pos.end()) {
						lamps_pos.erase(posll);
						{
							auto it = lighted_rows.find(x);
							--(it->second);
							if (!it->second) {
								lighted_rows.erase(it);
							}
						}
						{
							auto it = lighted_cols.find(y);
							--(it->second);
							if (!it->second) {
								lighted_cols.erase(it);
							}
						}
						{
							auto it = lighted_slash.find(y - x);
							--(it->second);
							if (!it->second) {
								lighted_slash.erase(it);
							}
						}
						{
							auto it = lighted_backslash.find(x + y);
							--(it->second);
							if (!it->second) {
								lighted_backslash.erase(it);
							}
						}
					}
				}
			}

		}
		return rst;
	}
};
int main()
{
	Solution so;
	
	vector<vector<int>> lamps{ {1,1} };
	vector<vector<int>> queries{ {2, 0},{1, 0} };

	so.gridIllumination(6, lamps, queries);
	return 0;
}
/*
6
[[1,1]]
[[2,0],[1,0]]
*/