class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size(), i = len-1;
        
        while (i >= 0 && s[i] == ' ') i--;
        if (i < 0) return 0;
        
        int result = 0;
        while (i >= 0 && s[i] != ' ') {
            i--;
            result++;
        }
        return result;
    }
};
