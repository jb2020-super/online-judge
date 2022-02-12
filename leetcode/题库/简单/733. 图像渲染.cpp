class Solution {
    int m_target;
    int m_newColor;
    int dir[4][2]{
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };
    int m;
    int n;
public:
    void search(vector<vector<int>>& image, int x, int y){
        for (int i = 0; i < 4; ++i){
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && image[x1][y1] == m_target){
                image[x1][y1] = m_newColor;
                search(image, x1, y1);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m_target = image[sr][sc];
        m_newColor = newColor;
        if (m_target == m_newColor){
            return image;
        }
        m = image.size();
        n = image[0].size();
        image[sr][sc] = newColor;
        search(image, sr, sc);
        return image;
    }
};