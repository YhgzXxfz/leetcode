class Solution {
public:
    bool search(vector<int>& nums, int target) {
       	if (nums.empty()) return false;

	int len = nums.size(), left = 0, right = len-1;
        while (left < right) {
            int mid = left+(right-left)/2;
            if (nums[mid] == target) return true;
            
            if (nums[mid] > nums[right]) {
                if (nums[left] <= target && target < nums[mid]) right = mid;
                else left = mid+1;
            } else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right]) left = mid+1;
                else right = mid;
            } else {
                right--;
            }
        }
        return nums[left] == target ? true : false;
    }
};
