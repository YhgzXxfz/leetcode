// O(R-L), O(1)
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int result = 0;
        vector<int> primes = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
        for (int i = L; i <= R; ++i) {
            bitset<32> bits(i);
            if (primes[bits.count()]) ++result;
        }
        return result;
    }
};



// O(R-L), O(1)
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int result = 0;
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (int i = L; i <= R; ++i) {
            int bits = 0, x = i;
            while (x) {
                x &= (x-1);
                ++bits;
            }
            if (primes.count(bits)) ++result;
        }
        return result;
    }
};
