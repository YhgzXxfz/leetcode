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
