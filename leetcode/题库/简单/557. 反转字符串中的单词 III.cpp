class Solution {
public:
    void reverseString(string &s, int start, int end){        
        char ch;
        for (int i = start, j = end; i < j; ++i, --j){
            ch = s[i];
            s[i] = s[j];
            s[j] = ch;
        }
    }
    string reverseWords(string s) {
        int len = s.length();
        int i = 0;
        int j = 0;
        for (; i < len; ++i){
            if (s[i] == ' '){
                if (j < i - 1) {
                    reverseString(s, j, i - 1);
                }
                j = i + 1;
            }
        }
        if (j < i - 1){
            reverseString(s, j, i - 1);
        }
        return s;
    }
};