class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        
        int carry = 0, p_1 = num1.size()-1, p_2 = num2.size()-1;
        while (p_1 >= 0 && p_2 >= 0) {
            int sum = (num1[p_1]-'0') + (num2[p_2]-'0') + carry;
            result += to_string(sum%10);
            carry = sum/10;
            p_1--; p_2--;
        }
        
        while (p_1 >= 0) {
            int sum = num1[p_1]-'0' + carry;
            result += to_string(sum%10);
            carry = sum/10;
            p_1--;
        }
        
        while (p_2 >= 0) {
            int sum = num2[p_2]-'0' + carry;
            result += to_string(sum%10);
            carry = sum/10;
            p_2--;
        }
        
        if (carry) result += to_string(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
