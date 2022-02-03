// 1414. 和为 K 的最少斐波那契数字数目
#include <iostream>

class Solution {
public:
	Solution() {
		InitFibonacci();
	}
	void InitFibonacci()
	{
		const int MAX_NUM = 1000000000;
		fib[0] = fib[1] = 1;
		cnt = 2;
		for (; fib[cnt-1] < MAX_NUM; ++cnt) {
			fib[cnt] = fib[cnt - 1] + fib[cnt - 2];
			//printf("%d: %d\n", cnt, fib[cnt]);
		}
	}
	// find the largest number <= k
	int BinarySearch(int k) {
		int left = 0;
		int right = cnt - 1;
		int mid = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (fib[mid] == k) {
				return k;
			}
			else if (fib[mid] < k) {
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		if (fib[mid] > k) {
			return fib[mid - 1];
		}
		return fib[mid];
	}
	int findMinFibonacciNumbers(int k) {
		int n = 0;
		while (k > 0) {
			int val = BinarySearch(k);
			n++;
			k -= val;
		}
		return n;
	}
private:
	int fib[50];
	int cnt{ 0 };
};

int main()
{
	Solution so;
	so.findMinFibonacciNumbers(1);
	return 0;
}