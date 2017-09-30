// union-find
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, 0);
        for (int i = 0; i < n; ++i) roots[i] = i;
        
        for (auto edge : edges) {
            int x = find(roots, edge.first);
            int y = find(roots, edge.second);
            if (x == y) return false;
            
            roots[x] = y;
        }
        return edges.size() >= n-1;
    }
    
private:
    int find(vector<int>& roots, int id) {
        while (roots[id] != id) {
            roots[id] = roots[roots[id]];
            id = roots[id];
        }
        return id;
    }
};


// bfs
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (const auto& edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0); visited[0] = 1;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            for (auto neighbor : graph[curr]) {
                if (visited[neighbor] == 1) return false; 
                else if (visited[neighbor] == 0) { 
                    q.push(neighbor);
                    visited[neighbor] = 1; 
                }
            }
            visited[curr] = 2;
        }
        if (count(visited.begin(), visited.end(), 0)) return false;
        return true;
    }
};


// dfs
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, unordered_set<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        
        vector<int> visited(n, 0);
        visited[0] = 1;
        
        if (hasCycle(graph, visited, 0, -1)) return false;
        if (accumulate(visited.begin(), visited.end(), 0) < n) return false;
        return true;
    }

private:
    bool hasCycle(unordered_map<int, unordered_set<int>>& graph, vector<int>& visited, int src, int prev) {
        for (auto neighbor : graph[src]) {
            if (neighbor != prev) {
                if (visited[neighbor]) return true;
                
                visited[neighbor] = 1;
                if (hasCycle(graph, visited, neighbor, src)) return true;
            }
        }
        return false;
    }
};
