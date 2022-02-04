
// 1725. 可以形成最大正方形的矩形数目
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> len_array;
        int len = rectangles.size();
        for (int i = 0; i < len; ++i){
            len_array.push_back(min(rectangles[i][0], rectangles[i][1]));
        }
        sort(len_array.begin(), len_array.end(), greater<int>());
        int max_len = len_array[0];
        int cnt = 1;
        len = len_array.size();
        for (int i = 1; i < len; ++i){
            if (len_array[i] == max_len){
                cnt++;
            }else{
                break;
            }
        }
        return cnt;
    }
};