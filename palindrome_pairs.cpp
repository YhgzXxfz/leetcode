class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int len = words.size();
        vector<vector<int>> result;
        if (len == 0) return result;
        
        for (int i = 0; i < len; ++i) {
            string key = words[i];
            reverse(key.begin(), key.end());
            mp[key] = i;
        }
        
        if (mp.find("") != mp.end()) {
            for (int i = 0; i < len; ++i) {
                if (words[i] == "") continue;
                if (IsPalindrome(words[i])) result.push_back({mp[""], i});
            }
        }
        
        for (int i = 0; i < len; ++i) {
            string word = words[i];
            for (int j = 0; j < word.size(); ++j) {
                string left = word.substr(0, j), right = word.substr(j);
                
                if (mp.find(left) != mp.end() && mp[left] != i && IsPalindrome(right)) result.push_back({i, mp[left]});
                
                if (mp.find(right) != mp.end() && mp[right] != i && IsPalindrome(left)) result.push_back({mp[right], i});
            }
        }
        return result;
    }

private:
    bool IsPalindrome(string str) {
        int l = 0, r = str.size()-1;
        while (l < r) {
            if (str[l++] != str[r--]) return false;
        }
        return true;
    }
    
    unordered_map<string, int> mp;
};
