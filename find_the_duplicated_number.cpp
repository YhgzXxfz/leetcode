class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 1 binary search
        /*
        int len = nums.size();
        int left = 0, right = len-1;
        int count = 0;
        while (left < right) {
            count = 0;
            int mid = (left+right) /2;
            for (auto n : nums) {
                if (n <= mid) ++count;
            }
            if (count <= mid) left = mid+1;
            else right = mid;
        }
        return left;
        */
        
        // 2 two pointers
        if (nums.size() > 1) {
            int slow = nums[0], fast = nums[0];
            while (true) {
                slow = nums[slow];
                fast = nums[nums[fast]];
                if (slow == fast) break;
            }
            
            fast = nums[0];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
        return -1;
    }
};
