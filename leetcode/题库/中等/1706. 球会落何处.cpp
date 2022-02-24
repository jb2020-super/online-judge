class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rst(n, -1);
        for (int k = 0; k < n; ++k){
            int col = k;
            for (int i = 0; i < m; ++i){
                if (grid[i][col] == 1){
                    if (col + 1 < n && grid[i][col + 1] == 1){
                        ++col;
                    }else{
                        col = -1;
                        break;
                    }
                }else{
                    if (col - 1 >= 0 && grid[i][col - 1] == -1){
                        --col;
                    }else{
                        col = -1;
                        break;
                    }
                }
            }
            rst[k] = col;
        }
        return rst;
    }
};