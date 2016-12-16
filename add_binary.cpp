class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;
        
        int p_a = a.size()-1, p_b = b.size()-1;
        int carry = 0;
        string result = "";
        while (p_a >= 0 && p_b >= 0) {
            int sum = a[p_a]-'0' + b[p_b]-'0' + carry;
            result += to_string(sum%2);
            carry = sum/2;
            p_a--; p_b--;
        }
        
        while (p_a >= 0) {
            int sum = a[p_a]-'0' + carry;
            result += to_string(sum%2);
            carry = sum/2;
            p_a--;
        }
        
        while (p_b >= 0) {
            int sum = b[p_b]-'0' + carry;
            result += to_string(sum%2);
            carry = sum/2;
            p_b--;
        }
        
        if (carry) result += to_string(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
