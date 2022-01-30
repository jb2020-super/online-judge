#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	void InsertWord(string &word, map<string, int> &un_words) {
		if (!word.empty()) {
			auto it = un_words.find(word);
			if (it == un_words.end()) {
				un_words.insert({ word, 1 });
			}
			else
			{
				it->second++;
			}
		}
		word.clear();
	}
	void ParseSentence(string &str, map<string, int> &un_words) {
		int len = str.size();
		string word;
		for (int i = 0; i < len; ++i) {
			if (str[i] == ' ') {
				InsertWord(word, un_words);
			}
			else
			{
				word.push_back(str[i]);
			}
		}
		InsertWord(word, un_words);
	}
	vector<string> uncommonFromSentences(string s1, string s2) {		
		map<string, int> un_words;
		ParseSentence(s1, un_words);
		ParseSentence(s2, un_words);
		vector<string> result;
		for (auto &word : un_words) {
			if (word.second == 1) {
				result.push_back(word.first);
			}
		}
		
		return result;
	}
};

int main()
{
	Solution so;
	string s1 = "this apple is sweet";
	string s2 = "this apple is sour";
	so.uncommonFromSentences(s1, s2);
	return 0;
}