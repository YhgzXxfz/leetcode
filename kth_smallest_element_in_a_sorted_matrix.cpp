class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 1 Priority Queue, O(N^2)
        /*
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<int, vector<int>> pq;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        return pq.top();
        */
        
        // Binary Search, O(log(N^2))
        int m = matrix.size();
        int left = matrix[0][0], right = matrix[m-1][m-1];
        while (left < right) {
            int mid = left + (right-left)/2;
            int num = 0;
            for (int i = 0; i < m; ++i) {
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }
            
            if (num < k) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
