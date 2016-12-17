class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers(n), factorials(n+1);
        factorials[0] = 1;
        int sum = 1;
        for (int i = 1; i <= n; ++i) {
            numbers[i-1] = i;
            sum *= i;
            factorials[i] = sum;
        }
        
        k--;
        string result = "";
        for (int i = 1; i <= n; ++i) {
            int index = k/factorials[n-i];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin()+index);
            k -= index*factorials[n-i];
        }
        return result;
    }
};
