class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = primes.size();
        vector<int> index(len, 0), ugly(n, INT_MAX);
        ugly[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < len; j++) ugly[i] = min(ugly[i], ugly[index[j]]*primes[j]);
            for(int j = 0; j < len; j++) index[j] += (ugly[i] == ugly[index[j]]*primes[j]);
        }
        return ugly[n-1];
    }
};
