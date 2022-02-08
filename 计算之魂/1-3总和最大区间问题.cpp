/*
问题描述：
给定一个实数序列，设计一个最有效的算法，找到一个总和最大的区间
*/
#include <iostream>

bool FindFirstPositive(double *pdata, int size, int start, int &idx)
{
	double max = 1.0;
	int i = start;
	while (i < size && pdata[i] <= 0) {
		++i;
		if (max > 0.0 || pdata[i] > max) {
			max = pdata[i];
			idx = i;
		}
	}	
	if (i < size) {
		idx = i;
		return true;
	}
	return false;
}

void LargestSubsquence(double *pdata, int size)
{
	if (!pdata || !size) {
		printf("Invalid data.\n");
		return;
	}
	int idx = -1;
	if (!FindFirstPositive(pdata, size, 0, idx)) {
		printf("%d %d %lf\n", idx, idx, pdata[idx]);
		return;
	}
	int start{ idx }, max_start{ idx };
	int end{ idx }, max_end{ idx };
	double max_sum = pdata[idx];
	double current_sum = max_sum;
	double current_max = max_sum;
	for (int i = idx + 1; i < size; ++i) {
		current_sum += pdata[i];
		if (current_sum < 0) {
			if (current_max > max_sum) {
				max_start = start;
				max_end = end;
				max_sum = current_max;
			}
			
			if (!FindFirstPositive(pdata, size, i + 1, idx)) {
				break;
			}
			start = end = i = idx;
			current_max = current_sum = pdata[idx];
			
		}
		else if (current_sum > current_max)
		{
			end = i;
			current_max = current_sum;
		}
	}
	if (current_max > max_sum) {
		max_start = start;
		max_end = end;
		max_sum = current_max;
	}
	printf("%d %d %lf\n", max_start, max_end, max_sum);
}
int main1()
{
	constexpr int MAX_SIZE = 1000;
	double input_data[MAX_SIZE] = {1.5, -12.3, 3.2, -5.5, 23.2, 3.2, -1.4, -12.2, 34.2, 5.4, -7.8, 1.1, -4.9};
	int cnt = 13;
	LargestSubsquence(input_data, cnt);
	double input_data2[MAX_SIZE] = { 1.5, -12.3, 3.2, -5.5, 23.2, 3.2, -1.4, -62.2, 44.2, 5.4, -7.8, 1.1, -4.9 };
	int cnt2 = 13;
	LargestSubsquence(input_data2, cnt2);
	return 0;
}
