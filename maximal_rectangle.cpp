class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n+1, 0);
        int area = 0;
        
        for (int i = 0; i < m; ++i) {
            stack<int> s;
            for (int j = 0; j <= n; ++j) {
                if (j < n) heights[j] = matrix[i][j] == '1' ? 1+heights[j] : 0;
                    
                if (s.empty() || heights[j] >= heights[s.top()]) s.push(j);
                else {
                    while(!s.empty() && heights[j] < heights[s.top()]){
                        int tp = s.top();
                        s.pop();
                        area = max(area, heights[tp] * (s.empty() ? j : (j-s.top()-1)));
                    }
                    s.push(j);
                }
            }
        }
        return area;
    }
};
// dp
/*
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> left(n,0), right(n,n), height(n,0);
        int max_area = 0;
        for (int i = 0; i < m; i++) {
            int curr_left = 0, curr_right = n; 
            for (int j = 0; j < n; j++) { // compute height (can do this from either side)
                if (matrix[i][j] == '1') height[j]++; 
                else height[j] = 0;
            }
            for (int j = 0; j < n; j++) { // compute left (from left to right)
                if (matrix[i][j] == '1') left[j] = max(left[j],curr_left);
                else {
                    left[j] = 0; 
                    curr_left = j+1;
                }
            }
            // compute right (from right to left)
            for (int j = n-1; j >= 0; j--) {
                if (matrix[i][j] == '1') right[j] = min(right[j],curr_right);
                else {
                    right[j] = n; 
                    curr_right = j;
                }    
            }
            // compute the area of rectangle (can do this from either side)
            for (int j = 0; j < n; j++)
                max_area = max(max_area, (right[j]-left[j])*height[j]);
        }
        return max_area;
    }
};
*/
