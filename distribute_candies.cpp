class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> st(candies.begin(), candies.end());
        return min(st.size(), candies.size()/2);
    }
};
