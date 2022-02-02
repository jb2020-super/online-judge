// 2000. 反转单词前缀
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int len = word.size();
        int i = 0;
        int j = -1;
        for (i = 0; i < len; ++i){
            if (word[i] == ch){
                j = i;
                break;
            }
        }
        char tmp;
        for (i = 0; i < j; ++i, --j){
            tmp = word[i];
            word[i] = word[j];
            word[j] = tmp;
        }
        return word;
    }
};