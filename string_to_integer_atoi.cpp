// c++
class StringToIntegerAtoi {
public:
	int myAtoi(string s) {
		const int len = s.size();
		int i = 0;
		while (i < len && s[i] == ' ') ++i;
		if (i == len) return 0;

		bool minus = false;
		if (s[i] == '+' || s[i] == '-') {
			if (s[i] == '-') minus = true;

			++i;
		}
		if (i == len) return 0;

		long long result = 0;
		while (i < len && s[i] >= '0' && s[i] <= '9') {
			result = result*10 + s[i++]-'0';

			if (!minus && result > INT_MAX) return INT_MAX;
			if (minus && result > 0x80000000) return INT_MIN;
		}
		return minus ? -1 * (int)result : result;
	}
};


// c
class Solution {
public:
    int myAtoi(string str) {
        const char* s = str.c_str();
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
