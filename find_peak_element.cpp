class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // O(N)
        /*
        int len = nums.size();
        if (len == 0) return -1;
        if (len == 1) return 0;
        
        for (int i = 0; i < len; ++i) {
            if (i == 0 && nums[i] > nums[i+1]) return i;
            if (i == len-1 && nums[i] > nums[i-1]) return i;
            if (i > 0 && i < len-1) {
                if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
            }
        }
        return -1;
        */
        
        // O(N)
        /*
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] < nums[i-1]) return i-1;
        }
        return nums.size()-1;
        */
        
        // O(logN)
        int left = 0, right = nums.size()-1;
        
        while (left < right) {
            int mid = (left+right)/2;
            int mid2 = mid+1;
            if(nums[mid] < nums[mid2]) left = mid2;
            else right = mid;
        }
        return left;
    }
};
