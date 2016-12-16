class Solution {
public:
    int myAtoi(string str) {
        const char * s = str.c_str();
        bool minus = false; 

        while (' ' == *s) ++s;
    
        if (('+' ==  *s) || ('-' == *s)) {
            if ('-' == *s) minus = true;
            s++;
        }
    
        if (('\0' == *s) || (*s < '0') || (*s > '9')) return 0;
    
        unsigned long long result = 0; 
    
        while (*s != '\0') {
            if ((*s < '0') || (*s > '9')) break;
    
            result = result*10 + (*s-'0');
    
            if (minus) {
                if (result > 0x80000000) return INT_MIN;
            } else {
                if (result > 0x7fffffff) return INT_MAX;
            }
    
            ++s;
        }
    
        return minus ? (-1) * (int)result : (int)result;
    }
};
