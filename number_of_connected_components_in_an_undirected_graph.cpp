// union-find
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n);
        for (int i = 0; i < n; ++i) {
            roots[i] = i;
        }
        
        for (auto& edge : edges) {
            int x = find(roots, edge.first);
            int y = find(roots, edge.second);
            if (x != y) {
                roots[x] = y;
                n--;
            }
        }
        return n;
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

// dfs
class NumberOfConnectedComponentsInAnUndirectedGraph {
public:
	int countComponents(int n, vector<pair<int, int>>& edges) {
		unordered_map<int, unordered_set<int>> graph;
		for (auto edge : edges) {
			graph[edge.first].insert(edge.second);
			graph[edge.second].insert(edge.first);
		}

		int count = 0;
		vector<int> visited(n, 0);
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(graph, visited, i);
				++count;
			}
		}
		return count;
	}

private:
	void dfs(unordered_map<int, unordered_set<int>>& graph, vector<int>& visited, int curr) {
		if (visited[curr]) return ;

		visited[curr] = true;
		for (auto neighbor : graph[curr]) {
			dfs(graph, visited, neighbor);
		}
	}
};


// bfs
class NumberOfConnectedComponentsInAnUndirectedGraph {
public:
	int countComponents(int n, vector<pair<int, int>>& edges) {
		unordered_map<int, unordered_set<int>> graph;
		for (auto edge : edges) {
			graph[edge.first].insert(edge.second);
			graph[edge.second].insert(edge.first);
		}

		int count = 0;
		vector<int> visited(n,0);
		for (int i = 0; i < n; ++i) {
			if (visited[i]) continue;

			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				auto curr = q.front();
				q.pop();
				visited[curr] = true;
				for (auto neighbor : graph[curr]) {
					if (!visited[neighbor]) q.push(neighbor);
				}
			}
			++count;
		}
		return count;
	}
};
