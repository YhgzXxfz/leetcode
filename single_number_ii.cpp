class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (auto num : nums) {
                int digit = (num >> i) &1;
                if (digit) count++;
            }
            result |= ((count%3) << i);
        }
        return result;
    }
};
