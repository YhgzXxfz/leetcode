class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        
        vector<int> primes(n, 1);
        primes[0] = primes[1] = 0;
        for (int i = 0; i*i < n; ++i) {
            if (primes[i]) {
                for (int j = i*i; j < n; j += i) {
                    primes[j] = 0;
                }
            }
        }
        return count(primes.begin(), primes.end(), 1);
    }
};
