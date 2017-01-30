class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> counts(len, 0), sorted;
        
        for (int i = len-1; i >= 0; --i) {
            int index = findIndex(nums[i], sorted);
            sorted.emplace(sorted.begin()+index, nums[i]);
            counts[i] = index;
        }
        return counts;
    }
   
private: 
    int findIndex(int num, vector<int>& sorted) {
        int len = sorted.size();
        if (len == 0) return 0;
        
        int left = 0, right = len-1;
        if (num > sorted[right]) return right+1;
        if (num <= sorted[left]) return 0;
        
        while (left +1 < right) {
            int mid = left + (right-left)/2;
            
            if (num > sorted[mid]) left = mid+1;
            else right = mid;
        }
        if (num <= sorted[left]) return left;
        return right;
    }
};
