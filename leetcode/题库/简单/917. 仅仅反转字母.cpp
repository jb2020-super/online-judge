class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j){
            while (i < j && !isalpha(s[i])){
                ++i;
            }
            while (i < j && !isalpha(s[j])){
                --j;
            }
            if (i < j){
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                ++i;
                --j;
            }
        }
        return s;
    }
};