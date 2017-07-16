class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i < ppid.size(); ++i) {
            mp[ppid[i]].insert(pid[i]);
        }

        queue<int> q;
        q.push(kill);
        vector<int> result;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            
            for (auto child : mp[curr]) q.push(child);
        }
        return result;
    }
};
