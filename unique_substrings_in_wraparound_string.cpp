class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> count(26, 0);
        int curr_len = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i]-p[i-1] == 1 || p[i-1]-p[i] == 25)) curr_len++;
            else curr_len = 1;
            
            int index = p[i]-'a';
            count[index] = max(count[index], curr_len);
        }
        return accumulate(count.begin(), count.end(), 0);
    }
};
