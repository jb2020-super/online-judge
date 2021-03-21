/*
摩尔投票法
*/
#include <vector>
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int major{}, count{};        
        for (auto num : nums){
            if (count == 0){
                major = num;
                count = 1;
                continue;
            }
            if (major == num){
                count++;
            }else{
                count--;
            }
        }
        return major;
    }
};