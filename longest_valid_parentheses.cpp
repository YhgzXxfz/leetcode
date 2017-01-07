class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size(), last = -1, max_len = 0;
        stack<int> left;
        
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') left.push(i);
            else {
                if (left.empty()) last = i;
                else {
                    left.pop();
                    if (left.empty()) max_len = max(max_len, i-last);
                    else max_len = max(max_len, i-left.top());
                }
            }
        }
        return max_len;
    }
};
