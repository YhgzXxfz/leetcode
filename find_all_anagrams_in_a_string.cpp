class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sv(256, 0), pv(256, 0), result;
        if (s.empty() || p.empty() || s.size() < p.size()) return result;
        
        for (int i = 0; i < p.size(); ++i) {
            sv[s[i]]++;
            pv[p[i]]++;
        }
        if (sv == pv) result.emplace_back(0);
        
        for (int i = p.size(); i < s.size(); ++i) {
            sv[s[i]]++;
            sv[s[i-p.size()]]--;
            if (sv == pv) result.emplace_back(i-p.size()+1);
        }
        return result;
    }
};
