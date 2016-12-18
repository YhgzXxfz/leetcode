class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        int row = m-1, column = 0;
        while (row >= 0 && column < n) {
            if (target == matrix[row][column]) return true;
            else if (target > matrix[row][column]) ++column;
            else --row;
        }
        return false;
    }
};
