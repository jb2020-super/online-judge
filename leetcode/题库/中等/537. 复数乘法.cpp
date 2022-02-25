class Solution {
public:    
    void parseDigit(const string& num, int& idx, int &a) {
        int n = num.length();
        bool negative{false};
        a = 0;        
        while(idx < n){
            if (num[idx] == '-'){
                negative = true;
            }else if (isdigit(num[idx])){
                a = a * 10 + (num[idx] - '0');
            }else {
                break;
            }
            ++idx;
        }        
        if (negative){
            a = -a;
        }
    }
    void parseComplex(const string& num, int &a, int &b) {    
        int n = num.length();
        int idx = 0;
        parseDigit(num, idx, a);
        ++idx;
        parseDigit(num, idx, b);        
    }
    string complexNumberMultiply(string num1, string num2) {
        int a1{}, b1{}, a2{}, b2{};
        parseComplex(num1, a1, b1);
        parseComplex(num2, a2, b2);
        string rst;
        int a = a1 * a2 - b1 * b2;
        int b = a1 * b2 + a2 * b1;
        rst += to_string(a);
        rst += '+';
        rst += to_string(b);
        rst += 'i';
        return rst;
    }
};