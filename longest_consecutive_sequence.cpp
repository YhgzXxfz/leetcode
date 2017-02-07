class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        int max_len = 0;
        while(!st.empty()) {
            int i = *st.begin();
            st.erase(i);
            
            int upper = i+1;
            while (st.count(upper)) {
                st.erase(upper);
                ++upper;
            }
            
            int lower = i-1;
            while (st.count(lower)) {
                st.erase(lower);
                --lower;
            }
            
            max_len = max(max_len, upper-lower -1);
        }
        return max_len;
    }
};
