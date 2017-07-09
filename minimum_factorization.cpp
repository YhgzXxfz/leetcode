class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) return 1;
        
        priority_queue<int, vector<int>, greater<int>> facs;
        dfs(a, facs);
        return constructResult(facs);
    }

private:
    void dfs(int a, priority_queue<int, vector<int>, greater<int>>& facs) {
        if (a <= 1) return;
        
        int i = 9;
        for (; i >= 2; --i) {
            if (a % i == 0) {
                facs.push(i);
                dfs(a/i, facs);
                break;
            }
        }
        if (i < 2) facs = priority_queue<int, vector<int>, greater<int>>(); // a has non-single digit prime factors
    }
    
    int constructResult(priority_queue<int, vector<int>, greater<int>>& facs) {
        long long result = 0;
        while (!facs.empty()) {
            int digit = facs.top();
            facs.pop();
            result = result*10 + digit;
            
            if (result > INT_MAX || result < INT_MIN) return 0;
        }
        return result;
    }
};
