class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        
        for (auto n1 : nums1) {
            for (auto n2 : nums2) {
                if (pq.size() < k) pq.push(make_pair(n1, n2));
                else if (n1+n2 < pq.top().first+pq.top().second) {
                    pq.push(make_pair(n1, n2));
                    pq.pop();
                }
            }
        }
        
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
    }
    
private:
    struct comp {
        bool operator() (pair<int, int> & p1, pair<int, int> & p2) { return p1.first+p1.second < p2.first+p2.second; }
    };
};
