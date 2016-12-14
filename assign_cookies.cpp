class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int count = 0;
        for (int j = 0; count < g.size() && j < s.size(); ++j) {
            if (s[j] >= g[count]) count++;
        }
        return count;
    }
};
