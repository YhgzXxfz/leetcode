class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size(), max_count = INT_MIN;
        vector<int> visited(len, 0);
        for (const auto& num : nums) {
            if (visited[num]) continue;
            
            unordered_set<int> st;
            st.insert(num);
            visited[num] = true;
            int curr = nums[num], count = 1;
            while (!st.count(curr)) {
                st.insert(curr);
                visited[curr] = true;
                curr = nums[curr];
                count++;
            }
            max_count = max(max_count, count);
            if (max_count > len/2) break;
        }
        return max_count;
    }
};
