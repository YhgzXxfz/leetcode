class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 1
        /*
        vector<unordered_set<int>> graph (numCourses);
        for (auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        
        vector<int> indegrees(numCourses);
        for (auto node : graph) {
            for (auto neighbor : node) {
                ++indegrees[neighbor];
            }
        }
        
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; ++j) {
                if (indegrees[j] == 0) break;
            }
            if (j == numCourses) return false;
            
            indegrees[j] = -1;
            for (auto neighbor : graph[j]) {
                --indegrees[neighbor];
            }
        }
        
        return true;
        */
        
        // 2
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        
        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && dfs(graph, onpath, i, visited)) return false;
        }
        return true;
    }
    
    bool dfs(vector<unordered_set<int>>& graph, vector<bool>& onpath, int b, vector<bool>& visited) {
        if (visited[b]) return false;
        onpath[b] = visited[b] = true;
        for (auto neighbor : graph[b]) {
            // has cycle
            if (onpath[neighbor] || dfs(graph, onpath, neighbor, visited)) return true;
        }
        onpath[b] = false;
        return false;
    }
};
