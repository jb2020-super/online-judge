class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int alpha[256]{};
        int s1_len = s1.length();
        int s2_len = s2.length();
        if (s1_len > s2_len){
            return false;
        }
        for (int i = 0; i < s1_len; ++i){
            ++alpha[s1[i]];
        }
        int cnt{0};
        int i = 0;
        while (i < s1_len){
            auto &c = alpha[s2[i]];
            if (c > 0){
                ++cnt;
            }else{
                --cnt;
            }
            --c;            
            ++i;
        }
        if (cnt == s1_len){
            return true;
        }
        while (i < s2_len){
            auto &c1 = alpha[s2[i - s1_len]];
            if (c1 >= 0){
                --cnt;
            }else {
                ++cnt;
            }
            ++c1;            
            auto &c2 = alpha[s2[i]];
            if (c2 > 0){
                ++cnt;
            }else {
                --cnt;
            }            
            --c2;            
            ++i;
            if (cnt == s1_len){
                return true;
            }
        }
        if (cnt == s1_len){
            return true;
        }
        return false;
    }
};