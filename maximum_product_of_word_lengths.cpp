class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        if (len == 0) return 0;
        
        size_t result = 0;
        vector<int> bitword(len, 0);
        
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                bitword[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        
        for (int i = 0; i < len-1; ++i) {
            for (int j = i+1; j < len; ++j) {
                if ((bitword[i] & bitword[j]) == 0) result = max(result, words[i].size() * words[j].size());
            }
        }
        return result;
    }
};
