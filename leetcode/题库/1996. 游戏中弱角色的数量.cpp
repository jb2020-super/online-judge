/*
Accepted but very bad running time.
��������������ֵ��Χ��С�����߷�Χ�ܴ�ʱ�����ַ���Ҳ��һ�á�
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		sort(properties.begin(), properties.end(), [](vector<int>& first, vector<int>& second) {
			if (first[0] != second[0]) {
				return first[0] < second[0];
			}
			return first[1] < second[1];
		});
		int len = properties.size();
		for (int i = 0; i < len; ++i) {
			properties[i].push_back(i);
		}
		sort(properties.begin(), properties.end(), [](vector<int>& first, vector<int>& second) {
			if (first[1] != second[1]) {
				return first[1] < second[1];
			}
			return first[0] < second[0];
		});
		for (int i = 0; i < len; ++i) {
			properties[i][2] += i;
		}
		sort(properties.begin(), properties.end(), [](vector<int>& first, vector<int>& second) {
			if (first[2] != second[2]) {
				return first[2] < second[2];
			}
			else if (first[0] != second[0]) {
				return first[0] < second[0];
			}
			return first[1] < second[1];
		});

		int count = 0;
		int last = 0;
		for (int i = 0; i < len; ++i) {
			if (last > 0) {
				if (properties[last][0] > properties[i][0] &&
					properties[last][1] > properties[i][1]) {
					++count;
					continue;
				}
			}
			for (int j = len - 1; j > i; --j) {
				if ((properties[j][2] < properties[i][2] + 2) /*||
					(properties[j][0] + properties[j][1]) < (properties[i][0] + properties[i][1] + 2)*/) {
					break;
				}
				if (properties[j][0] > properties[i][0] &&
					properties[j][1] > properties[i][1]) {
					++count;
					last = j;
					break;
				}
			}
		}
		return count;
	}
};
/*
[[5,5],[6,3],[3,6]]
[[2,2],[3,3]]
[[1,5],[10,4],[4,3]]
[[2,3],[3,2]]
[[1,1],[1,1]]
[[1,1],[2,2],[3,3]]
[[3,3],[2,2],[1,1]]
[[3,3],[2,2],[1,1],[4,4]]
[[1,1],[2,1],[2,2],[1,2]]
[[7,9],[10,7],[6,9],[10,4],[7,5],[7,10]]
*/
/*
�ٶ������㷨�����
1.��������ֵ��Χ�����10^5��������
2.��ֵ�ĵ�һά�ǹ��������ڶ�ά�Ƿ�������
3.����b�ĺ��壬b[k]��������Ϊk�Ľ�ɫ�У������������Ǹ�ֵ��
4.mn��¼�����Ĺ�������ֵ��
5.����r�ĺ��壬r[j]����ȹ�����j�����Щ��ɫ�У�������������ֵ��
6.b��r����Ԥ�����֮�󣬶��ڸ�����һ����ɫ��ֵ[x,y]����ѯr[x]�õ��ȹ�����x��Ľ�ɫ�з������������ֵ��
���r[x] > y����˵���˽�ɫ������ɫ��
*/
class SolutionFastest {
public:
	int b[100005], r[100005];
	int numberOfWeakCharacters(vector<vector<int>>& a) {
		int n = a.size(), cnt = 0, mx = 0, mn = 0;
		for (int i = 0; i < n; ++i) {
			b[a[i][0]] = max(b[a[i][0]], a[i][1]);
			mn = max(mn, a[i][0]);
		}
		for (int i = mn; ~i; --i) {
			r[i] = max(r[i + 1], mx);
			mx = max(mx, b[i]);
		}
		for (int i = 0; i < n; ++i) {
			if (r[a[i][0]] > a[i][1]) cnt++;
		}
		return cnt;
	}
};