class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size(), left = 0, right = len-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (nums[mid] == target) {
                left = mid;
                while (left >= 0 && nums[left] == target) left--;
                left++;
                right = mid;
                while (right < len && nums[right] == target) right++;
                right--;
                return {left, right};
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return {-1,-1};
    }
};
