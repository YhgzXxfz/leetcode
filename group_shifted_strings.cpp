class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        
        for (auto sample : strings) {
            string key = shift(sample);
            mp[key].emplace_back(sample);
        }
        
        for (auto entry : mp) {
            result.push_back(entry.second);
        }
        
        return result;
    }

private:
    string shift(string sample) {
        if (sample.empty()) return "";
        
        string key = sample;
        int diff = sample[0] - 'a';
        for (int i = 0; i < sample.size(); ++i) {
            key[i] -= diff;
            if (key[i] < 'a') key[i] += 26;
        }
        return key;
    }
};
