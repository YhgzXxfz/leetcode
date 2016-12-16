class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while (n) {
            n--;
            result += 'A' + n%26;
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
