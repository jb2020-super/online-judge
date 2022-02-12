class Solution {
    int dir[4][2]{
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };
    int m{};
    int n{};
public:
    void search(vector<vector<int>>& grid, int x, int y, int &area){
        for (int i = 0; i < 4; ++i){
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] == 1){
                ++area;
                grid[x1][y1] = -1;
                search(grid, x1, y1, area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int max_area{0};
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    int area{1};
                    grid[i][j] = -1;
                    search(grid, i, j, area);
                    if (area > max_area){
                        max_area = area;
                    }
                }
            }
        }
        return max_area;
    }
};