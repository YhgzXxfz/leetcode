// topological sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        
        vector<int> result;
        
        queue<int> zero_degrees;
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) zero_degrees.push(i);
        }
        
        for (int i = 0 ; i < numCourses; ++i) {
            if (zero_degrees.empty()) return {};
            int node = zero_degrees.front();
            zero_degrees.pop();
            result.emplace_back(node);
            
            for (auto neighbor : graph[node]) {
                --indegrees[neighbor];
                if (indegrees[neighbor] == 0) zero_degrees.push(neighbor);
            }
        }
        return result;
    }
};
  
// 2 check if a cycle exists      
class Solution {       
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<unordered_set<int>> graph (numCourses);
        for (auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        
        vector<int> result;
        vector<int> onpath(numCourses, 0), visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfs(graph, i, onpath, visited, result)) return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    bool dfs(vector<unordered_set<int>>& graph, int node, vector<int>& onpath, vector<int>& visited, vector<int>& result) { 
        if (visited[node]) return false;
        onpath[node] = visited[node] = 1; 
        for (int neighbor : graph[node]) {
            if (onpath[neighbor] || dfs(graph, neighbor, onpath, visited, result)) return true;
        }
        result.push_back(node);
        onpath[node] = 0;
	return false;
    }
};
