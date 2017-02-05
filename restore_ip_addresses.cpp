class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        
        for (int a = 1; a <= 3; ++a) {
            for (int b = 1; b <= 3; ++b) {
                for (int c = 1; c <= 3; ++c) {
                    for (int d = 1; d <= 3; ++d) {
                        if (a+b+c+d == s.size()) {
                            int A = stoi(s.substr(0, a)), B = stoi(s.substr(a, b)), C = stoi(s.substr(a+b, c)), D = stoi(s.substr(a+b+c, d));
                            if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                                ip = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                                if (ip.size() == s.size()+3) result.emplace_back(ip);
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};
