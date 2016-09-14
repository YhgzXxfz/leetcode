class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0, len = s.size();
        for (int i = 0; i < len; ++i) {
            sum += (t[i]-s[i]);
        }
        return sum+t[len];
    }
};
