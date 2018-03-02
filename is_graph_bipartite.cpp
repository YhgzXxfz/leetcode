class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<int> colors(len, -1);
        
        for (int i = 0; i < len; ++i) {
            if (colors[i] == -1 && !isValid(graph, colors, 0, i)) return false;
        }
        return true;
    }
    
private:
    bool isValid(vector<vector<int>>& graph, vector<int>& colors, int color, int node) {
        if (colors[node] != -1) return colors[node] == color;
        
        colors[node] = color;
        for (auto next : graph[node]) {
            if (!isValid(graph, colors, 1-color, next)) return false;
        }
        return true;
    }
};
