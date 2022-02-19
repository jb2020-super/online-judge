class Solution {
public:
    void swap(vector<int>& arr, int k){
        int i = 0;
        int j = k - 1;        
        while (i < j){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            ++i;
            --j;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> rst;
        int n = arr.size();
        for (int i = n; i >= 1; --i){
            int pos = i - 1;
            if (arr[pos] == i){
                continue;
            }
            while (pos >= 0 && arr[pos] != i){
                --pos;
            }
            if (pos != 0){
                rst.push_back(pos + 1);
                swap(arr, pos + 1);

            }
            rst.push_back(i);
            swap(arr, i);
        }
        return rst;
    }
};