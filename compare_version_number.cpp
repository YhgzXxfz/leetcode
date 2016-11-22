class Solution {
public:
    int compareVersion(string version1, string version2) {
        string rest1 = version1;
        string rest2 = version2;
        int ps1, ps2;
        
        while (true) {
            if (rest1 == "" && rest2 == "") break;
            
            int v1 = stringToInteger(rest1);
            int v2 = stringToInteger(rest2);
            
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            
            ps1 = pointPosition(rest1);
            rest1 = rest1.substr(ps1+1, rest1.size()-ps1-1);
            ps2 = pointPosition(rest2);
            rest2 = rest2.substr(ps2+1, rest2.size()-ps2-1);
        }
        return 0;
    }
    
    int stringToInteger(string str) {
        const char * s = str.c_str();
        int result = 0;
        while (*s != '\0') {
            if (*s == '.') break;
            
            result = result * 10 + (*s - '0');
            ++s;
        }
        return result;
    }
    
    int pointPosition(string str) {
        const char * s = str.c_str();
        int count = 0;
        while (*s != '\0') {
            if (*s == '.') break;
            
            ++count;
            ++s;
        }
        if (*s == '\0') count = str.length()-1;
        return count;
    }
};
