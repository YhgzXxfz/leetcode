class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> st;
        for (auto& num : nums) {
            st.insert(num);
        }
        
        int len = st.size();
        if (len == 1) return nums[0];
        else if (len == 2) return *max_element(nums.begin(), nums.end());
        
        priority_queue<int, vector<int>, greater<int> > pq;
        for (auto& distinct_num : st) {
            pq.push(distinct_num);
            if (pq.size() > 3) pq.pop();
        }
        
        return pq.top();
    }
};
