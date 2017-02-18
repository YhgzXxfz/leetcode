class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int len = org.size();
        if (len <= 0) return true;
        
        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int, int> outdegrees;
        
        // construct graph
        for (const auto& seq : seqs) {
            if (seq.empty()) continue;
            if (seq.size() == 1) outdegrees[seq[0]] = 0; // seq.size() == 1 will not be in graph, update outdegrees manually
            
            for (int i = 0; i < seq.size()-1; ++i) {
                graph[seq[i+1]].insert(seq[i]);
            }
        }
        
        // update outdegrees
        for (auto entry : graph) {
            for (auto neighbor : entry.second) {
                ++outdegrees[neighbor];
            }
        }
        for (auto entry : graph) { // zero out degree node will not be in entry.second of graph, update manually
            if (outdegrees.find(entry.first) == outdegrees.end()) outdegrees[entry.first] = 0;
        }
        
        // bfs
        queue<int> zero_degrees;
        for (auto entry : outdegrees) {
            if (entry.second == 0) zero_degrees.push(entry.first);
        }
        
        int count = len-1;
        while (!zero_degrees.empty()) {
            if (zero_degrees.size() > 1) return false;
            
            int curr = zero_degrees.front();
            zero_degrees.pop();
            if (count < 0 || curr != org[count--]) return false;
            
            for (auto neighbor : graph[curr]) {
                --outdegrees[neighbor];
                if (outdegrees[neighbor] == 0) zero_degrees.push(neighbor);
            }
        }
        return count == -1 && outdegrees.size() == org.size();
    }
};
