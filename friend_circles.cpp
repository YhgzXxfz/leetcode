// bfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size(), count = 0;
        vector<int> visited(m, 0);
        queue<int> q;
        for (int i = 0; i < m; ++i) {
            if (visited[i]) continue;
            
	    q.push(i);
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                visited[curr] = 1;
                for (int j = 0; j < m; ++j) {
                    if (matrix[curr][j] && visited[j] == 0) {
                        q.push(j);
                    }
                }
            }
            ++count;
        }
        return count;
    }
};
