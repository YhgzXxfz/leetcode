class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        // 1 topological sort
        /*
        if (seqs.size() == 0) return false;
        int n = org.size(), count = 0;
        unordered_map<int, unordered_set<int>> graph;   // record parents
        vector<int> degree(n+1, 0); // record out degree
        for (auto s : seqs) {   // build graph
            for (int i = s.size()-1; i >= 0; --i) {
                if (s[i] > n || s[i] < 0) return false; // in case number in seqs is out of range 1-n
                if (i > 0 && !graph[s[i]].count(s[i-1])) {
                    graph[s[i]].insert(s[i-1]);
                    if (degree[s[i-1]]++ == 0) count ++;
                }
            }
        }
        if (count != n-1) return false; // all nodes should have degree larger than 0 except the last one
        for (int i = n-1; i >= 0; --i) {    // topological sort
            if (degree[org[i]] > 0) return false;   // the last node should have 0 degree
            for (auto p : graph[org[i]]) 
                if (--degree[p] == 0 && p != org[i-1]) // found a node that is not supposed to have 0 degree
                    return false;
        }
        return true;
        */
        
        // 2 check if every two adjacent numbers of org also appear adjacently in any subsequences of seqs
        if (seqs.empty()) return false;
        vector<int> pos(org.size()+1);
        for (int i = 0;i < org.size(); ++i) pos[org[i]] = i;
        
        vector<char> visited(org.size()+1, 0); // int consumes more memory, while bool vectors takes more time to access
        int toMatch = org.size()-1;
        for (const auto& seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] <= 0 || seq[i] > org.size()) return false;
                if (i == 0) continue;
                
                int lead = seq[i-1], following = seq[i];
                if (pos[lead] >= pos[following]) return false;
                if (visited[lead] == 0 && pos[lead]+1 == pos[following]) {
                    visited[lead] = 1;
                    --toMatch;
                }
            }
        }
        return toMatch == 0;
    }
};
