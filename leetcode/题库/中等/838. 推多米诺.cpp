class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.size();
        int i = 0;
        int start = 0;
        while (i < len && dominoes[i] != 'R'){
            if (dominoes[i] == 'L'){
                while(start < i){
                    dominoes[start++] = 'L';
                }
                start = i + 1;
            }
            ++i;
        }
        while (i < len){
            int first_L = i + 1;
            int last_R = i;
            while (first_L < len && dominoes[first_L] != 'L'){
                if (dominoes[first_L] == 'R'){
                    int j = last_R + 1;
                    while(j < first_L){
                        dominoes[j++] = 'R';
                    } 
                    last_R = first_L;
                }
                ++first_L;
            }
            if (first_L < len && dominoes[first_L] == 'L'){
                int j = last_R + 1;
                int k = first_L - 1;
                while (j <= k){
                    if (j != k){
                        dominoes[j] = 'R';
                        dominoes[k] = 'L';
                    }else{
                        dominoes[j] = '.';
                    }
                    ++j;
                    --k;
                }
            }else if (first_L >= len){
                int j = last_R + 1;
                while (j < len){
                    dominoes[j++] = 'R';
                }
            }
            i = first_L + 1;
            start = i;
            while (i < len && dominoes[i] != 'R'){
                if (dominoes[i] == 'L'){
                    while(start < i){
                        dominoes[start++] = 'L';
                    }
                    start = i + 1;
                }
                ++i;
            }
        }
        return dominoes;
    }
};