// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int left{1u};
        unsigned int right{static_cast<unsigned int>(n)};
        int mid{0};
        int target{n};
        bool isBad{false};
        while (left <= right){
            mid = (left + right) >> 1;
            isBad = isBadVersion(mid);
            if (isBad){
                right = mid - 1;
                if (mid < target){
                    target = mid;
                }
            }else{
                left = mid + 1;
            }
        }
        return target;
    }
};