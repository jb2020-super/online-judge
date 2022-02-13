class Solution {

public:
    int maxNumberOfBalloons(string text) {
        int alpha[256]{};
        int len = text.length();
        for (int i = 0; i < len; ++i){
            ++alpha[text[i]];
        }
        char ballon[]{"balon"};
        alpha['l'] /= 2;
        alpha['o'] /= 2;
        int min_cnt{10000};
        for (int i = 0; i < 5; ++i){
            if (alpha[ballon[i]] < min_cnt){
                min_cnt = alpha[ballon[i]];
            }
        }
        return min_cnt;
    }
};