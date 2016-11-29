class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, max = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> st;
            for (auto num : nums) {
                st.insert(num & mask);
            }
            
            int temp = max | (1 << i);
            for (auto prefix : st) {
                if (st.find(temp ^ prefix) != st.end()) max = temp;
            }
        }
        return max;
    }
};
