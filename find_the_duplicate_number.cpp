class Solution {
public:
    int findDuplicate(vector<int>& nums) {
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
    }
};
