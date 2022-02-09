class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int len = nums.size();
        int cnt{0};
        for (int i = 0; i < len - 1; ++i){
            for (int j = i + 1; j < len; ++j){
                auto diff = nums[i] - nums[j];
                if (diff == k || -diff == k){
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};