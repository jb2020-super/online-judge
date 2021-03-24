#include <vector>
using namespace std;
// [1,2,3,4]
// [3,1,4,2]
// [-1,3,2,0]
// [1,0,1,-4,-3]
// O(n^2)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        bool second_flg{}, third_flg{};
        int second{}, third{};
        for (int i = 0; i < nums.size(); ++i){
            second_flg = third_flg = false;
            for (int j = i + 1; j < nums.size(); ++j){
                if (!second_flg){
                    if (nums[j] > nums[i]){
                        second_flg = true;
                        second = nums[j];
                    }                    
                }else{
                    if (nums[j] < second && nums[j] > nums[i]){
                        third_flg = true;
                        third = nums[j];
                        break;
                    }else if ( nums[j] > second) {
                        second = nums[j];                        
                    }
                }
            }
            if (second_flg && third_flg){
                break;
            }
        }
        if (second_flg && third_flg){
            return true;
        }else{
            return false;
        }
    }
};

int main() {
    Solution so;
    vector<int> nums = { 1,0,1,-4,-3 };
    bool result = so.find132pattern(nums);
    return 0;
}