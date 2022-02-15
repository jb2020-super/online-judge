class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rst;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i){
            int min{matrix[i][0]};
            int min_idx{0};
            for (int j = 1; j < n; ++j){
                if (matrix[i][j] < min){
                    min = matrix[i][j];
                    min_idx = j;
                }
            }
            int max{matrix[0][min_idx]};
            int max_idx{0};
            for (int k = 1; k < m; ++k){
                if (matrix[k][min_idx] > max){
                    max = matrix[k][min_idx];
                    max_idx = k;
                }
            }
            if (i == max_idx){
                rst.push_back(min);
            }
        }
        return rst;
    }
};