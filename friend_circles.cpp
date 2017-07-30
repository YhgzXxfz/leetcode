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


// dfs

class Solution {
public:
    int findCircleNum(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int len = matrix.size(), count = 0;
        vector<int> visited(len, 0);
        for (int i = 0; i < len; ++i) {
            if (visited[i]) continue;
            
            dfs(matrix, visited, i);
            count++;
        }
        return count;
    }

private:
    void dfs(vector<vector<int>>& matrix, vector<int>& visited, int curr) {
        for (int i = 0; i < visited.size(); ++i) {
            if (visited[i]) continue;
            
            if (matrix[curr][i]) {
                visited[curr] = true;
                dfs(matrix, visited, i);
            }
        }
    }
};
