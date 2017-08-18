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
