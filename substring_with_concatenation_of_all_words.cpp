class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (auto word : words) {
            counts[word]++;
        }
        
        int number = words.size(), len = words[0].size();
        vector<int> indexes;
        for (int i = 0; i < s.size() - number*len +1; ++i) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < number; ++j) {
                string candidate = s.substr(i+j*len, len);
                if (counts.find(candidate) == counts.end()) break;
                
                seen[candidate]++;
                if (seen[candidate] > counts[candidate]) break;
            }
            
            if (j == number) indexes.push_back(i);
        }
        return indexes;
    }
};
