class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto word : words) {
            ++mp[word];
        }
        
        auto comp = [&](pair<string, int> p1, pair<string, int> p2) {
            if (p1.second == p2.second) return p1.first < p2.first;
            return p1.second > p2.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
        for (auto entry : mp) {
            pq.push(entry);
            if (pq.size() > k) pq.pop();
        }
        
        vector<string> result;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            result.push_back(curr.first);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
