class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> result;
        unordered_map<char, int> mp;
        for (auto c : s) mp[c]++;
        
        int odd = 0;
        char mid;
        string half;
        for (auto& entry : mp) {
            if (entry.second &1) {
                odd++;
                mid = entry.first;
                if (odd > 1) return result;
            }
            half += string(entry.second/2, entry.first);
        }
        
        result = permute(half);
        for (string& p : result) {
            string t(p);
            reverse(t.begin(), t.end());
			if (odd) t = mid + t;
            p += t;
        }
        return result;
    }

private:
    vector<int> permute(string& s) {
        vector<string> permutations;
        string t(s);
        do {
            permutations.emplace_back(s);
            next_permutation(s.begin(), s.end()); 
        } while (s != t);
        return permutations; 
    }
};
