class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int len = s.size();
        if (len <= 10) return result;
        
        unordered_map<string, int> mp;
        for (int i = 0; i < len-9; ++i) {
            string dna = s.substr(i,10);
            if (mp.find(dna) == mp.end()) {
                mp[dna] = 1;
            } else {
                if (mp[dna] == 1) result.emplace_back(dna);
                mp[dna]++;
            }
        }
        return result;
    }
};
