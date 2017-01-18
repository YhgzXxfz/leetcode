class Solution {
public:
    string shortestPalindrome(string s) {
        // 1
        /*
        int len = s.size();
        
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        int pos;
        for (pos = len; pos >= 0; --pos) {
            if (rev_s.substr(len-pos) == s.substr(0, pos)) break;
        }
        return rev_s.substr(0, len-pos) +s;
        */
        
        // 2
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        
        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i-1];
            while (j > 0 && l[i] != l[j]) {
                j = p[j-1];
            }
            p[i] = (j += l[i] == l[j]);
        }
        
        return rev_s.substr(0, s.size() - p[l.size()-1]) + s;
    }
};
