class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        dfs(result, 0, 0, s, ip);
        return result;
    }
    
private:
    void dfs(vector<string>& result, int start, int step, string s, string ip) {
        if (start == s.size() && step == 4) {
            ip.resize(ip.size() -1);
            result.push_back(ip);
            return;
        }
        
        if (s.size() - start > (4-step)*3) return;
        if (s.size() - start < 4-step) return;
        
        int num = 0;
        for (int i = start; i < start+3; ++i) {
            num = num*10 + (s[i]-'0');
            if (num <= 255) {
                ip += s[i];
                dfs(result, i+1, step+1, s, ip+'.');
            }
            
            if (num == 0) break;
        }
    }
};
