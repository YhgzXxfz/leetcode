class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // reverse up-down, then swap symmetry
	if (matrix.empty()) return ;

	int m = matrix.size(), n = matrix[0].size();
	reverse(matrix.begin(), matrix.end());
	for (int i = 0; i < m; ++i) {
		for (int j = i+1; j < n; ++j) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	// rotate
	/*
	int n = matrix.size();
        if (n <= 1) return;
        
        int top = 0, left = 0, bottom = n-1, right = n-1;
        while (top <= bottom && left <= right) {
            for (int i = left; i < right; ++i) {
                int biase = i - top;
                int val = matrix[top][i];
                matrix[top][i] = matrix[bottom-biase][left];
                matrix[bottom-biase][left] = matrix[bottom][right-biase];
                matrix[bottom][right-biase] = matrix[top+biase][right];
                matrix[top+biase][right] = val;
            }
            
            ++top;
            ++left;
            --bottom;
            --right;
        }
	*/
    }
};
