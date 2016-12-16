class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result = "";
        result += (numerator < 0) ^ (denominator < 0) ? "-" : "";
        long num = abs((long) numerator), den = abs((long) denominator);
        
        result += to_string(num/den);
        num %= den;
        
        if (num == 0) return result;
        
        result += ".";
        unordered_map<long, int> mp;
        while (num) {
            if (mp.find(num) != mp.end()) {
                int index = mp[num];
                result.insert(index, 1, '(');
                result += ")";
                break;
            } else {
                mp[num] = result.size();
            }
            
            num *= 10;
            result += to_string(num/den);
            num %= den;
        }
        return result;
    }
};
