class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (a == 0) {
            for (auto& num : nums) {
                num = b*num+c;
            }
            if (b < 0) reverse(nums.begin(), nums.end());
            return nums;
        }
        
        int len = nums.size();
        vector<int> sorted(len);
        int left = 0, right = len-1, index = len-1;
        double x = -(double)b/(2*(double)a);
        while (left <= right) {
            if (abs(nums[left]-x) < abs(nums[right]-x)) {
                sorted[index--] = nums[right--];
            } else {
                sorted[index--] = nums[left++];
            }
        }
        
        if (a < 0) reverse(sorted.begin(), sorted.end());
        for (auto& num : sorted) {
            num = a*num*num+b*num+c;
        }
        return sorted;
    }
};
