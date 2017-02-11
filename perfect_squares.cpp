// 1 dp
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j*j <= i; ++j) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
 
// 2 math return 4 if and only if n = 4^k * (8m+7)
class Solution {
public:
    int numSquare(int n) {
	if (isSquare(n)) return 1;
        
        while ((n&3) == 0) {
            n >>= 2;
        }
        
        if ((n&7) == 7) return 4;
        
        int root = sqrt(n);
        for (int i = 1; i <= root; ++i) {
            if (isSquare(n-i*i)) return 2;
        }
        return 3;
        
        
    }
    
private:
    bool isSquare(int n) {
        int root = sqrt(n);
        return root*root == n;
    }
};
