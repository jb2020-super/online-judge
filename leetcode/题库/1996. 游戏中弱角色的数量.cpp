/*
Accepted but very bad running time.
但是如果本题的数值范围是小数或者范围很大时，这种方法也可一用。
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
速度最快的算法解读：
1.利于了数值范围最大是10^5的条件；
2.数值的第一维是攻击力，第二维是防御力；
3.数组b的含义，b[k]代表攻击力为k的角色中，防御力最大的那个值；
4.mn记录了最大的攻击力数值；
5.数组r的含义，r[j]代表比攻击力j大的那些角色中，防御力最大的数值；
6.b和r数组预处理好之后，对于给定的一个角色数值[x,y]，查询r[x]得到比攻击力x大的角色中防御力的最大数值；
如果r[x] > y，则说明此角色是弱角色。
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