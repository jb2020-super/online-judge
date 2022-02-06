class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        char ch;
        for (int i = 0, j = len - 1; i < j; ++i, --j){
            ch = s[i];
            s[i] = s[j];
            s[j] = ch;
        }
    }
};