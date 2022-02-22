/*
执行用时：
180 ms, 在所有 C++ 提交中击败了94.44%的用户
内存消耗：
179.2 MB, 在所有 C++ 提交中击败了59.72%的用户
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    const static int N = 31;
    const static int PAIR_SIZE = 7;
    const static long long MODE = 1000000007;
    vector<int> prime = {
        1, 2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30
    };
    int pair[PAIR_SIZE][3] = {
        {6, 2, 3},
        {10, 2, 5},
        {14, 2, 7},
        {15, 3, 5},
        {21, 3, 7},
        {22, 2, 11},
        {26, 2, 13}
    };
	long long m_rst{};
public:
    void permute(const vector<int>& nums, vector<int>& flg, vector<int>& count, int idx, long long rst){
        if (idx >= nums.size()){
			m_rst = (m_rst + rst) % MODE;
            return;
        }
        int c = nums[idx];
		if (c == 30) {
			if (!flg[2] && !flg[3] && !flg[5]) {
				++flg[30];
				++flg[2];
				++flg[3];
				++flg[5];
				long long rst1 = (rst * (count[c])) % MODE;
				permute(nums, flg, count, idx + 1, rst1);
				--flg[30];
				--flg[2];
				--flg[3];
				--flg[5];
			}
			permute(nums, flg, count, idx + 1, rst);
			return;
		}
        bool is_special{false};
        for (int i = 0; i < PAIR_SIZE; ++i){            
            if (c == pair[i][0]){
				if (!flg[pair[i][1]] && !flg[pair[i][2]]) {
					++flg[pair[i][1]];
					++flg[pair[i][2]];
					++flg[pair[i][0]];
					long long rst1 = (rst * (count[c])) % MODE;
					permute(nums, flg, count, idx + 1, rst1);
					--flg[pair[i][1]];
					--flg[pair[i][2]];
					--flg[pair[i][0]];
				}
				permute(nums, flg, count, idx + 1, rst);				
				is_special = true;
                break;
            }
        }
        if (!is_special){
            ++flg[c];
			long long rst1 = (rst * (count[c])) % MODE;
            permute(nums, flg, count, idx + 1, rst1);
            --flg[c];
            permute(nums, flg, count, idx + 1, rst);
        }
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> count(N, -1);
        for (auto i : prime){
            count[i] = 0;
        }
        for (auto i : nums){
            if (count[i] >= 0){
                ++count[i];
            }
        }
        vector<int> vals;
        for (int i = 2; i < N; ++i){
            if (count[i] > 0){
                vals.push_back(i);
            }
        }
        vector<int> flg(N, 0);
        long long rst{1};
		m_rst = 0;
        permute(vals, flg, count, 0, rst);
        --m_rst;
/*        for (auto i : vals){            
            m_rst = (m_rst * count[i]) % MODE;            
        }	*/	
		for (int i = 0; i < count[1]; ++i) {
			m_rst = (m_rst * 2) % MODE;
		}
        return m_rst;
    }
};

int main()
{
	Solution so;
	//vector<int> nums{ 4, 2, 3, 15 };
	//vector<int> nums{ 2,3,5,6,7,10,11,13,14,15,17,19,21,22,23,26,29,2,3,5,2,3,5,6,10,7,6,10,25,15,21,22,27,26 };
	//vector<int> nums{ 1, 1, 1, 1, 2, 3, 4, 5 };
	vector<int> nums{ 2,2,3 };
	
	int rst = so.numberOfGoodSubsets(nums);
	std::cout << rst << std::endl;
	return 0;
}