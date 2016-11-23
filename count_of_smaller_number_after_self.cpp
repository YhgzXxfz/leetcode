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
    
    int findIndex(int num, vector<int> sorted) {
        int len = sorted.size();
        if (len == 0) return 0;
        
        int start = 0, end = len-1;
        if (num > sorted[end]) return end+1;
        if (num <= sorted[start]) return 0;
        
        while (start +1 < end) {
            int mid = start + (end-start)/2;
            
            if (num > sorted[mid]) start = mid+1;
            else end = mid;
        }
        if (num <= sorted[start]) return start;
        return end;
    }
};
