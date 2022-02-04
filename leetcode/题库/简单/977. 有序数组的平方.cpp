//977. 有序数组的平方
// 排序，双指针
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> squares;
        for (int i = 0; i < len; ++i){
            squares.push_back(nums[i] * nums[i]);
        }
        sort(squares.begin(), squares.end());
        return squares;
    }
};