class Solution {
public:
    int compareVersion(string version1, string version2) {
        string restStr1 = version1;
        string restStr2 = version2;
        int length1, length2;
        int ps1, ps2;
        
        while (true)
        {
            if (restStr1 == "" && restStr2 == "") break;
            
            int v1 = StringToInteger(restStr1);
            int v2 = StringToInteger(restStr2);
            
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            
            ps1 = PointPosition(restStr1);
            length1 = restStr1.length();
            restStr1 = restStr1.substr(ps1+1, length1-ps1-1);
            ps2 = PointPosition(restStr2);
            length2 = restStr2.length();
            restStr2 = restStr2.substr(ps2+1, length2-ps2-1);
            
        }
        return 0;
    }
    
    int StringToInteger(string str)
    {
        const char * s = str.c_str();
        int result = 0;
        while (*s != '\0')
        {
            if (*s == '.') 
                break;
            
            result = result * 10 + (*s - '0');
            ++s;
        }
        return result;
    }
    
    int PointPosition(string str)
    {
        const char * s = str.c_str();
        int count = 0;
        while (*s != '\0')
        {
            if (*s == '.') 
                break;
            
            ++count;
            ++s;
        }
        if (*s == '\0') count = str.length()-1;
        return count;
    }
};
