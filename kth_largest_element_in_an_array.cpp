class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // 1
        /*
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
        */
        
        // 2
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            pq.pop(); 
        return pq.top();
    }
};
