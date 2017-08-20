class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto comp = [&](pair<int,int> p1, pair<int,int> p2) {
            return p1.first > p2.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        int len = nums.size(), curr_max = INT_MIN;
        vector<int> index(len, 0);
        for (int i = 0; i < len; ++i) {
            if (nums[i].size() == 0) continue;
            pq.push(make_pair(nums[i][0], i));
            index[i] = 1;
            curr_max = max(curr_max, nums[i][0]);
        }
        
        int start = pq.top().first, end = curr_max; // min-max pair of all the first elements
        
        while (index[pq.top().second] < nums[pq.top().second].size()) {
            int row = pq.top().second, col = index[row];
            pq.pop();
            pq.push(make_pair(nums[row][col], row));
            curr_max = max(curr_max, nums[row][col]);
            ++index[row];
            
            if (end-start > curr_max - pq.top().first) {
                start = pq.top().first;
                end = curr_max;
            }
        }
        return {start, end};
    }
};
