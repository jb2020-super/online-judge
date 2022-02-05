// 1219. »Æ½ð¿ó¹¤
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	bool flg[15][15];
	int dir[4][2]{ -1, 0, 1, 0, 0, 1, 0, -1 };
	int row{};
	int col{};
public:
	int kaiWa(vector<vector<int>>& grid, int x, int y) {
		int max_gold{ 0 };
		for (int i = 0; i < 4; ++i) {
			int x0 = x + dir[i][0];
			int y0 = y + dir[i][1];
			if (x0 >= 0 && x0 < row &&
				y0 >= 0 && y0 < col &&
				!flg[x0][y0] &&
				grid[x0][y0]) {
				flg[x0][y0] = true;
				int gold = kaiWa(grid, x0, y0);
				flg[x0][y0] = false;
				if (gold > max_gold) {
					max_gold = gold;
				}
			}
		}
		return max_gold + grid[x][y];
	}
	int getMaximumGold(vector<vector<int>>& grid) {
		row = grid.size();
		col = grid[0].size();
		int max_gold{ 0 };
		memset(flg, 0, sizeof(flg));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (!grid[i][j]) {
					continue;
				}
				flg[i][j] = true;
				int gold = kaiWa(grid, i, j);
				flg[i][j] = false;
				if (gold > max_gold) {
					max_gold = gold;
				}
			}
		}
		return max_gold;
	}
};

int main()
{
	Solution so;
	vector<vector<int>> grid = {
		{0,6,0},{5,8,7},{0,9,0}
	};
	so.getMaximumGold(grid);
	return 0;
}