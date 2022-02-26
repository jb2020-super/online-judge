class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_diff{-1};
        int n = nums.size();
        for (int i = 1; i < n; ++i){
            for (int j = i - 1; j >= 0; --j){
                int diff = nums[i] - nums[j];
                if (diff > 0 && diff > max_diff){
                    max_diff = diff;
                }
                if (diff <= 0){
                    break;
                }
            }
        }
        return max_diff;
    }
};


class Solution1 {
public:
    int maximumDifference(vector<int>& nums) {
        int max_diff{-1};
        int n = nums.size();
        int min_val{nums[0]};
        for (int i = 1; i < n; ++i){
            if (nums[i] > min_val){
                auto diff = nums[i] - min_val;
                if (max_diff < diff){
                    max_diff = diff;
                }
            }else if (nums[i] < min_val){
                min_val = nums[i];
            }
        }
        return max_diff;
    }
};