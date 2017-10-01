class Solution {
public:
    string findContestMatch(int n) {
        vector<string> vec(n);
        for (int i = 0; i < n; ++i) vec[i] = to_string(i+1);
        
        while (n > 1) {
            for (int i = 0; i < n/2; ++i) {
                vec[i] = "(" + vec[i] + "," + vec[n-1-i] + ")";
            }
            n /= 2;
        }
        return vec[0];
    }
};


class Solution {
public:
    string findContestMatch(int n) {
        int k = log(n)/log(2), num = 1, sum;
        string result = "1";
        for (int i = 1; i <= k; ++i) {
            num *= 2;
            sum = num+1;
            
            string s;
            int len = result.size();
            for (int j = 0; j < len; ++j) {
                char c = result[j];
                if (isdigit(c)) {
                    int digit = 0;
                    while (j < len && isdigit(result[j])) { digit = digit*10 + result[j++]-'0'; }
                    
                    j--;
                    s += replace(digit, sum);
                } else {
                    s += c;
                }
            }
            result = s;
        }
        return result;
    }

private:
    string replace(int digit, int sum) {
        return "(" + to_string(digit) + "," + to_string(sum-digit) + ")";
    }
};
