class Solution {
public:
    int min(int a, int b){
        return a > b ? b : a;
    }
    int binarySearch(vector<int>& numbers, int start, int& end, int target){
        int mid{};
        int mid_val{};
        while (start <= end){
            mid = (start + end) >> 1;
            mid_val = numbers[mid];
            if (mid_val == target){
                return mid;
            }else if (mid_val < target){
                start = mid + 1;
            }else {
                end = mid - 1;
            }            
        }
        if (numbers[end] < target){
            end = min(end + 1, numbers.size() - 1);
        }
        return -1;
    }    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int start = 0;
        int end = 0;
        int right = len - 1;
        for (int i = 0; i < len; ++i){
            int remain = target - numbers[i];
            int idx = binarySearch(numbers, i + 1, right, remain);
            if (idx > i){
                start = i;
                end = idx;
                break;
            }
        }
        return {start + 1, end + 1};
    }
};

// O(n)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {        
        int sum{};
        for (int i = 0, j = numbers.size() - 1; i < j;){
            sum = numbers[i] + numbers[j];
            if (sum > target){
                --j;
            }else if (sum < target){
                ++i;
            }else{
                return {i + 1, j + 1};
            }
        }
        return {0, 0};
    }
};