// binary search, t-O(logN + k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = index-1, j = index;
        while (k--) {
            if (i < 0 || (j < arr.size() && abs(arr[i]-x) > abs(arr[j]-x))) ++j;
            else --i;
        }
        return vector<int>(arr.begin()+i+1, arr.begin()+j);
    }
};



// pq + sort, t-O(N)
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
