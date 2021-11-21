/*
韩信点兵：
相传韩信才智过人，从不直接清点自己军队的人数，只要让士兵先后以三人一排、五人一排、七人一排地变换队形，而他每次只掠一眼队伍的排尾就知道总人数了。输入包含多组数据，每组数据包含3个非负整数a，b，c，表示每种队形排尾的人数（a＜3，b＜5，c＜7），输出总人数的最小值（或报告无解）。已知总人数不小于10，不超过100。输入到文件结束为止。
样例输入：
2 1 6
2 1 3
样例输出：
Case 1: 41
Case 2: No answer
*/

#include <iostream>

int main() {
	int a, b, c;
	int cas = 1;
	while (scanf("%d%d%d", &a, &b, &c) != EOF) {
		printf("Case %d: ", cas);
		int i = 10;
		for (; i <= 100; ++i) {
			if (i % 3 == a &&
				i % 5 == b &&
				i % 7 == c)
			{
				printf("%d\n", i);
				break;
			}
		}
		if (i > 100) {
			printf("No answer\n");
		}
		++cas;
	}
	return 0;
}