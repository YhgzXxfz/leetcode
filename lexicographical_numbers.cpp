class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int i = 1, j, k;
        for (;;) {
            for (k = 0; i*pow(10, k) <= n; ++k) {
                result.emplace_back(i*pow(10, k));
            }
            
            for (j = result.back()+1; j <=n && (j%10) != 0; ++j) {
                result.emplace_back(j);
            }
            
            if (j%10 == 0) j--;
            else j /= 10;
            
            while (j%10 == 9) j /= 10;
            i = j+1;
            
            if (result.size() >= n) break;
        }
        return result;
    }
};
