class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 1 t-O(n), m-O(n)
        /*
        vector<int> result;
        
        unordered_set<int> st(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); ++i) {
            if (!st.count(i)) result.emplace_back(i);
        }
        return result;
        */
        
        // 2 t-O(n), m-O(1)
        int len = nums.size();
        vector<int> result(len);
        
        for (int i = 0; i < len; ++i) {
            result[nums[i]-1] = 1;
        }
        
        int index = 0;
        for (int i = 0; i < len; ++i) {
            if (result[i] == 0) result[index++] = i+1;
        }
        result.resize(index);
        return result;
    }
};
