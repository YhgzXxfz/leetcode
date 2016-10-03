class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (auto& num : nums) {
            left = max(left, (long long) num);
            right += num;
        }
        
        while (left < right) {
            long long mid = left + (right-left)/2;
            if (canSplit(nums, m, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }

private:
    bool canSplit(vector<int>& nums, int m, long long sum) {
        int count = 1;
        long long s = 0;
        for (auto& num : nums) {
            s += num;
            if (s > sum) {
                s = num;
                count++;
            }
        }
        return count <= m;
    }
};
