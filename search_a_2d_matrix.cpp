class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
	if (n == 0) return false;
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        
        int left = 0, right = m*n-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            int row = mid/n, col = mid%n;
            if (target == matrix[row][col]) return true;
            else if (target > matrix[row][col]) left = mid+1;
            else right = mid-1;
        }
        return false;
    }
};
