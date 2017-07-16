class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return 0;
        
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len-2; ++i) {
            for (int j = i+1; j < len-1; ++j) {
                int left = j+1, right = len-1, target = nums[i]+nums[j];
                while (left <= right) {
                    int mid = left + (right-left)/2;
                    if (nums[mid] >= target) right = mid-1;
                    else left = mid+1;
                }
                count += right-j;
            }
        }
        return count;
    }
};
