class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1);
        if (num < 0) return result;
        
        result[0] = 0;
        for (int i = 1; i <= num; ++i) {
            result[i] = result[i/2] + (i&1);
        }
        return result;
    }
};
