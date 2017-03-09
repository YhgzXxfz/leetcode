class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (left+right)>>1;
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            else if (((mid&1) && nums[mid] == nums[mid-1]) || (mid%2 == 0 && nums[mid] == nums[mid+1]))
                left = mid+1;
            else
                right = mid-1;
        }
        return nums[left];
    }
};
