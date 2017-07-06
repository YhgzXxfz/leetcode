class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m*n != r*c) return nums;
        
        vector<vector<int>> output(r, vector<int>(c, 0));
        for (int k = 0; k < m*n; ++k) {
            output[k/c][k%c] = nums[k/n][k%n];
        }
        return output;
    }
};
