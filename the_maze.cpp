// bfs
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start == destination) return true;
        
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}}, visited(m, vector<int>(n,0));
        visited[start[0]][start[1]] = 1;
        queue<pair<int,int>> q;
        q.push(make_pair(start[0], start[1]));
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            for (auto dir : dirs) {
                int x = curr.first, y = curr.second;
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += dir[0]; y += dir[1];
                }
                x -= dir[0]; y -= dir[1];
                
                if (visited[x][y]) continue;
                visited[x][y] = true;
                
                if (destination[0] == x && destination[1] == y) return true;
                q.push(make_pair(x,y));
            } 
        }
        return false;
    }
};


// dfs
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start == destination) return true;
        
        set<vector<int>> st;
        return dfs(maze, start, destination, st);
    }

private:
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest, set<vector<int>>& st) {
        if (start == dest) return true;
        if (st.count(start)) return false;
        
        st.insert(start);
        for (auto dir : dirs) {
            auto pos = goToEnd(maze, start, dir);
            if (pos == dest || dfs(maze, pos, dest, st)) return true;
        }
        return false;
    }
    
    vector<int> goToEnd(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir) {
        int x = start[0], y = start[1], i = dir[0], j = dir[1];
        int m = maze.size(), n = maze[0].size();
        x += i; y += j;
        if (x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == 1) return start;
        
        vector<int> pos = {x, y};
        return goToEnd(maze, pos, dir);
    }
    
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
};
