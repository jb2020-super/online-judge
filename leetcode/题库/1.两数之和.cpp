class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rst;  
        bool finished{false};
        for (int i = 0; i < nums.size() && !finished; ++i){
            int a = nums[i];
            for (int j = i + 1; j < nums.size(); ++j){
                int b = nums[j];
                if (a + b == target){
                    rst.push_back(i);
                    rst.push_back(j);
                    finished = true;
                    break;
                }
            }           
        }        
        
        return rst;
    }
};