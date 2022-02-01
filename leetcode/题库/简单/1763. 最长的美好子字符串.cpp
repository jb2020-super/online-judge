#include <string>
using namespace std;

class Solution {
public:    
    void check(int flg[2], int idx, int &cnt){
        if (!flg[idx]){
            flg[idx] = 1;
            if (flg[1 - idx]){
                cnt--;
            }else{
                cnt++;
            }
        }
    }
    string longestNiceSubstring(string s) {
        int len = s.size();
        int mx_start = -1;
        int mx_end = -1;
        int mx_len = 0;
        for (int i = 0; i < len; ++i){
            int cnt = 0;
            int table[26][2]{};
            for (int j = i; j < len; ++j){
                if (s[j] >= 'a' && s[j] <= 'z'){
                    check(table[s[j] - 'a'], 0, cnt);                    
                }else{
                    check(table[s[j] - 'A'], 1, cnt);                    
                }
                if (!cnt && (j - i + 1 > mx_len)){
                    mx_start = i;
                    mx_end = j;
                    mx_len = j - i + 1;
                }
            }
        }
        
        if (mx_len > 0){
            return string(s, mx_start, mx_len);
        }
        return "";
    }
};