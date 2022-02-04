#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	void revArray(int *start, int n)
	{
		for (int i = 0, j = n; i < j; ++i, --j) {
			swap(start[i], start[j]);
		}
	}
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k %= len;
		if (!k) {
			return;
		}
		revArray(nums.data(), len - 1);
		revArray(nums.data(), k - 1);
		revArray(nums.data() + k, len - k - 1);
	}
};

class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (k > size){
            k = k % size;
        }
        if (k == 0)
            return;
        int a = size;
        int b = k;
        int c = 0;
        int gdc = 1;
        do{
            c = a % b;
            if (c == 0)
                break;
            a = b;
            b = c;
        }while(true);
        gdc = b;
        int pre = 0, tmp = 0;
        for (int i = 0; i < gdc; ++i){
            int pos = i;
            pre = nums[pos];
            for (int j = 0; j < size / gdc; ++j){
                pos = (pos + k) % size;
                tmp = nums[pos];
                nums[pos] = pre;
                pre = tmp;
            }
        }
    }
};

int main()
{
	Solution so;
	vector<int> nums{ 1,2,3,4,5,6,7 };
	so.rotate(nums, 3);
	return 0;
}