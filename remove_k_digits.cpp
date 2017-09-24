// O(N)
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int keep = num.size()-k;
        for (int i = 0; i < num.size(); ++i) {
            while (result.size() > 0 && result.back() > num[i] && k > 0) {
                result.pop_back();
                --k;
            }
            result += num[i];
        }
        result.erase(keep, string::npos);
        
        while (result.size() > 1 && result[0] == '0') result.erase(0,1);
        return result.empty() ? "0" : result;
    }
};

// O(N*k)
class Solution {
public:
    string removeKdigits(string num, int k) {
        for (int i = 0; i < k; ++i) {
            int p = 0;
            while (p < num.size()-1 && num[p] <= num[p+1]) p++;
            num.erase(num.begin()+p);
        }
        
        while (num.size() > 0 && num[0] == '0') num.erase(0, 1);
        return num.empty() ? "0" : num;
    }
};
