class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string s = "", result = "a";
        for (auto str : strs) {
            string rev = str;
            reverse(rev.begin(), rev.end());
            s += max(rev, str);
        }
        
        int st = 0;
        for (int i = 0; i < strs.size(); ++i) {
            string p1 = strs[i], p2 = strs[i], body = s.substr(st+p1.size()) + s.substr(0, st);
            reverse(p2.begin(), p2.end());
            for (int j = 0; j < strs[i].size(); ++j) {
                if (p1[j] >= result[0]) result = max(result, p1.substr(j) + body + p1.substr(0,j));
                if (p2[j] >= result[0]) result = max(result, p2.substr(j) + body + p2.substr(0,j));
            }
            st += strs[i].size();
        }
        return result;
    }
};
