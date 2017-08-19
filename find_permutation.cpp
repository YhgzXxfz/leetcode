class Solution {
public:
    vector<int> findPermutation(string s) {
        int len = s.size();
        vector<int> nums(len+1);
        for (int i = 0; i <= len; ++i) nums[i] = i+1;
        
        for (int r = 0; r < len; ++r) {
            if (s[r] == 'D') {
                int l = r;
                while (r < len && s[r] == 'D') r++;
                reverse(nums, l, r);
            }
        }
        return nums;
    }

private:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};
