class Solution:
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1: return 0
        
        dp = (n+1)*[None]
        for i in range(1, n+1):
            dp[i] = i
            for j in range(2,i):
                if i%j == 0:
                    dp[i] = min(dp[i], dp[j] + 1 + (i/j-1))
                    
        return int(dp[n])
        
