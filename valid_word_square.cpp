class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty()) return true;
        
        int m = words.size();
        if (words[0].size() != m) return false;
        for (int i = 0; i < m; ++i) {
            int n = words[i].size();
            if (n > m) return false;
            
            string temp;
            for (int j = 0; j < n; ++j) {
                if (words[j].size() < i+1) return false;
                temp += words[j][i];
            }
            if (temp != words[i]) return false;
        }
        return true;
    }
};
