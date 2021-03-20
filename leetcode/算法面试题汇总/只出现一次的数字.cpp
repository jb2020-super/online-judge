#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int res{nums[0]};
        for (int i = 1; i < nums.size(); ++i){
            res ^= nums[i];
        }
        return res;
    }
};

int main(){
    std::vector<int> input{4,1,2,1,2};
    Solution sol;
    auto output = sol.singleNumber(input);
    if (output == 4){
        std::cout << "Accepted" << std::endl;
    }else {
        std::cout << "Wrong answer" << std::endl;
    }
    return 0;
}