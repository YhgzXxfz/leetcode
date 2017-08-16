class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto comp = [&](pair<int, int> p1, pair<int, int> p2) {
            if (p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        for (int i = 0; i < arr.size(); ++i) {
            int dist = abs(arr[i]-x);
            pq.push(make_pair(dist, i));
            
            if (pq.size() > k) pq.pop();
        }
        
        vector<int> result;
        while (!pq.empty()) {
            int index = pq.top().second;
            result.push_back(arr[index]);
            pq.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};
