// 广度优先搜索，用了队列结构，结果时间和空间都比较慢
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
	int m;
	int n;
	int total{ 0 };
public:
	struct Pos {
		int x;
		int y;
	};
	void search(vector<vector<int>>& grid, int x, int y) {
		int dir[4][2]{
			{0, -1},
			{0, 1},
			{-1, 0},
			{1, 0}
		};
		queue<Pos> qu;
		qu.push({ x, y });
		grid[x][y] = -1;
		int cnt{ 1 };
		bool flg{ false };
		while (!qu.empty()) {
			auto pos = qu.front();
			qu.pop();
			
			for (int i = 0; i < 4; ++i) {
				int x1 = pos.x + dir[i][0];
				int y1 = pos.y + dir[i][1];
				if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n) {
					if (grid[x1][y1] == 1) {
						qu.push({ x1, y1 });
						++cnt;
						grid[x1][y1] = -1;
					}
				}
				else {
					flg = true;
				}
			}
		}
		if (!flg) {
			total += cnt;
		}
	}
	int numEnclaves(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		total = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) {
					search(grid, i, j);
				}
			}
		}
		return total;
	}
};

int main()
{
	vector<vector<int>> grid{
	{0,0,0,1,1,1,0,1,1,1,1,1,0,0,0},
	{1,1,1,1,0,0,0,1,1,0,0,0,1,1,1},
	{1,1,1,0,0,1,0,1,1,1,0,0,0,1,1},
	{1,1,0,1,0,1,1,0,0,0,1,1,0,1,0},
	{1,1,1,1,0,0,0,1,1,1,0,0,0,1,1},
	{1,0,1,1,0,0,1,1,1,1,1,1,0,0,0},
	{0,1,0,0,1,1,1,1,0,0,1,1,1,0,0},
	{0,0,1,0,0,0,0,1,1,0,0,1,0,0,0},
	{1,0,1,0,0,1,0,0,0,0,0,0,1,0,1},
	{1,1,1,0,1,0,1,0,1,1,1,0,0,1,0}
	};
	Solution so;
	so.numEnclaves(grid);
	return 0;
}