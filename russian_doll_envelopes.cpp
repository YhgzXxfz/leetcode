// O(NlogN)
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;

		int len = envelopes.size();
		if (len == 1) return 1;

		auto comp = [&](pair<int,int> p1, pair<int,int> p2) {
			if (p1.first == p2.first) return p1.second > p2.second;
			return p1.first < p2.first;
		};
		sort(envelopes.begin(), envelopes.end(), comp);

		vector<int> dp(len), height(len+1, INT_MAX);
		for (int i = 0; i < len; ++i) {
			int k = lower_bound(height.begin(), height.end(), envelopes[i].second)-height.begin();
			dp[i] = k;
			height[k] = envelopes[i].second;
		}
		return 1 + *max_element(dp.begin(), dp.end());
    }
};


// O(N^2)
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        if (envelopes.size() == 1) return 1;
        
        auto comp = [&](pair<int, int> e1, pair<int, int> e2) { 
            if (e1.first == e2.first) return e1.second < e2.second;
            return e1.first < e2.first; 
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        
        int max_count = INT_MIN;
        int len = envelopes.size();
        vector<int> dp(len, 1);
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            max_count = max(max_count, dp[i]);
        }
        return max_count;
    }
};
