class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size(), count = 0;
        if (len <= 1) return 0;
        
        for (int i = 31; i >= 0; --i) {
            int k = 0;
            for (auto& num : nums) {
                k += (num >> i)&1;
            }
            count += k*(len-k);
        }
        return count;
    }
};
