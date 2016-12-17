class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        string result(len1+len2, '0');
        
        for (int i = len1-1; i >= 0; --i) {
            for (int j = len2-1; j >= 0; --j) {
                int p_curr = i+j+1, p_carry = i+j;
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int sum = mul + result[p_curr]-'0';
                
                result[p_curr] = sum%10+'0';
                result[p_carry] += sum/10;
            }
        }
        
        while (!result.empty() && result[0] == '0') result.erase(0,1);
        return result.empty() ? "0" : result;
    }
};
