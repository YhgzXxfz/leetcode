class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 1
        /*
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        for (int i = 0; i < len-1; ++i) {
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
        */
        
        // 2
        unordered_set<int> st;
        for (auto& num : nums) {
            if (st.count(num)) return true;
            st.insert(num);
        }
        return false;
    }
};
