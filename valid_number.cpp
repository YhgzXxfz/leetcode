class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        
        const int len = s.size();
	int i = 0;
        while (i < len && s[i] == ' ') i++;
        if (len == i) return false;
        if (s[i] == '+' || s[i] == '-') i++;
        if (len == i) return false;
        
        int numbers = 0, points = 0;
        while (i < len && (s[i] == '.' || s[i] >= '0' && s[i] <= '9')) {
            if (s[i] == '.') points++;
            else numbers++;
            i++;
        }
        if (points > 1 || numbers < 1) return false;
        if (len == i) return true;
        
        if (s[i] == 'e') {
            i++;
            if (len == i) return false;
            
            if (s[i] == '+' || s[i] == '-') i++;
            if (len == i) return false;
            numbers = 0;
            while (i < len && s[i] >= '0' && s[i] <= '9') {
                numbers++;
                i++;
            }
            if (numbers < 1) return false;
            if (len == i) return true;
        }
        
        while (i < len && s[i] == ' ') i++;
        return len == i;
    }
};
