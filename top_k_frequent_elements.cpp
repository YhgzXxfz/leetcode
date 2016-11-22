class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // 1 map O(kn)
        /*
        int len = nums.size();
        vector<int> result;
        
        unordered_map<int, int> mp;
        if (k <= 0 || k > len) return result;
        
        for (auto num : nums) {
            mp[num]++;
        }
        
        for (int i = 0; i < k; ++i) {
            int max_frequency = 0, index = 0;   
            for (auto oc : mp) {
                if (oc.second > max_frequency) {
                    max_frequency = oc.second;
                    index = oc.first;
                }
            }
            result.push_back(index);
            auto it = mp.find(index);
            it->second = -1;
        }
        
        return result;
        */
        
        // 2 map + heap O(klog(n))
        
        unordered_map<int, int> mp;
        for (auto num : nums) mp[num]++;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto oc : mp) {
            pq.push(oc.second);
            while (pq.size() > k) pq.pop();
        }
        
        vector<int> result;
        for (auto oc : mp) {
            if (oc.second >= pq.top()) result.push_back(oc.first);
        }
        return result;
        
        
        // 3 map + bucket sort O(n)
        /*
        unordered_map<int, int> mp;
        for (auto num : nums) mp[num]++;
        
        vector<vector<int>> buckets(nums.size()+1);
        for (auto oc : mp) {
            buckets[oc.second].push_back(oc.first);
        }
        
        reverse(begin(buckets), end(buckets));
        
        vector<int> result;
        for (auto bucket : buckets) {
            for (auto num : bucket) {
                result.push_back(num);
                if (result.size() >= k) return result;
            }
        }
        return result;
        */
    }
};
