class Solution {
    const static int MAX_N{25};
    double grid[MAX_N][MAX_N];
    double grid_tmp[MAX_N][MAX_N];
    int dir[8][2]{
        {-2, -1},
        {-1, -2},
        {1, -2},
        {2, -1},
        {2, 1},
        {1, 2},
        {-1, 2},
        {-2, 1}
    };
    double rat{1.0/8.0};
public:
    void initGrid(double pp[MAX_N][MAX_N], int n, double val)
    {
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                pp[i][j] = val;
            }
        }
    }
    double knightProbability(int n, int k, int row, int column) {
        initGrid(grid, n, -1.0);
        grid[row][column] = 1.0;
        for (int i = 0; i < k; ++i){
            initGrid(grid_tmp, n, 0.0);
            for (int p = 0; p < n; ++p){
                for (int q = 0; q < n; ++q){
                    if (grid[p][q] > 0.0){
                        for (int j = 0; j < 8; ++j){
                            int x = p + dir[j][0];
                            int y = q + dir[j][1];
                            if (x >= 0 && x < n && y >= 0 && y < n){
                                grid_tmp[x][y] += rat * grid[p][q];
                            }
                        }
                    }
                }
            }
            for (int p = 0; p < n; ++p){
                for (int q = 0; q < n; ++q){
                    if (grid_tmp[p][q] > 0.0){
                        grid[p][q] = grid_tmp[p][q];
                    }else {
                        grid[p][q] = -1.0;
                    }
                }
            }
        }
        double sum{0.0};
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] > 0.0){
                    sum += grid[i][j];
                }
            }
        }
        return sum;
    }
};