// 12ms, 6.8MB
class Solution {
    int alpha[256];
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (!len){
            return 0;
        }
        memset(alpha, 0, sizeof(alpha));
        int count{0};
        for (const auto& ch : s){
            if (!alpha[ch]){
                ++count;
                alpha[ch] = 1;
            }
        }
        
        for (int i = count; i >= 2; --i){
            int unique_cnt{0};
            memset(alpha, 0, sizeof(alpha));
            for(int j = 0; j < i; ++j){
                if (!alpha[s[j]]){
                    ++unique_cnt;                    
                }else if (alpha[s[j]] == 1){
                    --unique_cnt;
                }
                ++alpha[s[j]];
            }
            if (unique_cnt == i){
                return i;
            }
            for (int j = i; j < len; ++j){
                if (!alpha[s[j]]){
                    ++unique_cnt;
                }else if (alpha[s[j]] == 1){
                    --unique_cnt;
                }
                ++alpha[s[j]];
                auto int &first = alpha[s[j - i]];
                --first;
                if (first == 1){
                    ++unique_cnt;
                }else if (!first){
                    --unique_cnt;
                }
                if (unique_cnt == i){
                    return i;
                }
            }
        }
        return 1;
    }
};
// 4 ms, 7MB
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flg[256]{};
        int max_len{};
        int len{}, start{};
        for (int i = 0; i < s.length(); ++i){
            if (flg[s[i]]){
                if (len > max_len){
                    max_len = len;
                }
                
                while (s[start] != s[i]){
                    flg[s[start]]--;
                    ++start;
                    --len;
                }
                ++start;
            }else{
                flg[s[i]]++;
                ++len;
            }
        }
        if (len > max_len){
            max_len = len;
        }
        return max_len;
    }
};