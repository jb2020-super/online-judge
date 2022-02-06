//1748. 唯一元素的和
class Solution {
    int cnt[101]{};
public:
    int sumOfUnique(vector<int>& nums) {
        memset(cnt, 0, sizeof(cnt));
        int sum{0};
        int len = nums.size();
        int tmp{};
        for (int i = 0; i < len; ++i){
            tmp = nums[i];
            if (!cnt[tmp]){
                sum += tmp;
                cnt[tmp]++;
            }else if (cnt[tmp] == 1){
                sum -= tmp;
                cnt[tmp]++;
            }
        }
        return sum;
    }
};