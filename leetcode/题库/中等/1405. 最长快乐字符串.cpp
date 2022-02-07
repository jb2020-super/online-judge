// 1405. 最长快乐字符串
#include <string>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;
class Solution {
	struct Trip {
		char ch;
		int cnt;
	}tri[3];
public:
	void sortTriple(int a, int b, int c) {
		tri[0].ch = 'a';
		tri[0].cnt = a;
		tri[1].ch = 'b';
		tri[1].cnt = b;
		tri[2].ch = 'c';
		tri[2].cnt = c;
		sort(tri, tri + 3, [](const Trip& a, const Trip& b) { return a.cnt > b.cnt; });
	}
	void fillChar(string &str, int start, int cnt) {

	}
	string longestDiverseString(int a, int b, int c) {
		sortTriple(a, b, c);
		if (tri[1].cnt + tri[2].cnt < (tri[0].cnt + 1) / 2 - 1) {
			tri[0].cnt = (tri[1].cnt + tri[2].cnt + 1) * 2;
		}
		string str((tri[0].cnt + 1) / 2 * 6, 'x');
		for (int i = 0, j = 0; i < tri[0].cnt; i += 2, j += 6) {
			str[j] = tri[0].ch;
			if (i + 1 < tri[0].cnt) {
				str[j + 1] = tri[0].ch;
			}
		}
		int i = 0;
		int j = 2;
		int len = str.size();
		while (i < tri[1].cnt && j < len) {
			str[j] = tri[1].ch;
			j += 6;
			++i;
		}
		if (j < len) {
			j += 2;
			i = 0;
			while (i < tri[2].cnt && j < len) {
				str[j] = tri[2].ch;
				j += 6;
				++i;
			}
			if (i < tri[2].cnt) {
				j = 4;
				while (i < tri[2].cnt & j < len) {
					str[j] = tri[2].ch;
					j += 6;
					++i;
				}
			}
		}
		else {
			if (i < tri[1].cnt) {
				j = 3;
				while (i < tri[1].cnt && j < len) {
					str[j] = tri[1].ch;
					j += 6;
					++i;
				}
			}
			i = 0;
			j = 4;
			while (i < tri[2].cnt && j < len) {
				str[j] = tri[2].ch;
				j += 6;
				++i;
			}
			if (i < tri[2].cnt) {
				j = 5;
				while (i < tri[2].cnt && j < len) {
					str[j] = tri[2].ch;
					j += 6;
					++i;
				}
			}
		}


		string rst;
		for (auto ch : str) {
			if (ch != 'x') {
				rst.push_back(ch);
			}
		}
		return rst;
	}
};

int main()
{
	string str('x', 24);
	cout << str;
	return 0;
}