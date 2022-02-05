//283. 移动零
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();        
        int j = 0;
        for (int i = 0; i < len; ++i){
            if (nums[i]){                
                nums[j++] = nums[i];
            }            
        }
        while (j < len){
            nums[j++] = 0;
        }
    }
};