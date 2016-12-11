class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        vector<string> buckets(s.size()+1, "");
        
        for (auto c : s) mp[c]++;
        
        for (auto& entry : mp) {
            int times = entry.second;
            buckets[times].append(times, entry.first);
        }
        
        string result = "";
        for (int i = buckets.size()-1; i >= 0; --i) {
            if (!buckets[i].empty()) result += buckets[i];
        }
        return result;
    }
};
