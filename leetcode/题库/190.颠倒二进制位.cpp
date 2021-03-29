class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        int i = 0;
        uint32_t j = 1;
        while(i < 31){            
            m += (n & j) > 0 ? 1 : 0; 
            m <<= 1;           
            ++i;
            j <<= 1;
        };
        m += (n & j) > 0 ? 1 : 0;
        return m;
    }
};