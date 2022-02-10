class Solution {
public:    
    int gdc(int a, int b){        
        while (b){
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> rst;
        if (n == 1){
            return rst;
        }        
        for (int i = 2; i <= n; ++i){
            for (int j = 1; j < i; ++j){
                if (gdc(i, j) == 1){
                    string frac(to_string(j));
                    frac += '/';
                    frac += to_string(i);
                    rst.push_back(frac);
                }
            }
        }
        return rst;
    }
};