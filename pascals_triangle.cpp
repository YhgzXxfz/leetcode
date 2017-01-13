class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; ++i) {
            int len = i+1;
            result[i].resize(len);
            result[i][0] = result[i][len-1] = 1;
            if (i == 0) continue;
            
            for (int j = 1; j < (len+1)/2; ++j) {
                result[i][j] = result[i][len-1-j] = result[i-1][j-1]+result[i-1][j];
            }
        }
        return result;
    }
};
