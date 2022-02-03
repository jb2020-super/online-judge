class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left{0};
        int right = nums.size() - 1;
        int mid{0};
        int mid_val{0};
        while (left <= right){
            mid = (left + right) >> 1;
            mid_val = nums[mid];
            if (mid_val == target){
                return mid;
            }else if (mid_val < target){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        if (mid_val < target){
            mid++;
        }
        return mid;
    }
};