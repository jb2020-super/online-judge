#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	struct Data {
		int x;
		int y;
		int height;
	};
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		auto m = isWater.size();
		auto n = isWater[0].size();
		queue<Data> q;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (isWater[i][j]) {
					q.push({ i, j, 0});
					isWater[i][j] = 0;
				}
				else
				{
					isWater[i][j] = -1;
				}
			}
		}
		int dir[4][2] = {
			-1, 0,
			1, 0,
			0, -1,
			0, 1
		};
		while (!q.empty()) {
			auto pos = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int x = pos.x + dir[i][0];
				int y = pos.y + dir[i][1];
				if (x >= 0 && x < m &&
					y >= 0 && y < n &&
					isWater[x][y] < 0) {
					q.push({ x, y, pos.height + 1 });
					isWater[x][y] = pos.height + 1;
				}
			}
		}
		return isWater;
	}
};