class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.find('.') != string::npos) return checkIPv4(IP);
        if (IP.find(':') != string::npos) return checkIPv6(IP);
        return "Neither";
    }

private:
    string checkIPv4(string ip) {
        for (int i = 0; i < 3; ++i) {
            int point = ip.find('.');
            if (point == string::npos) return "Neither";
            
            if (!isValidIPv4(ip.substr(0,point))) return "Neither";
            ip = ip.substr(point+1);
        }
        if (ip.empty() || ip.find('.') != string::npos) return "Neither";
        return isValidIPv4(ip) ? "IPv4" : "Neither";
    }

    bool isValidIPv4(string ip) {
	int len = ip.size();
    	if (len <= 0 || len > 3) return false;
    	
    	int num = 0;
	    for (int i = 0; i < len; ++i) {
	        char c = ip[i];
	        // special case: if c is a leading zero and there are characters left
	        if (!isalnum(c) || (i == 0 && c == '0' && len > 1)) return false;
	        else num = num*10 + c-'0';
	    }
	    return num <= 255;
    }
    
    string checkIPv6(string ip) {
        for (int i = 0; i < 7; ++i) {
            int colon = ip.find(':');
            if (colon == string::npos) return "Neither";
            
            if (!isValidIPv6(ip.substr(0,colon))) return "Neither";
            ip = ip.substr(colon+1);
        }
        if (ip.empty() || ip.find(':') != string::npos) return "Neither";
        return isValidIPv6(ip) ? "IPv6" : "Neither";
    }

    bool isValidIPv6(string ip) {
    	if (ip.size() <= 0 || ip.size() > 4) return false;
    	
	    for (auto c : ipv6) {
	        if (validIPv6Chars.find(c) == string::npos) return false;
	    }
	    return true;
    }
    
    const string validIPv6Chars = "0123456789abcdefABCDEF";
};
