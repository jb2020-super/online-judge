class Solution {
public:
    int singleNonDuplicateSlow(vector<int>& nums) {
        int rst = nums[0];
        int len = nums.size();
        for (int i = 1; i < len; ++i){
            rst ^= nums[i];
        }
        return rst;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int left{0};
        int len = nums.size();
        int right = len - 1;
        int mid_val{0};
        while (left <= right){
            int mid = (left + right) >> 1;
            mid_val = nums[mid];
            bool left_equal = (mid - 1 >= 0) ? (nums[mid - 1] == mid_val) : false;
            bool right_equal = (mid + 1 < len) ? (nums[mid + 1] == mid_val) : false;
            if (!left_equal && !right_equal){
                return mid_val;
            }
            if (((mid & 1) && left_equal) ||
             (!(mid & 1) && right_equal)){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return mid_val;
    }
};